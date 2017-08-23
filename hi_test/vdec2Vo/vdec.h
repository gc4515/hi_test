#ifndef VDEC_H
#define VDEC_H

#include <QObject>
#include "chead.h"
#include "vdecthread.h"
#include <QTimer>

class vdec : public QObject
{
    Q_OBJECT
public:
    explicit vdec(QObject *parent = 0);
    ~vdec();
    void VdecBindVpss();
    void VpssBindVo();

signals:
    void signalVideoPlay(const QString &filepath,bool status);
    void signalFastPlay();
    void signalSlowPlay();
    void signalRealPlay();
    void signalDelay10(int value);
    void signalDelay2(int value);
    void signalFF10(int value);
    void signalFF2(int value);
public slots:
    void slotPause();
    void slotResume();
    void slotFastPlay();
    void slotSlowPlay();
    void slotRealPlay();
    void slotDelay10(int value);
    void slotDelay2(int value);
    void slotFF10(int value);
    void slotFF2(int value);
    void slotVideoPlay(QString filepath, bool status);
private:
    VdecThread *m_vdecThread;
};

#endif // VDEC_H
