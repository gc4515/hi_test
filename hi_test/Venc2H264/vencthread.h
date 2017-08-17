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

    void run();
    HI_S32 SAMPLE_COMM_VENC_SaveH264(FILE *fpH264File, VENC_STREAM_S *pstStream);
    static SAMPLE_VENC_GETSTREAM_PARA_S *gs_stPara;

signals:

public slots:

private:
    QReadWriteLock *m_lock;
    QDateTime *m_dateTime;
};

#endif // VENCTHREAD_H
