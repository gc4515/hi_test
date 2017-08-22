#include "vdecthread.h"

#define _FILE_OFFSET_BITS 64
SAMPLE_VDEC_SENDPARAM_S *VdecThread::gs_sendParam = new SAMPLE_VDEC_SENDPARAM_S;
VdecThread::VdecThread(QObject *parent) :
    QThread(parent)
{
    setUsedBytes(0);
    fp = NULL;
    pu8Buf = NULL;
    run_flag = HI_TRUE;
    m_ICount = 0;
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

void VdecThread::slotTimerOut()
{
    //printf("time: %llu\n",getPts());
    if(play_status == 0)
    {
        if(getPts() == 30000)
        {
            setPts(40000);
            setSleepTime(20000);
        }else{
            setPts(30000);
        }
    }
}

void VdecThread::slotVideoPlay(QString filepath,bool status)
{
    play_status = status;
    //filepath= filepath.replace(QString("\n"),QString(""));
    printf("vdec:%s\n",filepath.toLocal8Bit().data());
    if(status == 0)
    {
        setPts(40000);
        setSleepTime(20000);
        setFilePath(filepath);
    }else{
        setPts(40000);
        setSleepTime(20000);
        filepath = filepath.left(filepath.length() - 1);
        setFilePath(filepath);
    }
}

void VdecThread::slotFastPlay()
{
    HI_S32 s32Ret;

    s32Ret = HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    if(s32Ret != HI_SUCCESS)
    {
        printf("HI_MPI_VO_ClearChnBuffer failed\n");
    }
    s32Ret = HI_MPI_VO_SetChnFrameRate(0,0,50);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VO_SetChnFrameRate failed\n");
    }
    setPts(20000);
    setSleepTime(10000);
    printf("fast\n");
}
void VdecThread::slotSlowPlay()
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
    setPts(80000);
    //setSleepTime(10000);
    printf("slow\n");
}
void VdecThread::slotRealPlay()
{
    HI_S32 s32Ret;
    s32Ret = HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    if(s32Ret != HI_SUCCESS)
    {
        printf("HI_MPI_VO_ClearChnBuffer failed\n");
    }

    s32Ret = HI_MPI_VO_SetChnFrameRate(0,0,30);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VO_SetChnFrameRate failed\n");
    }
    if(play_status == 0)
    {
        setPts(40000);
        setSleepTime(20000);
    }else{
        setPts(40000);
        setSleepTime(20000);
    }
}

/*********************************************
 * 打开文件并且分配缓存
 * *******************************************/
void VdecThread::openFile()
{
    fp = fopen64(getFilePath().toLocal8Bit().data(),"r");
    //fp = fopen64("/home/2017.8.17_11-07-00.h264","r");
    while(HI_NULL == fp)
    {
        usleep(10);
        fp = fopen64(getFilePath().toLocal8Bit().data(),"r");
        if(HI_NULL == fp)
        {
            SAMPLE_PRT("can't open file %s in send stream thread:%d\n", getFilePath().toLocal8Bit().data(),VdecThread::gs_sendParam->VdChn);
        }
    }

    printf("open file [%s] ok in send stream thread:%d!\n", getFilePath().toLocal8Bit().data(),VdecThread::gs_sendParam->VdChn);
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

void VdecThread::run()
{
    VDEC_STREAM_S stStream;
    //SAMPLE_VDEC_SENDPARAM_S *pstSendParam;
    //char sFileName[50], sFilePostfix[20];
    //FILE* fp = NULL;
    HI_S32 s32BlockMode = HI_IO_BLOCK;
    HI_U64 u64pts;
    //HI_S32 s32IntervalTime = 40000;
    HI_S32 i, s32Ret, len, start;
    HI_S64 s32ReadLen;
    HI_BOOL bFindStart, bFindEnd;
    start = 0;
    u64pts= 0;
    //s32UsedBytes = 0;
    /******************* open the stream file *****************/

    //SAMPLE_COMM_SYS_Payload2FilePostfix(VdecThread::gs_sendParam->enPayload, sFilePostfix);
    //sprintf(sFileName, "/mnt/save_stream%s", sFilePostfix);
    //fp = fopen64(sFileName, "r");
    //printf("%s\n",getFilePath().toLocal8Bit().data());
    openFile();
    //m_timer->start();
    while (HI_TRUE == VdecThread::gs_sendParam->bRun)
    {
        fseeko64(fp, getUsedBytes(), SEEK_SET);
        s32ReadLen = fread(pu8Buf, 1, VdecThread::gs_sendParam->s32MinBufSize, fp);
        if (s32ReadLen<0)
        {
             printf("file end.\n");
             break;
        }
        printf("readLen: %llu\n",s32ReadLen);
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
//                    if((pu8Buf[i + 3] &0x1F) == 0x5)
//                    {
//                        printf("I: %d\n",m_ICount++);
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
            //printf("pts :%llu\n",getPts());
        }
        //printf("get\n");
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
//            usleep(s32IntervalTime);
        }
        usleep(getSleepTime());//控制向vdec解码通道发送码流的速度即给予vdec解码时间
    }
    printf("file end\n");
    if (pu8Buf != HI_NULL)
    {
        free(pu8Buf);
    }
    fclose(fp);
}



