#ifndef VENC_H
#define VENC_H

#include <QObject>
#include "chead.h"
#include "vencthread.h"
class Venc : public QObject
{
    Q_OBJECT
public:
    explicit Venc(QObject *parent = 0);
    ~Venc();
    void ViBindVenc();
    HI_S32 Venc_ModuleInit();
signals:
    void signalRealPlay(QString filepath,bool status);
public slots:
    void slotRealPlay(QString filepath,bool status);
private:
    VencThread *m_vencThread;
};

#endif // VENC_H
