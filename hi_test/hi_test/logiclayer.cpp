#include "logiclayer.h"
#include "vdec.h"
#include "chead.h"
Logiclayer::Logiclayer(QObject *parent) :
    QObject(parent)
{
    m_showForm = new ShowForm();
    m_DesktopForm = new DesktopForm();

    m_showForm->setWindowFlags(m_showForm->windowFlags()&~Qt::WindowMaximizeButtonHint\
                               &~Qt::WindowMinimizeButtonHint);
    m_DesktopForm->setWindowFlags(Qt::WindowTitleHint);

    m_DesktopForm->showMaximized();
    m_showForm->hide();
    m_timer = new QTimer();
    m_timer->setInterval(1000);

    connect(m_DesktopForm,SIGNAL(signalRealPlay(QString,bool)),this,SLOT(slotVideoShow(QString,bool)));//显示实时流播放界面
    connect(m_DesktopForm,SIGNAL(signalSelectFile()),this,SLOT(slotSelectFile()));//选取播放文件
    //connect(m_documentForm,SIGNAL(signalVideoShow(QString,bool)),this,SLOT(slotVideoShow(QString,bool)));
    connect(m_showForm,SIGNAL(signalDesktopFormShow()),this,SLOT(slotDesktopFormShow()));
    connect(m_timer,SIGNAL(timeout()),m_showForm,SLOT(slotTimerOut()));
}

Logiclayer::~Logiclayer()
{

}

/********************************************
 * function: setStatus(bool status)
 * 类别：类成员函数
 * 参数：status
 * 返回值：void
 * 功能：设置状态：实时|录像文件播放
 * ******************************************/
void Logiclayer::setStatus(bool status)
{
    status_flag = status;
}

const bool &Logiclayer::getStatus() const
{
    return status_flag;
}

/********************************************
 * function: slotSelectFile()
 * 类别：类成员函数
 * 参数：void
 * 返回值：void
 * 功能：检索录像文件
 * ******************************************/
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
        VdecThread::m_stringList->clear();
        connect(this,SIGNAL(signalRealPlay(QString,bool)),m_venc,SLOT(slotRealPlay(QString,bool)));
        emit signalRealPlay(filepath,status);
    }
    emit signalVideoPlayStart();
    //sleep(1);
    //usleep(400000);
    m_vdec = new vdec;
    m_timer->start();
    connect(this,SIGNAL(signalVideoPlay(QString,bool)),m_vdec,SLOT(slotVideoPlay(QString,bool)));//显示播放界面
    connect(m_showForm,SIGNAL(signalPause()),m_vdec,SLOT(slotPause()));//暂停播放
    connect(m_showForm,SIGNAL(signalResume()),m_vdec,SLOT(slotResume()));//恢复播放
    connect(m_showForm,SIGNAL(signalFastPlay()),m_vdec,SLOT(slotFastPlay()));//快放 50帧/S
    connect(m_showForm,SIGNAL(signalSlowPlay()),m_vdec,SLOT(slotSlowPlay()));//慢放 13帧/S
    connect(m_showForm,SIGNAL(signalRealPlay()),m_vdec,SLOT(slotRealPlay())); //恢复正常播放 25帧/S
    connect(m_showForm,SIGNAL(signalDelay10(int)),m_vdec,SLOT(slotDelay10(int)));//后退10S
    connect(m_showForm,SIGNAL(signalDelay2(int)),m_vdec,SLOT(slotDelay2(int))); //后退2S

    connect(m_showForm,SIGNAL(signalFF10(int,bool)),m_vdec,SLOT(slotFF10(int,bool)));//快进10S
    connect(m_showForm,SIGNAL(signalFF2(int,bool)),m_vdec,SLOT(slotFF2(int,bool)));//快进2S

    emit signalVideoPlay(filepath,status);
    HI_MPI_VO_ChnShow(0,0);
    m_DesktopForm->hide();
    m_showForm->showMaximized();
}

void Logiclayer::slotDesktopFormShow()
{
    m_timer->stop();
    usleep(50000);
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

/***************************************************
 * function: viUnbindVenc(VI_CHN srcChn,VENC_CHN destChn)
 * 类别：类成员函数
 * 参数：srcChn:输入通道 destChn:venc编码通道
 * 返回值：void
 * 功能：vi解绑venc
 * *************************************************/
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

/********************************************************
 * function: vdecUnbindVpss(VDEC_CHN srcChn, VPSS_CHN destChn)
 * 类别：类成员函数
 * 参数：srcChn:解码通道 destChn:VPSS通道
 * 返回值：void
 * 功能：vdec解绑VPSS
 * ******************************************************/
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
/********************************************************
 * function: vpssUnbindVo(VPSS_CHN vpssChn, VO_CHN voChn)
 * 类别：类成员函数
 * 参数：vpssChn:VPSS通道 voChn:Vo通道
 * 返回值：void
 * 功能：VPSS解绑VO
 * ******************************************************/
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



