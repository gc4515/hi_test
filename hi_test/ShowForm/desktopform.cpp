#include "desktopform.h"
#include "ui_desktopform.h"
#include <QWSServer>
#include <QFileDialog>
#include <QMessageBox>
#include <QPalette>

DesktopForm::DesktopForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DesktopForm)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x80));
    setPalette(pal);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground,true);
    QWSServer::setBackground(QColor(0x0,0x0,0x0,0x0));

    ui->setupUi(this);
}

DesktopForm::~DesktopForm()
{
    delete ui;
}

void DesktopForm::on_pb_show_clicked()
{
    emit signalVideoShow("",0);//发送实时播放信号，切换至实时画面
}

void DesktopForm::on_pb_document_clicked()
{
    emit signalSelectFile();
//    QString filepath = QFileDialog::getOpenFileName(this,trUtf8("open file"),trUtf8("/home"),\
//                                                    trUtf8("Video file(*.h264)"));
//    if(filepath.size() == 0)
//    {
//        //QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."));
//    }else{
//        //QMessageBox::information(NULL, tr("Path"), tr("You selected ") + filepath);
//        emit signalVideoShow(filepath,1);
//    }
}
