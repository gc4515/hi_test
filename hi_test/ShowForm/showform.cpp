#include "showform.h"
#include "ui_showform.h"
#include <QWSServer>
#include <QMessageBox>
#include <QPalette>
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void signalprint(int);
void signalprint(int)
{
    printf("sigbus error\n");
}
ShowForm::ShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowForm)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
    max = 1;
//    m_timer = new QTimer();
//    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotTimerOut()));
//    m_timer->setInterval(1000);
//    m_timer->start();
    //this->setAttribute(Qt::WA_TranslucentBackground,true);
    QWSServer::setBackground(QColor(0x0,0x0,0x0,0x0));

    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(1);
    ui->horizontalSlider->setValue(0);
}

ShowForm::~ShowForm()
{
    delete ui;
}

void ShowForm::mouseMoveEvent(QMouseEvent *e)
{
    signal(SIGBUS,signalprint);
}
//关闭事件
void ShowForm::closeEvent(QCloseEvent *e)
{
    int r = QMessageBox::question(this,tr("exit"),QObject::trUtf8("确定要退出吗？"),
                                  QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if(r == QMessageBox::Yes)
    {
        ui->label_time->clear();
        max = 1;
        emit signalDesktopFormShow();
        e->accept();
    }else{
        e->ignore();
    }
}

void ShowForm::slotTimerOut()
{
        ui->label_time->setText(QString(trUtf8("%1 秒").arg(QString::number(max))));
        ui->horizontalSlider->setMaximum(max++);
        int value = ui->horizontalSlider->value();
        ui->label_current->setText(QString::number(value));
        //printf("%d\n",value);
        value+=1;
        ui->horizontalSlider->setValue(value);

        value = 0;
}

// 暂停/恢复功能
void ShowForm::on_pb_pause_clicked()
{
    if(m_videoFlag == 0)//当前为播放态
    {
        m_videoFlag = 1;
        ui->pb_pause->setIcon(QIcon("./image/play.png"));
        emit signalPause();
    }else if(m_videoFlag == 1)
    {
        m_videoFlag = 0;
        ui->pb_pause->setIcon(QIcon("./image/pause.png"));
        emit signalResume();
    }
}

//快放
void ShowForm::on_pb_fast_clicked()
{
    emit signalFastPlay();
}

//慢放
void ShowForm::on_pb_slow_clicked()
{
    emit signalSlowPlay();
}

//恢复实时播放
void ShowForm::on_pb_realplay_clicked()
{
    emit signalRealPlay();
}

//后退10S
void ShowForm::on_pb_delay10_clicked()
{
    HI_MPI_VDEC_StopRecvStream(0);
    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);

    //printf("value: %d\n",ui->horizontalSlider->value());
    if(ui->horizontalSlider->value() <= 10)
    {
        emit signalDelay10(10);
        ui->horizontalSlider->setValue(0);
    }else{
        emit signalDelay10(ui->horizontalSlider->value());
        ui->horizontalSlider->setValue(ui->horizontalSlider->value() - 10);
    }
}

void ShowForm::on_pb_delay1_clicked()
{
    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    HI_MPI_VDEC_StopRecvStream(0);
    //printf("value: %d\n",ui->horizontalSlider->value());
    if(ui->horizontalSlider->value() <= 2)
    {
        emit signalDelay2(2);
        ui->horizontalSlider->setValue(0);
    }else{
        emit signalDelay2(ui->horizontalSlider->value());
        ui->horizontalSlider->setValue(ui->horizontalSlider->value() - 2);
    }
}

void ShowForm::on_pb_FF10_clicked()
{
    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    HI_MPI_VDEC_StopRecvStream(0);
    if((ui->horizontalSlider->value() + 10) >= ui->horizontalSlider->maximum())
    {
        emit signalFF10(ui->horizontalSlider->maximum()-10);
        ui->horizontalSlider->setValue(ui->horizontalSlider->maximum());
    }else{
        emit signalFF10(ui->horizontalSlider->value());
        ui->horizontalSlider->setValue(ui->horizontalSlider->value() + 10);
    }

}

void ShowForm::on_pb_FF1_clicked()
{
    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    HI_MPI_VDEC_StopRecvStream(0);
    if((ui->horizontalSlider->value() + 2) >= ui->horizontalSlider->maximum())
    {
        emit signalFF2(ui->horizontalSlider->maximum() - 2);
        ui->horizontalSlider->setValue(ui->horizontalSlider->maximum());
    }else{
        emit signalFF2(ui->horizontalSlider->value());
        ui->horizontalSlider->setValue(ui->horizontalSlider->value() + 2);
    }
}
