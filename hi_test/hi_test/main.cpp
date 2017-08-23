#include <QApplication>
#include "logiclayer.h"
#include "venc.h"
#include "vdec.h"
#include <QFontDatabase>
#include <QTextCodec>
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
void signalBus(int);
void signalBus(int)
{
    printf("signalbus\n");
}

int main(int argc,char *argv[])
{
    //HI_MPI_SYS_Exit();
    SystemInit systeminit;
//    Venc m_venc;
//    usleep(10);
//    vdec m_vdec;
    systeminit.HifbInit();
    QApplication a(argc,argv);
    signal(SIGBUS,signalBus);//SIG_IGN
    Logiclayer logic;
    QObject::connect(&logic,SIGNAL(signalVideoPlayStart()),&systeminit,SLOT(slotVideoPlayStart()));

    return a.exec();
}
