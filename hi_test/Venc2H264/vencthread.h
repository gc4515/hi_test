#ifndef VENCTHREAD_H
#define VENCTHREAD_H

#include <QObject>
#include <QThread>
#include "chead.h"
#include <QReadWriteLock>
#include <QDateTime>
class VencThread : public QThread
{
    Q_OBJECT
public:
    explicit VencThread(QObject *parent = 0);
    ~VencThread();
    void setVencFilePath(const QString &filepath);
    QString getVencFilePath()const;

    void run();
    HI_S32 SAMPLE_COMM_VENC_SaveH264(FILE *fpH264File, VENC_STREAM_S *pstStream);
    static SAMPLE_VENC_GETSTREAM_PARA_S *gs_stPara;

signals:

public slots:
    void slotRealPlay(QString filepath,bool status);
private:
    QReadWriteLock *m_lock;
    QString m_vencFilePath;
    int m_Icount;
};

#endif // VENCTHREAD_H
