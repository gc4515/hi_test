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
    void setUsedBytes(const HI_S64 &usedbytes);
    const HI_S64 &getUsedBytes()const;

    void setFilePath(const QString &filepath);
    const QString &getFilePath()const;

    static SAMPLE_VDEC_SENDPARAM_S *gs_sendParam;
signals:

public slots:
    void slotVideoPlay(QString filepath);
private:
    HI_S64 s32UsedBytes;
    QReadWriteLock *m_readlock;
    FILE *fp;
    QString m_filePath;
};

#endif // VDECTHREAD_H
