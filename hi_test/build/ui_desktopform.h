/********************************************************************************
** Form generated from reading UI file 'desktopform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKTOPFORM_H
#define UI_DESKTOPFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesktopForm
{
public:
    QPushButton *pb_show;
    QPushButton *pb_document;

    void setupUi(QWidget *DesktopForm)
    {
        if (DesktopForm->objectName().isEmpty())
            DesktopForm->setObjectName(QString::fromUtf8("DesktopForm"));
        DesktopForm->resize(685, 510);
        pb_show = new QPushButton(DesktopForm);
        pb_show->setObjectName(QString::fromUtf8("pb_show"));
        pb_show->setGeometry(QRect(20, 20, 50, 50));
        pb_show->setFocusPolicy(Qt::NoFocus);
        pb_show->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_show->setIcon(icon);
        pb_show->setIconSize(QSize(60, 50));
        pb_show->setAutoDefault(false);
        pb_show->setFlat(true);
        pb_document = new QPushButton(DesktopForm);
        pb_document->setObjectName(QString::fromUtf8("pb_document"));
        pb_document->setGeometry(QRect(20, 100, 50, 50));
        pb_document->setFocusPolicy(Qt::NoFocus);
        pb_document->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_document->setIcon(icon1);
        pb_document->setIconSize(QSize(60, 50));
        pb_document->setAutoDefault(false);
        pb_document->setDefault(false);
        pb_document->setFlat(true);

        retranslateUi(DesktopForm);

        QMetaObject::connectSlotsByName(DesktopForm);
    } // setupUi

    void retranslateUi(QWidget *DesktopForm)
    {
        DesktopForm->setWindowTitle(QApplication::translate("DesktopForm", "Form", 0, QApplication::UnicodeUTF8));
        pb_show->setText(QString());
        pb_show->setShortcut(QString());
        pb_document->setText(QString());
        pb_document->setShortcut(QString());
    } // retranslateUi

};

namespace Ui {
    class DesktopForm: public Ui_DesktopForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKTOPFORM_H
