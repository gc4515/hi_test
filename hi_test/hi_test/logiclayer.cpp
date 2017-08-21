#include "logiclayer.h"
#include "vdec.h"
#include "chead.h"
Logiclayer::Logiclayer(QObject *parent) :
    QObject(parent)
{
    m_showForm = new ShowForm();
    m_DesktopForm = new DesktopForm();
    //m_documentForm = new DocumentForm();

    m_showForm->setWindowFlags(m_showForm->windowFlags()&~Qt::WindowMaximizeButtonHint\
                               &~Qt::WindowMinimizeButtonHint);
    /*m_DesktopForm->setWindowFlags(m_DesktopForm->windowFlags()&~Qt::WindowMaximizeButtonHint\
                                  &~Qt::WindowMinimizeButtonHint);*/
    m_DesktopForm->setWindowFlags(Qt::WindowTitleHint);

    m_DesktopForm->showMaximized();
    m_showForm->hide();
    //m_documentForm->hide();

    connect(m_DesktopForm,SIGNAL(signalRealPlay(QString,bool)),this,SLOT(slotVideoShow(QString,bool)));//显示实时流播放界面
    connect(m_DesktopForm,SIGNAL(signalSelectFile()),this,SLOT(slotSelectFile()));//选取播放文件
    //connect(m_documentForm,SIGNAL(signalVideoShow(QString,bool)),this,SLOT(slotVideoShow(QString,bool)));
    connect(m_showForm,SIGNAL(signalDesktopFormShow()),this,SLOT(slotDesktopFormShow()));
}

Logiclayer::~Logiclayer()
{

}

void Logiclayer::setStatus(bool status)
{
    status_flag = status;
}

const bool &Logiclayer::getStatus() const
{
    return status_flag;
}

void Logiclayer::slotSelectFile()
{
    m_documentForm = new DocumentForm();
    m_documentForm->updateDocumentForm();
    connect(m_documentForm,SIGNAL(signalVideoShow(QString,bool)),this,SLOT(slotVideoShow(QString,bool)));
//    m_documentForm->updateDocumentForm();
    m_documentForm->show();
}

void Logiclayer::slotVideoShow(QString filepath,bool status)
{
    setStatus(status);
    if(getStatus() == 0)
    {
        m_venc = new Venc();
        connect(this,SIGNAL(signalRealPlay(QString,bool)),m_venc,SLOT(slotRealPlay(QString,bool)));
        emit signalRealPlay(filepath,status);
    }
    emit signalVideoPlayStart();
    //usleep(1000);
    m_vdec = new vdec;
    connect(this,SIGNAL(signalVideoPlay(QString,bool)),m_vdec,SLOT(slotVideoPlay(QString,bool)));
    connect(m_showForm,SIGNAL(signalPause()),m_vdec,SLOT(slotPause()));//暂停播放
    connect(m_showForm,SIGNAL(signalResume()),m_vdec,SLOT(slotResume()));//恢复播放
    connect(m_showForm,SIGNAL(signalFastPlay()),m_vdec,SLOT(slotFastPlay()));//快放 50帧/S
    connect(m_showForm,SIGNAL(signalSlowPlay()),m_vdec,SLOT(slotSlowPlay()));//慢放 13帧/S
    connect(m_showForm,SIGNAL(signalRealPlay()),m_vdec,SLOT(slotRealPlay())); //恢复正常播放 25帧/S

    emit signalVideoPlay(filepath,status);
    HI_MPI_VO_ChnShow(0,0);
    m_DesktopForm->hide();
    m_showForm->showMaximized();
}

void Logiclayer::slotDesktopFormShow()
{
    if(getStatus() == 0)//实时
    {
        VencThread::gs_stPara->bThreadStart = HI_FALSE;
        VencThread::gs_stPara->s32Cnt = 1;
        viUnbindVenc(0,0);
        //HI_MPI_VENC_DestroyChn(0);
        delete m_venc;
    }
    HI_S32 s32Ret;
    HI_MPI_VO_ClearChnBuffer(0,0,HI_TRUE);
    VdecThread::gs_sendParam->bRun = HI_FALSE;
    vdecUnbindVpss(0,2);

    HI_MPI_VDEC_StopRecvStream(0);

    s32Ret = HI_MPI_VDEC_DestroyChn(0);
    if(HI_SUCCESS != s32Ret)
    {
        printf("HI_MPI_VDEC_DestroyChn failed with %x\n",s32Ret);
    }
    vpssUnbindVo(2,0);
    //HI_MPI_VO_Disable(0);
    HI_MPI_VO_ChnHide(0,0);

    m_showForm->hide();
    m_DesktopForm->showMaximized();
    delete m_vdec;
}

void Logiclayer::viUnbindVenc(VI_CHN srcChn,VENC_CHN destChn)
{
    MPP_CHN_S stSrcChn;
    MPP_CHN_S stDestChn;

    stSrcChn.enModId = HI_ID_VIU;
    stSrcChn.s32DevId = 0;
    stSrcChn.s32ChnId = srcChn;

    stDestChn.enModId = HI_ID_GROUP;
    stDestChn.s32DevId = 0;
    stDestChn.s32ChnId = destChn;

    HI_MPI_SYS_UnBind(&stSrcChn,&stDestChn);
}
void Logiclayer::vdecUnbindVpss(VDEC_CHN srcChn, VPSS_CHN destChn)
{
    MPP_CHN_S stSrcChn;
    MPP_CHN_S stDestChn;

    stSrcChn.enModId = HI_ID_VDEC;
    stSrcChn.s32DevId = 0;
    stSrcChn.s32ChnId = srcChn;

    stDestChn.enModId = HI_ID_VPSS;
    stDestChn.s32DevId = 1;
    stDestChn.s32ChnId = destChn;

    HI_MPI_SYS_UnBind(&stSrcChn,&stDestChn);
}

void Logiclayer::vpssUnbindVo(VPSS_CHN vpssChn, VO_CHN voChn)
{
    MPP_CHN_S stSrcChn1;
    MPP_CHN_S stDestChn1;

    stSrcChn1.enModId = HI_ID_VPSS;
    stSrcChn1.s32DevId = 1;
    stSrcChn1.s32ChnId = vpssChn;

    stDestChn1.enModId = HI_ID_VOU;
    stDestChn1.s32DevId = 0;
    stDestChn1.s32ChnId = voChn;
    HI_MPI_SYS_UnBind(&stSrcChn1,&stDestChn1);
}



