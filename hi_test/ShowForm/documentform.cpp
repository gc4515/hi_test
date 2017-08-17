#include "documentform.h"
#include "ui_documentform.h"
#include <QWSServer>
#include <QPalette>
#include <QListWidgetItem>
#include <QListView>
#include <QDir>
#include <QFileInfoList>
#include <QPlastiqueStyle>
DocumentForm::DocumentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocumentForm)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x00));
    setPalette(pal);
    qApp->setStyle(new QPlastiqueStyle);
//    QWSServer::setBackground(QColor(0x0,0x0,0x0,0x0));
    ui->setupUi(this);
    ui->listWidget->setFlow(QListWidget::LeftToRight);
    ui->listWidget->setViewMode(QListView::IconMode);//设置Item显示模式
    ui->listWidget->setIconSize(QSize(50,50));//设置Item Icon图片大小
    ui->listWidget->setMovement(QListView::Static);//设置列表不可拖动
    ui->listWidget->setResizeMode(QListWidget::Adjust);//设置Item自动对齐
    ui->listWidget->setLayoutMode(QListWidget::Batched);
}

DocumentForm::~DocumentForm()
{
    delete ui;
}

void DocumentForm::updateDocumentForm()
{
    ui->listWidget->clear();
    QDir dir("/home");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();

//    connect(ui->listWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(slotItem(QModelIndex)));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotItem(QListWidgetItem*)));
    //ui->listWidget->setSpacing(15);
    for(int i = 0; i<list.size();i++)
    {
        QStringList stringlist = list.at(i).fileName().split("_");
        QString itemname;
        itemname.clear();
        for(int j = 0;j < stringlist.size();j++)
        {
            itemname = itemname + stringlist.at(j) +"\n";
        }
        QListWidgetItem *newItem = new QListWidgetItem(QIcon("./image/file.png"),\
                                                       itemname,ui->listWidget);
    }
}
void DocumentForm::slotItem(QListWidgetItem *item)
{
    //printf("%s\n",item->text().toLocal8Bit().data());
    QString filename = "/home/" + item->text();
    filename = filename.replace(QString("\n"),QString("_"));
    //printf("%s\n",filename.toLocal8Bit().data());
    emit signalVideoShow(filename,1);
    this->hide();
}
