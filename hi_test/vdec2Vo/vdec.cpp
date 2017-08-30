#include "vdec.h"

vdec::vdec(QObject *parent) :
    QObject(parent)
{
    m_vdecThread = new VdecThread();
    connect(this,SIGNAL(signalVideoPlay(QString,bool)),m_vdecThread,SLOT(slotVideoPlay(QString,bool)));
    connect(this,SIGNAL(signalPause()),m_vdecThread,SLOT(slotPause()));//暂停
    connect(this,SIGNAL(signalResume()),m_vdecThread,SLOT(slotResume()));
    connect(this,SIGNAL(signalFastPlay()),m_vdecThread,SLOT(slotFastPlay()));//快放
    connect(this,SIGNAL(signalSlowPlay()),m_vdecThread,SLOT(slotSlowPlay()));//慢放
    connect(this,SIGNAL(signalRealPlay()),m_vdecThread,SLOT(slotRealPlay()));//恢复正常播放
    connect(this,SIGNAL(signalDelay10(int,bool)),m_vdecThread,SLOT(slotDelay10(int,bool)));//后退10S
    connect(this,SIGNAL(signalDelay2(int,bool)),m_vdecThread,SLOT(slotDelay2(int,bool)));//后退2S
    connect(this,SIGNAL(signalFF10(int,bool,bool)),m_vdecThread,SLOT(slotFF10(int,bool,bool)));//快进10S
    connect(this,SIGNAL(signalFF2(int,bool,bool)),m_vdecThread,SLOT(slotFF2(int,bool,bool)));//快进2S
    connect(this,SIGNAL(signalSliderReleased(int,bool)),m_vdecThread,SLOT(slotSliderReleased(int,bool)));
    VdecBindVpss();
    VpssBindVo();
}
vdec::~vdec()
{

}
/********************************************
 * function: VdecBindVpss()
 * 类别：类成员函数
 * 参数：void
 * 返回值：void
 * 功能：vdec绑定vpss
 * *******************************************/
void vdec::VdecBindVpss()
{
    HI_S32 s32Ret;
    s32Ret = SAMLE_COMM_VDEC_BindVpss(0, 1);
    if (HI_SUCCESS !=s32Ret)
    {
        SAMPLE_PRT("vdec bind vpss failed!\n");
    }
}

/********************************************
 * function: VpssBindVo()
 * 类别：类成员函数
 * 参数：void
 * 返回值：void
 * 功能：Vpss绑定Vo 并启动解码线程
 * *******************************************/
void vdec::VpssBindVo()
{
    SIZE_S stSize;
    HI_S32 s32Ret = HI_SUCCESS;

    s32Ret = SAMPLE_COMM_VO_BindVpss(0,0,1,VPSS_PRE0_CHN);//VPSS_BSTR_CHN: 定义大码流通道的ID号
    if (HI_SUCCESS != s32Ret)
    {
        SAMPLE_PRT("SAMPLE_COMM_VO_BindVpss failed!\n");
    }
    s32Ret = SAMPLE_COMM_SYS_GetPicSize(VIDEO_ENCODING_MODE_PAL, PIC_HD1080, &stSize);
    if (HI_SUCCESS !=s32Ret)
    {
        SAMPLE_PRT("get picture size failed!\n");
    }
    printf("stsize: %d %d\n",stSize.u32Width,stSize.u32Height);
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

    HI_MPI_VO_ChnShow(0,0);
    HI_MPI_VO_ChnResume(0,0);
    VdecThread::gs_sendParam->bRun = HI_TRUE;
    VdecThread::gs_sendParam->enPayload = PT_H264;
    VdecThread::gs_sendParam->enVideoMode = VIDEO_MODE_FRAME;
    VdecThread::gs_sendParam->s32MinBufSize = stSize.u32Height * stSize.u32Width / 2;
    VdecThread::gs_sendParam->VdChn = 0;
    m_vdecThread->start();
}


void vdec::slotVideoPlay(QString filepath,bool status)
{
    m_playStatus = status;
    emit signalVideoPlay(filepath,status);
}

/********************************************
 * function: slotPause()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：发送暂停信号到解码控制线程
 * *******************************************/
void vdec::slotPause()
{
    emit signalPause();
}

/********************************************
 * function: slotResume()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：发送恢复播放信号到解码控制线程
 * *******************************************/
void vdec::slotResume()
{
    emit signalResume();
}

/********************************************
 * function: slotFastPlay()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：发送快放信号到解码控制线程
 * *******************************************/
void vdec::slotFastPlay()
{
    emit signalFastPlay();
}

/********************************************
 * function: slotSlowPlay()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：发送慢放信号到解码控制线程
 * *******************************************/
void vdec::slotSlowPlay()
{
    emit signalSlowPlay();
}

/********************************************
 * function: slotRealPlay()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：发送恢复正常播放信号到解码控制线程
 * *******************************************/
void vdec::slotRealPlay()
{
    emit signalRealPlay();
}

/********************************************
 * function: slotDelay10(int value)
 * 类别：槽函数
 * 参数：value:当前播放位置
 * 返回值：void
 * 功能：发送后退10S信号到解码控制线程
 * *******************************************/
void vdec::slotDelay10(int value)
{
    emit signalDelay10(value,m_playStatus);
}
/********************************************
 * function: slotDelay2(int value)
 * 类别：槽函数
 * 参数：value:当前播放位置
 * 返回值：void
 * 功能：发送后退2S信号到解码控制线程
 * *******************************************/
void vdec::slotDelay2(int value)
{
    emit signalDelay2(value,m_playStatus);
}

/********************************************
 * function: slotFF10(int value,bool realPlay)
 * 类别：槽函数
 * 参数：value:当前播放位置 realPlay:是否实时播放
 * 返回值：void
 * 功能：发送快进10S信号到解码控制线程
 * *******************************************/
void vdec::slotFF10(int value,bool realPlay)
{
    emit signalFF10(value,realPlay,m_playStatus);
}

/********************************************
 * function: slotFF2(int value, bool realPlay)
 * 类别：槽函数
 * 参数：value:当前播放位置 realPlay:是否实时播放
 * 返回值：void
 * 功能：发送快进2S信号到解码控制线程
 * *******************************************/
void vdec::slotFF2(int value, bool realPlay)
{
    emit signalFF2(value,realPlay,m_playStatus);
}

void vdec::slotSliderReleased(int value)
{
    emit signalSliderReleased(value,m_playStatus);
}
