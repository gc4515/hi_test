#include "venc.h"

Venc::Venc(QObject *parent) :
    QObject(parent)
{
    m_vencThread = new VencThread;
    connect(this,SIGNAL(signalRealPlay(QString,bool)),m_vencThread,SLOT(slotRealPlay(QString,bool)));
    ViBindVenc();
}
Venc::~Venc()
{

}

//Vi 直接绑定VENC
void Venc::ViBindVenc()
{
    //HI_MPI_VENC_SetMaxStreamCnt(0,2);
    HI_S32 s32Ret;
    MPP_CHN_S stBindSrc;
    MPP_CHN_S stBindDest;
    stBindDest.enModId = HI_ID_GROUP;
    stBindDest.s32ChnId = 0;
    stBindDest.s32DevId = 0;

    stBindSrc.enModId = HI_ID_VIU;
    stBindSrc.s32ChnId = 0;
    stBindSrc.s32DevId = 0;
    s32Ret = HI_MPI_SYS_Bind(&stBindSrc, &stBindDest);

    VencThread::gs_stPara->bThreadStart = HI_TRUE;
    VencThread::gs_stPara->s32Cnt = 1;

    m_vencThread->start();
}

void Venc::slotRealPlay(QString filepath,bool status)
{
    emit signalRealPlay(filepath,status);
}
