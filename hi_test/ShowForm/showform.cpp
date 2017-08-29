#include "showform.h"
#include "ui_showform.h"
#include <QWSServer>
#include <QMessageBox>
#include <QPalette>
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "vdecthread.h"
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
    max = 0;
    m_FastorSlow  = 2;
    m_timerCount = 0;
    QWSServer::setBackground(QColor(0x0,0x0,0x0,0x0));

    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(1);
    ui->horizontalSlider->setValue(0);
}

ShowForm::~ShowForm()
{
    delete ui;
}
void ShowForm::setPlayStatus(const bool &status)
{
    m_playStatus = status;
}
const bool &ShowForm::getPlayStatus()const
{
    return m_playStatus;
}
void ShowForm::mouseMoveEvent(QMouseEvent *e)
{
    signal(SIGBUS,SIG_IGN);
}
void ShowForm::mousePressEvent(QMouseEvent *e)
{
    signal(SIGBUS,SIG_IGN);
}
//关闭事件
void ShowForm::closeEvent(QCloseEvent *e)
{
//    int r = QMessageBox::question(this,trUtf8("exit"),QObject::trUtf8("确定要退出吗？"),
//                                  QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
//    if(r == QMessageBox::Yes)
//    {
        ui->label_time->clear();
        ui->label_current->clear();
        ui->horizontalSlider->setValue(0);
        max = 0;
        emit signalDesktopFormShow();
//        e->accept();
//    }else{
//        e->ignore();
//    }
}

void ShowForm::slotTimerOut()
{
    int value;
    if(getPlayStatus() == 0)//实时流播放状态
    {
        ui->label_time->setText(QString(trUtf8("%1秒").arg(QString::number(max))));
        ui->horizontalSlider->setMaximum(max++);
        if(m_videoFlag == 0)//是否暂停态
        {
            value = ui->horizontalSlider->value();
            ui->label_current->setText(QString::number(value));
            //printf("%d\n",value);
            value++;
            ui->horizontalSlider->setValue(value);
        }
    }/*     录像文件播放  */
    else{
        ui->label_time->setText(QString(trUtf8("%1 秒").arg(QString::number(VdecThread::g_Icount))));
        ui->horizontalSlider->setMaximum(VdecThread::g_Icount);
        if(m_videoFlag == 0)//是否暂停态 0:否
        {
            value = ui->horizontalSlider->value();
            ui->label_current->setText(QString::number(value));
            //printf("%d\n",value);
            if(m_FastorSlow == 0)
            {
                value+=2;
            }else if(m_FastorSlow == 1)
            {
                m_timerCount++;
                if(m_timerCount ==5)
                {
                    value++;
                    m_timerCount = 0;
                }

            }else{
                value++;
            }
            ui->horizontalSlider->setValue(value);
            value = 0;
            //printf("value: %d\n",ui->horizontalSlider->value());
        }
    }
}

// 暂停/恢复功能
void ShowForm::on_pb_pause_clicked()
{
    signal(SIGBUS,SIG_IGN);

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
    m_FastorSlow = 0;
    emit signalFastPlay();
}

//慢放
void ShowForm::on_pb_slow_clicked()
{
    m_FastorSlow = 1;
    emit signalSlowPlay();
}

//恢复实时播放
void ShowForm::on_pb_realplay_clicked()
{
    m_FastorSlow = 2;
    emit signalRealPlay();
}

//后退10S
void ShowForm::on_pb_delay10_clicked()
{
    signal(SIGBUS,SIG_IGN);
    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);

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
    signal(SIGBUS,SIG_IGN);

    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
    //HI_MPI_VDEC_StopRecvStream(0);
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
    signal(SIGBUS,SIG_IGN);

    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
//    HI_MPI_VDEC_StopRecvStream(0);
    if((ui->horizontalSlider->value() + 10) >= ui->horizontalSlider->maximum())
    {
        emit signalFF10(ui->horizontalSlider->maximum()-10,HI_TRUE);
        ui->horizontalSlider->setValue(ui->horizontalSlider->maximum());
    }else{
        emit signalFF10(ui->horizontalSlider->value(),HI_FALSE);
        ui->horizontalSlider->setValue(ui->horizontalSlider->value() + 10);
    }
}

void ShowForm::on_pb_FF1_clicked()
{
    signal(SIGBUS,SIG_IGN);

    HI_MPI_VO_ClearChnBuffer(0,0,HI_FALSE);
//    HI_MPI_VDEC_StopRecvStream(0);
    if((ui->horizontalSlider->value() + 2) >= ui->horizontalSlider->maximum())
    {
        emit signalFF2(ui->horizontalSlider->maximum() - 3,HI_TRUE);
        ui->horizontalSlider->setValue(ui->horizontalSlider->maximum());
    }else{
        emit signalFF2(ui->horizontalSlider->value(),HI_FALSE);
        ui->horizontalSlider->setValue(ui->horizontalSlider->value() + 2);
    }
}
