#include "vdec.h"

vdec::vdec(QObject *parent) :
    QObject(parent)
{
    m_vdecThread = new VdecThread();
    connect(this,SIGNAL(signalVideoPlay(QString,bool)),m_vdecThread,SLOT(slotVideoPlay(QString,bool)));
    connect(this,SIGNAL(signalFastPlay()),m_vdecThread,SLOT(slotFastPlay()));
    connect(this,SIGNAL(signalSlowPlay()),m_vdecThread,SLOT(slotSlowPlay()));
    connect(this,SIGNAL(signalRealPlay()),m_vdecThread,SLOT(slotRealPlay()));
    m_timer = new QTimer();
    m_timer->setInterval(5000);
    m_timer->start();
    connect(m_timer,SIGNAL(timeout()),m_vdecThread,SLOT(slotTimerOut()));
    VdecBindVpss();
    VpssBindVo();

}
vdec::~vdec()
{

}

void vdec::VdecBindVpss()
{
    HI_S32 s32Ret;
    s32Ret = SAMLE_COMM_VDEC_BindVpss(0, 1);
    if (HI_SUCCESS !=s32Ret)
    {
        SAMPLE_PRT("vdec bind vpss failed!\n");
    }
}

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
    emit signalVideoPlay(filepath,status);
}

//暂停播放
void vdec::slotPause()
{
    printf("pause\n");
    HI_MPI_VO_ChnPause(0,0);
    //HI_MPI_VO_ChnHide(0,0);
}

//恢复播放
void vdec::slotResume()
{
    printf("resume\n");
    HI_MPI_VO_ChnResume(0,0);
    //HI_MPI_VO_ChnShow(0,0);
}

//快放 50帧/S
void vdec::slotFastPlay()
{
    emit signalFastPlay();
}

//慢放 13帧/S
void vdec::slotSlowPlay()
{
    emit signalSlowPlay();
}

void vdec::slotRealPlay()
{
    emit signalRealPlay();
}
