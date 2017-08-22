#include "showform.h"
#include "ui_showform.h"
#include <QWSServer>
#include <QMessageBox>
#include <QPalette>

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

void ShowForm::closeEvent(QCloseEvent *e)
{
    int r = QMessageBox::question(this,tr("exit"),QObject::trUtf8("确定要退出吗？"),
                                  QMessageBox::Yes|QMessageBox::Default,QMessageBox::No|QMessageBox::Escape);
    if(r == QMessageBox::Yes)
    {
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
    //printf("%d\n",value);
    value+=1;
    ui->horizontalSlider->setValue(value);
}

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


void ShowForm::on_pb_fast_clicked()
{
    emit signalFastPlay();
}

void ShowForm::on_pb_slow_clicked()
{
    emit signalSlowPlay();
}

void ShowForm::on_pb_realplay_clicked()
{
    emit signalRealPlay();
}

