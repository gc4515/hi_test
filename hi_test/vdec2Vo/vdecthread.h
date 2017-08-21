#ifndef VDECTHREAD_H
#define VDECTHREAD_H

#include <QThread>
#include "chead.h"
#include <QReadWriteLock>
#include <QFile>
class VdecThread : public QThread
{
    Q_OBJECT
public:
    explicit VdecThread(QObject *parent = 0);
    ~VdecThread();
    void run();
    void openFile();

    void setUsedBytes(const HI_S64 &usedbytes);
    const HI_S64 &getUsedBytes()const;

    void setFilePath(const QString &filepath);
    const QString getFilePath()const;

    void setPts(const HI_U64 &pts);
    const HI_U64 &getPts()const;

    void setSleepTime(const HI_U64 &sleeptime);
    const HI_U64 &getSleepTime()const;

    static SAMPLE_VDEC_SENDPARAM_S *gs_sendParam;
signals:

public slots:
    void slotVideoPlay(QString filepath, bool status);
    void slotFastPlay();
    void slotSlowPlay();
    void slotRealPlay();
private:
    HI_S64 s32UsedBytes;
    QReadWriteLock *m_readlock;
    FILE *fp;
    HI_U8 *pu8Buf;
    QString m_filePath;
    HI_U64 m_pts;
    HI_U64 m_sleepTime;
    bool play_status;
    bool run_flag;
};

#endif // VDECTHREAD_H
