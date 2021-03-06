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
    void signalPause();
    void signalResume();
    void signalFastPlay();
    void signalSlowPlay();
    void signalRealPlay();
    void signalDelay10(int value,bool playStatus);
    void signalDelay2(int value,bool playStatus);
    void signalFF10(int value,bool realPlay,bool playStatus);
    void signalFF2(int value,bool realPlay,bool playStatus);
    void signalSliderReleased(const int &value,bool playStatus);
public slots:
    void slotPause();
    void slotResume();
    void slotFastPlay();
    void slotSlowPlay();
    void slotRealPlay();
    void slotDelay10(int value);
    void slotDelay2(int value);
    void slotFF10(int value, bool realPlay);
    void slotFF2(int value,bool realPlay);
    void slotVideoPlay(QString filepath, bool status);
    void slotSliderReleased(int value);
private:
    VdecThread *m_vdecThread;
    bool m_playStatus;
};

#endif // VDEC_H
