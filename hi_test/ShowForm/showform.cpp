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
    //this->setAttribute(Qt::WA_TranslucentBackground,true);
    QWSServer::setBackground(QColor(0x0,0x0,0x0,0x0));

    ui->setupUi(this);
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

void ShowForm::on_pb_pause_clicked()
{

    emit signalPause();
}

void ShowForm::on_pb_resume_clicked()
{
    emit signalResume();
}
