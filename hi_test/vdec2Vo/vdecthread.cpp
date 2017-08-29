#include "vdecthread.h"
#include "chead.h"
#include <QList>
#include <QStringList>
#define _FILE_OFFSET_BITS 64
SAMPLE_VDEC_SENDPARAM_S *VdecThread::gs_sendParam = new SAMPLE_VDEC_SENDPARAM_S;
QStringList *VdecThread::m_stringList = new QStringList;
HI_S32 VdecThread::g_Icount = 0;
VdecThread::VdecThread(QObject *parent) :
    QThread(parent)
{
    setUsedBytes(0);
    fp = NULL;
    pu8Buf = NULL;
    run_flag = HI_TRUE;
    fast_flag = HI_FALSE;
    m_ICount = 0;
//    m_saveFile = new QFile();

    m_readlock = new QReadWriteLock;
}

VdecThread::~VdecThread()
{

}

void VdecThread::setUsedBytes(const HI_S64 &usedbytes)
{
    s32UsedBytes = usedbytes;
}

const HI_S64 &VdecThread::getUsedBytes()const
{
    return s32UsedBytes;
}

void VdecThread::setFilePath(const QString &filepath)
{
    m_filePath.clear();
    m_filePath = filepath;
}

const QString VdecThread::getFilePath() const
{
    return m_filePath;
}

void VdecThread::setPts(const HI_U64 &pts)
{
    m_pts = 0;
    m_pts = pts;
}
const HI_U64 &VdecThread::getPts()const
{
    return m_pts;
}

void VdecThread::setSleepTime(const HI_U64 &sleeptime)
{
    m_sleepTime = 0;
    m_sleepTime = sleeptime;
}
const HI_U64 &VdecThread::getSleepTime()const
{
    return m_sleepTime;
}

void VdecThread::slotVideoPlay(QString filepath,bool status)
{
    play_status = status;
    //filepath= filepath.replace(QString("\n"),QString(""));
//    printf("vdec:%s\n",filepath.toLocal8Bit().data());
   QString savepath = filepath;
    m_saveFile = new QFile(savepath.left(savepath.size() -6));
    if(!m_saveFile->open(QIODevice::ReadWrite))
    {
        printf("open save file error\n");
    }
    m_ICountList = QString(m_saveFile->readAll()).split("|");
    g_Icount = m_ICountList.size();
    if(status == 0)//实时
    {
        setPts(40000);
        setSleepTime(20000);
        HI_MPI_VO_SetChnFrameRate(0,0,30);
        setFilePath(filepath);
    }else{                      //录像文件播放

//        printf("file size: %d\n",VdecThread::m_stringList->at(10).toInt());
        setPts(40000);
        setSleepTime(20000);
        filepath = filepath.left(filepath.length() - 1);
        setFilePath(filepath);

    }
}

/********************************************
 * function: slotFastPlay()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：快放 50帧/S
 * ******************************************/
void VdecThread::slotFastPlay()
{
    HI_S32 s32Ret;
    fast_flag = HI_TRUE;
    s32Ret = HI_MPI_VDEC_StopRecvStream(0);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VDEC_StopRecvStream failed\n");
    }
    s32Ret = HI_MPI_VO_EnableChn(0,0);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VO_EnableChn failed\n");
    }
    s32Ret = HI_MPI_VO_SetChnFrameRate(0,0,50);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VO_SetChnFrameRate failed\n");
    }
    //setPts(20000);
    setSleepTime(0);
    s32Ret = HI_MPI_VDEC_StartRecvStream(0);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VDEC_StartRecvStream failed\n");
    }
    printf("fast\n");
}

/********************************************
 * function: slotSlowPlay()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：慢放 13帧/S
 * ******************************************/
void VdecThread::slotSlowPlay()
{
    HI_S32 s32Ret;
    s32Ret = HI_MPI_VDEC_StopRecvStream(0);//解码器停止接收码流
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VDEC_StopRecvStream failed\n");
    }
    s32Ret = HI_MPI_VO_SetChnFrameRate(0,0,5);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VO_SetChnFrameRate failed\n");
    }
    //setPts(40000);
    //setSleepTime(10000);
    s32Ret = HI_MPI_VDEC_StartRecvStream(0);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VDEC_StartRecvStream failed\n");
    }
    printf("slow\n");
}

/********************************************
 * function: slotFastPlay()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：恢复正常播放25/S
 * ******************************************/
void VdecThread::slotRealPlay()
{
    HI_S32 s32Ret;
    s32Ret = HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    if(s32Ret != HI_SUCCESS)
    {
        printf("HI_MPI_VO_ClearChnBuffer failed\n");
    }

    s32Ret = HI_MPI_VO_SetChnFrameRate(0,0,25);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VO_SetChnFrameRate failed\n");
    }
//    if(play_status == 0)
//    {
//        setPts(40000);
//        setSleepTime(20000);
//    }else{
//        setPts(40000);
//        setSleepTime(20000);
//    }
}

/********************************************
 * function: slotPause()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：暂停播放 解绑vdec与VPSS
 * ******************************************/
void VdecThread::slotPause()
{
    MPP_CHN_S stSrcChn;
    MPP_CHN_S stDestChn;

    stSrcChn.enModId = HI_ID_VDEC;
    stSrcChn.s32DevId = 0;
    stSrcChn.s32ChnId = 0;

    stDestChn.enModId = HI_ID_VPSS;
    stDestChn.s32DevId = 1;
    stDestChn.s32ChnId = 2;

    HI_MPI_SYS_UnBind(&stSrcChn,&stDestChn);
    HI_MPI_VDEC_StopRecvStream(0);
}

/********************************************
 * function: slotResume()
 * 类别：槽函数
 * 参数：void
 * 返回值：void
 * 功能：恢复播放 重新绑定vdec与vpss
 * ******************************************/
void VdecThread::slotResume()
{
    HI_S32 s32Ret;
    s32Ret = SAMLE_COMM_VDEC_BindVpss(0, 1);
    if (HI_SUCCESS !=s32Ret)
    {
        SAMPLE_PRT("vdec bind vpss failed!\n");
    }
    HI_MPI_VDEC_StartRecvStream(0);
}

/********************************************
 * function: slotDelay10(int value)
 * 类别：槽函数
 * 参数：value 当前播放位置
 * 返回值：void
 * 功能：当前播放位置后退10秒
 * ******************************************/
void VdecThread::slotDelay10(int value, bool playStatus)
{
//    printf("Icount: %d\n",m_ICountList.size());
    HI_U64 set;
    HI_S32 s32Ret;
    if(fast_flag == HI_FALSE)//是否为快放状态 否：恢复25帧/S
    {
        HI_MPI_VO_SetChnFrameRate(0,0,25);
    }

    HI_MPI_VDEC_StopRecvStream(0);
    HI_MPI_VDEC_ResetChn(0);
    //fseeko64(fp, VdecThread::m_stringList->at(10).toLongLong(), SEEK_SET);
    if(playStatus == 0)
    {
        set= VdecThread::m_stringList->at(value -10).toLongLong();
    }else{
        //printf("else\n");
        set = m_ICountList.at(value -10).toLongLong();
        printf("%llu\n",set);
    }

    setUsedBytes(set);

    HI_MPI_VDEC_StartRecvStream(0);
}

/********************************************
 * function: slotDelay2(int value)
 * 类别：槽函数
 * 参数：value 当前播放位置
 * 返回值：void
 * 功能：当前播放位置后退2秒
 * ******************************************/
void VdecThread::slotDelay2(int value, bool playStatus)
{
    HI_U64 set;
    HI_MPI_VDEC_StopRecvStream(0);
    HI_MPI_VDEC_ResetChn(0);
    if(playStatus == 0)//实时流
    {
        set= VdecThread::m_stringList->at(value - 2).toLongLong();
    }else {
        set= m_ICountList.at(value -2).toLongLong();
    }
    setUsedBytes(set);
    HI_MPI_VO_ChnRefresh(0,0);
    HI_MPI_VDEC_StartRecvStream(0);
}

/********************************************
 * function: slotFF10(int value,bool realPlay)
 * 类别：槽函数
 * 参数：value:当前播放位置 realPlay:是否实时播放
 * 返回值：void
 * 功能：当前播放位置快进10S
 * ******************************************/
void VdecThread::slotFF10(int value,bool realPlay,bool playStatus)
{
    HI_U64 set;
    HI_MPI_VDEC_StopRecvStream(0);
    HI_MPI_VDEC_ResetChn(0);
    if(playStatus == 0)
    {
        set = VdecThread::m_stringList->at(value + 10).toLongLong();
    }else{
        set = m_ICountList.at(value + 10).toLongLong();
}
    setUsedBytes(set);
    HI_MPI_VO_ChnRefresh(0,0);
    HI_MPI_VDEC_StartRecvStream(0);
}

/********************************************
 * function: slotFF2(int value,bool realPlay)
 * 类别：槽函数
 * 参数：value:当前播放位置 realPlay:是否实时播放
 * 返回值：void
 * 功能：当前播放位置快进2S
 * ******************************************/
void VdecThread::slotFF2(int value, bool realPlay, bool playStatus)
{
    HI_U64 set;
    if(realPlay == HI_TRUE)
    {
        setPts(33000);
        setSleepTime(20000);
    }
    HI_MPI_VDEC_StopRecvStream(0);
    HI_MPI_VDEC_ResetChn(0);
    if(playStatus == 0)
    {
        set = VdecThread::m_stringList->at(value + 2).toLongLong();
    }else{
        set = m_ICountList.at(value + 2).toLongLong();
    }
    setUsedBytes(set);
    HI_MPI_VO_ChnRefresh(0,0);
    HI_MPI_VDEC_StartRecvStream(0);
}

/********************************************
 * function: openFile()
 * 类别：类成员函数
 * 参数：void
 * 返回值：void
 * 功能：打开待解码文件并执行malloc分配内存
 * ******************************************/
void VdecThread::openFile()
{
    fp = fopen64(getFilePath().toLocal8Bit().data(),"r");
    while(HI_NULL == fp)
    {
        usleep(10);
        fp = fopen64(getFilePath().toLocal8Bit().data(),"r");
    }

    /******************* malloc the  stream buffer in user space *****************/
    if(VdecThread::gs_sendParam->s32MinBufSize!=0)
    {
        pu8Buf=(HI_U8 *)malloc(VdecThread::gs_sendParam->s32MinBufSize);
        if(pu8Buf==NULL)
        {
            SAMPLE_PRT("can't alloc %d in send stream thread:%d\n",VdecThread::gs_sendParam->s32MinBufSize,VdecThread::gs_sendParam->VdChn);
            fclose(fp);
        }
    }else
    {
        SAMPLE_PRT("none buffer to operate in send stream thread:%d\n",VdecThread::gs_sendParam->VdChn);
    }
}

/********************************************
 * function: run()
 * 类别：重写函数run()
 * 参数：void
 * 返回值：void
 * 功能：解码线程
 * ******************************************/
void VdecThread::run()
{
//    VDEC_STREAM_S stStream;
    //SAMPLE_VDEC_SENDPARAM_S *pstSendParam;
    //char sFileName[50], sFilePostfix[20];
    //FILE* fp = NULL;
    HI_S32 s32BlockMode = HI_IO_BLOCK;
    HI_U64 u64pts;
    HI_S32 i, s32Ret, len, start;
    HI_S64 s32ReadLen;
    HI_BOOL bFindStart, bFindEnd;
    start = 0;
    u64pts= 0;
    /******************* open the stream file *****************/

    //SAMPLE_COMM_SYS_Payload2FilePostfix(VdecThread::gs_sendParam->enPayload, sFilePostfix);
    //sprintf(sFileName, "/mnt/save_stream%s", sFilePostfix);
    //fp = fopen64(sFileName, "r");
    //printf("%s\n",getFilePath().toLocal8Bit().data());
    openFile();
    while (HI_TRUE == VdecThread::gs_sendParam->bRun)
    {
        if(run_flag == HI_TRUE)
        {
        signal(SIGBUS,SIG_IGN);
        //printf("usedbyte: %llu\n",getUsedBytes());

        fseeko64(fp, getUsedBytes(), SEEK_SET);
        s32ReadLen = fread(pu8Buf, 1, VdecThread::gs_sendParam->s32MinBufSize, fp);
        if (s32ReadLen<0)
        {
             printf("file end.\n");
             break;
        }

        //printf("readLen: %llu\n",s32ReadLen);
        /******************* cutting the stream for frame *****************/
        if( (VdecThread::gs_sendParam->enVideoMode==VIDEO_MODE_FRAME) && (VdecThread::gs_sendParam->enPayload== PT_H264) )
        {
            bFindStart = HI_FALSE;
            bFindEnd   = HI_FALSE;
            for (i=0; i<s32ReadLen-5; i++)
            {
                if (  pu8Buf[i  ] == 0 && pu8Buf[i+1] == 0 && pu8Buf[i+2] == 1 &&
                    ((pu8Buf[i+3]&0x1F) == 0x5 || (pu8Buf[i+3]&0x1F) == 0x1) &&
                    ((pu8Buf[i+4]&0x80) == 0x80)
                   )
                {
//                    if(pu8Buf[i] == 0 &&pu8Buf[i + 1] == 0&&pu8Buf[i + 2] == 1 &&pu8Buf[i + 3] == 101)
//                    {
//                        QString writeMsg = QString::number(getUsedBytes()) + "|";
//                        m_saveFile->write(writeMsg.toLocal8Bit().data());
//                        printf("where: %llu\n",getUsedBytes());
//                    }
                    bFindStart = HI_TRUE;
                    i += 4;
                    break;
                }
            }

            for (; i<s32ReadLen-5; i++)
            {
                if (  pu8Buf[i  ] == 0 && pu8Buf[i+1] == 0 && pu8Buf[i+2] == 1 &&
                    ((pu8Buf[i+3]&0x1F) == 0x5 || (pu8Buf[i+3]&0x1F) == 0x1) &&
                    ((pu8Buf[i+4]&0x80) == 0x80)
                   )
                {
                    bFindEnd = HI_TRUE;
                    break;
                }
            }

            s32ReadLen = i;
            if (bFindStart == HI_FALSE)
            {
                //SAMPLE_PRT("can not find start code in send stream thread:%d\n",pstSendParam->VdChn);
            }else if (bFindEnd == HI_FALSE)
            {
                s32ReadLen = i+5;
            }
        }

         stStream.u64PTS  = u64pts;
         stStream.pu8Addr = pu8Buf + start;
         stStream.u32Len  = s32ReadLen;
        if(VdecThread::gs_sendParam->enVideoMode==VIDEO_MODE_FRAME)
        {
            u64pts+=getPts();
        }
        /******************* send stream *****************/
        if (s32BlockMode == HI_IO_BLOCK)
        {
            s32Ret=HI_MPI_VDEC_SendStream(VdecThread::gs_sendParam->VdChn, &stStream, HI_IO_BLOCK);
        }else if (s32BlockMode == HI_IO_NOBLOCK)
        {
            s32Ret=HI_MPI_VDEC_SendStream(VdecThread::gs_sendParam->VdChn, &stStream, HI_IO_NOBLOCK);
        }else
        {
            s32Ret=HI_MPI_VDEC_SendStream_TimeOut(VdecThread::gs_sendParam->VdChn, &stStream, 8000);
        }

        if (HI_SUCCESS == s32Ret)
        {
            setUsedBytes(getUsedBytes() + s32ReadLen + start);
            //s32UsedBytes = s32UsedBytes +s32ReadLen + start;
        }else
        {
            if (s32BlockMode != HI_IO_BLOCK)
            {
                SAMPLE_PRT("failret:%x\n",s32Ret);
            }
            usleep(40000);
            //usleep(s32IntervalTime);
        }
        usleep(getSleepTime());//控制向vdec解码通道发送码流的速度即给予vdec解码时间
    }
    }
    printf("file end\n");
    if (pu8Buf != HI_NULL)
    {
        free(pu8Buf);
    }
    fclose(fp);
}



