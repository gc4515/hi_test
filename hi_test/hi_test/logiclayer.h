#ifndef LOGICLAYER_H
#define LOGICLAYER_H

#include <QObject>
#include "showform.h"
#include "desktopform.h"
#include "systeminit.h"
#include "vdec.h"
#include "venc.h"
#include "documentform.h"
#include <QTimer>

class Logiclayer : public QObject
{
    Q_OBJECT
public:
    explicit Logiclayer(QObject *parent = 0);
    ~Logiclayer();
    void vdecUnbindVpss(VDEC_CHN srcChn, VPSS_CHN destChn);
    void vpssUnbindVo(VPSS_CHN vpssChn, VO_CHN voChn);
    void viUnbindVenc(VI_CHN srcChn,VENC_CHN destChn);

    void setStatus(bool status);
    const bool& getStatus()const;
signals:
    void signalPause();
    void signalResume();
    void signalVideoPlay(QString filepath,bool status);
    void signalVideoPlayStart();
    void signalRealPlay(QString filepath,bool status);
public slots:
    void slotVideoShow(QString filepath, bool status);
//    void slotPause();
//    void slotResume();
    void slotDesktopFormShow();
    void slotSelectFile();
private:
    SystemInit *m_systemInit;
    ShowForm *m_showForm;
    DesktopForm *m_DesktopForm;
    DocumentForm *m_documentForm;
    vdec *m_vdec;
    Venc *m_venc;
    QTimer *m_timer;
    bool status_flag;
};

#endif // LOGICLAYER_H
