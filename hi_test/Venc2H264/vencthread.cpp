#include "vencthread.h"
#define _FILE_OFFSET_BITS 64
SAMPLE_VENC_GETSTREAM_PARA_S *VencThread::gs_stPara = new SAMPLE_VENC_GETSTREAM_PARA_S;

VencThread::VencThread(QObject *parent) :
    QThread(parent)
{
    m_lock = new QReadWriteLock();
    m_Icount = 0;
}
VencThread::~VencThread()
{
    delete m_lock;
}

void VencThread::setVencFilePath(const QString &filepath)
{
    m_vencFilePath.clear();
    m_vencFilePath = filepath;
}

QString VencThread::getVencFilePath() const
{
    return m_vencFilePath;
}

void VencThread::slotRealPlay(QString filepath, bool status)
{
    setVencFilePath(filepath);
}
void VencThread::run()
{
    HI_S32 i;
    //HI_S32 s32ChnTotal;
    VENC_CHN_ATTR_S stVencChnAttr;
    SAMPLE_VENC_GETSTREAM_PARA_S *pstPara;
    HI_S32 maxfd = 0;
    struct timeval TimeoutVal;
    fd_set read_fds;
    HI_S32 VencFd[VENC_MAX_CHN_NUM];
    HI_CHAR aszFileName[VENC_MAX_CHN_NUM][64];
    FILE *pFile[VENC_MAX_CHN_NUM];
    char szFilePostfix[10];
    VENC_CHN_STAT_S stStat;
    VENC_STREAM_S stStream;
    HI_S32 s32Ret;
    VENC_CHN VencChn;
    PAYLOAD_TYPE_E enPayLoadType[VENC_MAX_CHN_NUM];

    /********************************************
     * step 1: check &prepare save-file &venc-fd
     * ******************************************/
//    if(VencThread::gs_stPara->s32Cnt >= VENC_MAX_CHN_NUM)
//    {
//        SAMPLE_PRT("input count invaild\n");
//    }
    for(i = 0; i < VencThread::gs_stPara->s32Cnt; i++)
    {
        /*decide the stream file name, and open file to save stream.*/
        VencChn = i;
        s32Ret = HI_MPI_VENC_GetChnAttr(VencChn,&stVencChnAttr);
        if(s32Ret != HI_SUCCESS)
        {
            SAMPLE_PRT("HI_MPI_VENC_GetChnAttr chn[%d] failed with%#x!\n",\
                       VencChn,s32Ret);
        }
        enPayLoadType[i] = stVencChnAttr.stVeAttr.enType;

        //strcpy(szFilePostfix, ".h264");

        //aszFileName[i] = filename.toLocal8Bit().data();
        //sprintf(aszFileName[i], "/home/save_stream%s", szFilePostfix);
        pFile[i] = fopen64(getVencFilePath().toLocal8Bit().data(), "w");
        printf("venc:%s\n",getVencFilePath().toLocal8Bit().data());
        if (!pFile[i])
        {
            SAMPLE_PRT("open file[%s] failed!\n",
                   getVencFilePath().toLocal8Bit().data());
        }

        /*Set Venc Fd*/
        VencFd[i] = HI_MPI_VENC_GetFd(i);
        if (VencFd[i] < 0)
        {
            SAMPLE_PRT("HI_MPI_VENC_GetFd failed with %#x!\n",
                   VencFd[i]);
        }
        if (maxfd <= VencFd[i])
        {
            maxfd = VencFd[i];
        }
    }
    //printf("%d\n",GetVencStream::gs_stPara->bThreadStart);
    /*******************************************
     * step 2: Start to get streams of each channel
     * *****************************************/
    while(HI_TRUE == VencThread::gs_stPara->bThreadStart)
    {
        //printf("venc\n");
        FD_ZERO(&read_fds);
        for(i = 0; i < VencThread::gs_stPara->s32Cnt;i++)
        {
            FD_SET(VencFd[i],&read_fds);
        }

        TimeoutVal.tv_sec = 2;
        TimeoutVal.tv_usec = 0;

        s32Ret = select(maxfd + 1,&read_fds,NULL,NULL,&TimeoutVal);
        //printf("save\n");
        if(s32Ret < 0)
        {
            SAMPLE_PRT("select failed!\n");
            break;
        }else if(s32Ret == 0)
        {
            SAMPLE_PRT("get venc stream time out, exit thread\n");
            continue;
        }else{
            for(i = 0; i < VencThread::gs_stPara->s32Cnt;i++)
            {
                if(FD_ISSET(VencFd[i],&read_fds))
                {
                    /***********************************************
                     * step 2.1 : query how many packs in one-frame stream
                     * *********************************************/
                    memset(&stStream,0,sizeof(stStream));
                    s32Ret = HI_MPI_VENC_Query(i,&stStat);
                    if(HI_SUCCESS != s32Ret)
                    {
                        SAMPLE_PRT("HI_MPI_VENC_Query chn[%d] failed with %#x!\n", i, s32Ret);
                        break;
                    }

                    /*******************************************************
                     step 2.2 : malloc corresponding number of pack nodes.
                    *******************************************************/
                    stStream.pstPack = (VENC_PACK_S*)malloc(sizeof(VENC_PACK_S) * stStat.u32CurPacks);
                    if (NULL == stStream.pstPack)
                    {
                        SAMPLE_PRT("malloc stream pack failed!\n");
                        break;
                    }

                    /*******************************************************
                     step 2.3 : call mpi to get one-frame stream
                    *******************************************************/
                    stStream.u32PackCount = stStat.u32CurPacks;
                    stStream.pstPack->u64PTS +=40000;
                    s32Ret = HI_MPI_VENC_GetStream(i, &stStream, HI_TRUE);
                    if (HI_SUCCESS != s32Ret)
                    {
                        free(stStream.pstPack);
                        stStream.pstPack = NULL;
                        SAMPLE_PRT("HI_MPI_VENC_GetStream failed with %#x!\n", \
                               s32Ret);
                        break;
                    }

                    /*******************************************************
                     step 2.4 : save frame to file
                    *******************************************************/
                    s32Ret = SAMPLE_COMM_VENC_SaveH264(pFile[i], &stStream);
                    if (HI_SUCCESS != s32Ret)
                    {
                        free(stStream.pstPack);
                        stStream.pstPack = NULL;
                        SAMPLE_PRT("save stream failed!\n");
                        break;
                    }

                    /*******************************************************
                     step 2.5 : release stream
                    *******************************************************/
                    s32Ret = HI_MPI_VENC_ReleaseStream(i, &stStream);
                    if (HI_SUCCESS != s32Ret)
                    {
                        free(stStream.pstPack);
                        stStream.pstPack = NULL;
                        break;
                    }
                    /*******************************************************
                     step 2.6 : free pack nodes
                    *******************************************************/
                    free(stStream.pstPack);
                    stStream.pstPack = NULL;
                }
            }
        }
    }
}

HI_S32 VencThread::SAMPLE_COMM_VENC_SaveH264(FILE *fpH264File, VENC_STREAM_S *pstStream)
{
    HI_S32 i;
    m_lock->lockForWrite();
    //printf("pack: %d\n",pstStream->u32PackCount);

    for(i = 0; i < pstStream->u32PackCount;i++)
    {
        fflush(fpH264File);
            //printf("stream: %x\n",pstStream->pstPack[i].pu8Addr[0][4]);
            if(pstStream->pstPack[i].pu8Addr[0][4] == 101)
            {
                printf("I: %d\n",m_Icount++);
                printf("where: %llu\n",ftello64(fpH264File));
            }
        fwrite(pstStream->pstPack[i].pu8Addr[0],\
                pstStream->pstPack[i].u32Len[0],1,fpH264File);
        fflush(fpH264File);

        if(pstStream->pstPack[i].u32Len[1] > 0)
        {
            fwrite(pstStream->pstPack[i].pu8Addr[1],\
                    pstStream->pstPack[i].u32Len[1],1,fpH264File);

            fflush(fpH264File);
        }
    }
    m_lock->unlock();
    return HI_SUCCESS;
}

