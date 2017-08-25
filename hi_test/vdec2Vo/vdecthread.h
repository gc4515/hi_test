#ifndef VDECTHREAD_H
#define VDECTHREAD_H

#include <QThread>
#include "chead.h"
#include <QReadWriteLock>
#include <QFile>
#include <QStringList>

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
    static QStringList *m_stringList;
signals:

public slots:
    void slotVideoPlay(QString filepath, bool status);
    void slotPause();
    void slotResume();
    void slotFastPlay();
    void slotSlowPlay();
    void slotRealPlay();
    void slotDelay10(int value);
    void slotDelay2(int value);
    void slotFF10(int value,bool realPlay);
    void slotFF2(int value,bool realPlay);
private:
    HI_S64 s32UsedBytes;
    QReadWriteLock *m_readlock;
    FILE *fp;
    HI_U8 *pu8Buf;
    QString m_filePath;
    HI_U64 m_pts;
    HI_U64 m_sleepTime;
    QFile *m_saveFile;
    bool play_status;
    bool run_flag;
    HI_U32 m_ICount;
    VDEC_STREAM_S stStream;
};

#endif // VDECTHREAD_H
