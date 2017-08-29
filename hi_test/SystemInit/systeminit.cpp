#include "systeminit.h"
#include "hifb.h"

SystemInit::SystemInit(QObject *parent) :
    QObject(parent)
{
    gs_enNorm = VIDEO_ENCODING_MODE_PAL;
    u32ViChnCnt = 1;
    enViMode = SAMPLE_VI_MODE_4_1080P;//采集4*1080P
    Mpp_ModuleInit();
    Vi_ModuleInit();
    Venc_ModuleInit();
    Vpss_ModuleInit();
    //Vdec_ModuleInit();
    Vo_ModuleInit();
    //ViBindVo();
    //Venc m_venc;
    //vdec m_vdec;
}

SystemInit::~SystemInit()
{

}

void SystemInit::slotVideoPlayStart()
{
    Vdec_ModuleInit();
}
HI_VOID SystemInit::ViBindVo()
{
    HI_S32 s32Ret;
    MPP_CHN_S stBindSrc;
    MPP_CHN_S stBindDest;
    stBindDest.enModId = HI_ID_VOU;
    stBindDest.s32ChnId = 0;
    stBindDest.s32DevId = 0;

    stBindSrc.enModId = HI_ID_VIU;
    stBindSrc.s32ChnId = 0;
    stBindSrc.s32DevId = 0;
    s32Ret = HI_MPI_SYS_Bind(&stBindSrc, &stBindDest);
}

/***********************************************
 * 系统Mpp模块初始化
 * *********************************************/
HI_S32 SystemInit::Mpp_ModuleInit()
{
    memset(&stVbConf,0,sizeof(VB_CONF_S));
    u32BlkSize = SAMPLE_COMM_SYS_CalcPicVbBlkSize(gs_enNorm,PIC_HD1080,\
                                                  SAMPLE_PIXEL_FORMAT,SAMPLE_SYS_ALIGN_WIDTH);
    stVbConf.u32MaxPoolCnt = 128;

    /*  ddro video buffer   */
    stVbConf.astCommPool[0].u32BlkSize = u32BlkSize;
    stVbConf.astCommPool[0].u32BlkCnt = u32ViChnCnt *8;
    memset(stVbConf.astCommPool[0].acMmzName,\
            0,sizeof(stVbConf.astCommPool[0].acMmzName));

//    /*ddr0 hist buffer  */
//    stVbConf.astCommPool[4].u32BlkSize = u32BlkSize;
//    stVbConf.astCommPool[4].u32BlkCnt = u32ViChnCnt * 16;
//    memset(stVbConf.astCommPool[4].acMmzName,\
//            0,sizeof(stVbConf.astCommPool[4].acMmzName));

//    /*  ddr1 video buffer   */
//    stVbConf.astCommPool[2].u32BlkSize = u32BlkSize;
//    stVbConf.astCommPool[2].u32BlkCnt = u32ViChnCnt * 16;
//    strcpy(stVbConf.astCommPool[2].acMmzName,"ddr1");

////    /*  ddr1 hist buffer    */
//    stVbConf.astCommPool[3].u32BlkSize = u32BlkSize;
//    stVbConf.astCommPool[3].u32BlkCnt = u32ViChnCnt * 16;
//    strcpy(stVbConf.astCommPool[3].acMmzName,"ddr1");

    /***********************************************
     * step 1: mpp init
     * *********************************************/
    s32Ret = SAMPLE_COMM_SYS_Init(&stVbConf);
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_SYS_Init failed with %d\n",s32Ret);
        return NULL;
    }
    return HI_SUCCESS;
}

/*******************************************
 * 系统输入模块（VI）初始化
 * *****************************************/
HI_S32 SystemInit::Vi_ModuleInit()
{
    s32Ret = SAMPLE_COMM_VI_MemConfig(enViMode);
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VI_MemConfig failed with %d!\n",s32Ret);
        return NULL;
    }

    s32Ret = SAMPLE_COMM_VI_Start(enViMode,gs_enNorm);
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VI_Start failed with ");
        return NULL;
    }
    return HI_SUCCESS;
}

/************************************************
 * 视频编码模块（VENC）初始化
 * **********************************************/
HI_S32 SystemInit::Venc_ModuleInit()
{
    s32Ret = SAMPLE_COMM_VENC_MemConfig();
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VENC_MemConfig failed with %d\n",s32Ret);
        return NULL;
    }
    //开启VENC通道
    s32Ret = SAMPLE_COMM_VENC_Start(0, 0, PT_H264,\
                                    gs_enNorm, PIC_HD1080, SAMPLE_RC_CBR);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("Start Venc failed!\n");
    }

    return HI_SUCCESS;
}

/*****************************************
 * 视频处理子系统（VPSS）初始化
 * ***************************************/
HI_S32 SystemInit::Vpss_ModuleInit()
{
    s32Ret = SAMPLE_COMM_VPSS_MemConfig();
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VPSS_MemConfig failed!\n");
        return NULL;
    }
    //获取图像尺寸
    s32Ret = SAMPLE_COMM_SYS_GetPicSize(gs_enNorm, PIC_HD1080, &stSize);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_SYS_GetPicSize failed!\n");
    }
    if (704 == stSize.u32Width)
    {
        stSize.u32Width = 720;
    }
    else if (352 == stSize.u32Width)
    {
        stSize.u32Width = 360;
    }
    else if (176 == stSize.u32Width)
    {
        stSize.u32Width = 180;
    }
    s32Ret = SAMPLE_COMM_VPSS_Start(2, &stSize, VPSS_MAX_CHN_NUM,NULL);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("Start Vpss failed!\n");
    }
    return HI_SUCCESS;
}

//解码模块（VDEC）初始化
HI_S32 SystemInit::Vdec_ModuleInit()
{
    s32Ret = SAMPLE_COMM_VDEC_MemConfig();
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VPSS_MemConfig failed with %d!\n", s32Ret);
    }
    s32Ret = SAMPLE_COMM_SYS_GetPicSize(gs_enNorm, PIC_HD1080, &stSize);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_SYS_GetPicSize failed!\n");
    }
    if (704 == stSize.u32Width)
    {
        stSize.u32Width = 720;
    }
    else if (352 == stSize.u32Width)
    {
        stSize.u32Width = 360;
    }
    else if (176 == stSize.u32Width)
    {
        stSize.u32Width = 180;
    }
    s32Ret = SAMPLE_Vdec_CreateVdecChn(0, &stSize, PT_H264, VIDEO_MODE_STREAM);
    if (HI_SUCCESS !=s32Ret)
    {
        SAMPLE_PRT("create vdec chn failed!\n");
    }
    VDEC_CHN_PARAM_S pstParam;
    pstParam.s32ChanErrThr = 10;
    pstParam.s32ChanStrmOFThr = 0;
    pstParam.s32DecMode = 1;
    pstParam.s32DecOrderOutput = 1;//输出顺序：0:显示序  1:解码序

    s32Ret = HI_MPI_VDEC_SetChnParam(0,&pstParam);
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("HI_MPI_VDEC_SetChnParam failed with %x\n",s32Ret);
    }
}
HI_S32 SystemInit::SAMPLE_Vdec_CreateVdecChn(HI_S32 s32ChnId,SIZE_S *pstSize,PAYLOAD_TYPE_E enType,VIDEO_MODE_E enVdecMode)
{
    VDEC_CHN_ATTR_S stAttr;
    VDEC_PRTCL_PARAM_S stPrtclParam;
    HI_S32 s32Ret;

    memset(&stAttr,0,sizeof(VDEC_CHN_ATTR_S));

    stAttr.enType = enType;
    stAttr.u32BufSize = pstSize->u32Height * pstSize->u32Width;
    stAttr.u32Priority = 1;
    stAttr.u32PicHeight = pstSize->u32Height;
    stAttr.u32PicWidth = pstSize->u32Width;

    switch(enType)
    {
        case PT_H264:
        stAttr.stVdecVideoAttr.u32RefFrameNum = 1;
        stAttr.stVdecVideoAttr.enMode = enVdecMode;
        stAttr.stVdecVideoAttr.s32SupportBFrame = 1;
        break;
    case PT_JPEG:
        stAttr.stVdecJpegAttr.enMode = enVdecMode;
        break;
    case PT_MJPEG:
        stAttr.stVdecJpegAttr.enMode = enVdecMode;
        break;
    default:
         SAMPLE_PRT("err type \n");
         return HI_FAILURE;
    }

    s32Ret = HI_MPI_VDEC_CreateChn(s32ChnId,&stAttr);
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("HI_MPI_VDEC_CreateChn failed errno 0x%x \n", s32Ret);
        return s32Ret;
    }
    s32Ret = HI_MPI_VDEC_GetPrtclParam(0, &stPrtclParam);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("HI_MPI_VDEC_GetPrtclParam failed errno 0x%x \n", s32Ret);
        return s32Ret;
    }

    stPrtclParam.s32MaxSpsNum = 21;
    stPrtclParam.s32MaxPpsNum = 22;
    stPrtclParam.s32MaxSliceNum = 100;
    s32Ret = HI_MPI_VDEC_SetPrtclParam(0, &stPrtclParam);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("HI_MPI_VDEC_SetPrtclParam failed errno 0x%x \n", s32Ret);
        return s32Ret;
    }

    s32Ret = HI_MPI_VDEC_StartRecvStream(0);
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("HI_MPI_VDEC_StartRecvStream failed errno 0x%x \n", s32Ret);
        return s32Ret;
    }

    return HI_SUCCESS;
}
HI_S32 SystemInit::Vo_ModuleInit()
{
    SAMPLE_VO_MODE_E enVoMode;
    VO_PUB_ATTR_S stPutAttr;

    enVoMode = VO_MODE_1MUX;

    stPutAttr.enIntfType = VO_INTF_VGA | VO_INTF_HDMI;
    stPutAttr.enIntfSync = VO_OUTPUT_1280x800_60;
    stPutAttr.u32BgColor = 0x00000000;
    stPutAttr.bDoubleFrame = HI_FALSE;

    m_u32ViFrmRate = (VIDEO_ENCODING_MODE_PAL == gs_enNorm)?25:30;

    s32Ret = SAMPLE_COMM_VO_StartDevLayer(0,&stPutAttr,25);
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VO_StartDevLayer failed!\n");
        return NULL;
    }

    s32Ret = SAMPLE_COMM_VO_StartChn(0,&stPutAttr,enVoMode);//开启输出设备输出通道0
    if(HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VO_StartChn failed\n");
        return NULL;
    }
}

HI_S32 SystemInit::HifbInit()
{
    m_u32ViFrmRate = 0;
    m_Vodev = SAMPLE_VO_DEV_DHD0;

    char file[12] = "/dev/fb0";
    int fd = -1;

    fd = open(file,O_RDWR,0);
    if(fd < 0)
    {
        printf("open file failed!\n");
    }

    HI_BOOL bShow;
    struct fb_var_screeninfo var;   //定义可变的屏幕信息结构体
    HIFB_ALPHA_S stAlpha;   //定义Alpha 透明度结构体
    HIFB_POINT_S stPoint = {0,0};   //定义叠加层起始位置

    if(ioctl(fd,FBIOGET_VSCREENINFO,&var) < 0)
    {
        printf("FBIOGET_VSCREENINFO failed\n");
        close(fd);
    }
    //设置叠加层属性
    var.xres_virtual = 1280;
    var.yres_virtual = 720 * 2;
    var.xres = 1280;
    var.yres = 720;
    var.transp = {24,8,0};
    var.red = {16,8,0};
    var.green = {8,8,0};
    var.blue = {0,8,0};
    var.bits_per_pixel = 32;
    var.activate = FB_ACTIVATE_ALL;
    if(ioctl(fd,FBIOPUT_VSCREENINFO,&var) < 0)
    {
        printf("FBIOPUT_VSCREENINFO failed!\n");
        close(fd);
    }

    stPoint.s32XPos = 0;
    stPoint.s32YPos = 0;
    if(ioctl(fd,FBIOPUT_SCREEN_ORIGIN_HIFB,&stPoint) < 0)
    {
        printf("FBIOPUT_SCREEN_ORIGIN_HIFB failed!\n");
        close(fd);
    }

    //设置叠加层透明度
    stAlpha.bAlphaEnable = HI_TRUE; //叠加层使能
    stAlpha.bAlphaChannel = HI_TRUE; //叠加层通道使能
    stAlpha.u8Alpha0 = 0x0;
    stAlpha.u8Alpha1 = 0xff;
    stAlpha.u8GlobalAlpha = 0xff;

    if(ioctl(fd,FBIOPUT_ALPHA_HIFB,&stAlpha) < 0)
    {
        printf(" set alpha failed\n");
        close(fd);
    }
    bShow = HI_TRUE;
    if(ioctl(fd,FBIOPUT_SHOW_HIFB,&bShow) < 0)
    {
        printf("FBIOPUT_SHOW_HIFB failed\n");
        close(fd);
    }
}















