/********************************************************************************
** Form generated from reading UI file 'showform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWFORM_H
#define UI_SHOWFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowForm
{
public:
    QPushButton *pb_pause;
    QPushButton *pb_resume;

    void setupUi(QWidget *ShowForm)
    {
        if (ShowForm->objectName().isEmpty())
            ShowForm->setObjectName(QString::fromUtf8("ShowForm"));
        ShowForm->resize(1280, 690);
        ShowForm->setMinimumSize(QSize(1260, 690));
        ShowForm->setMaximumSize(QSize(1280, 690));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        ShowForm->setWindowIcon(icon);
        ShowForm->setStyleSheet(QString::fromUtf8(""));
        pb_pause = new QPushButton(ShowForm);
        pb_pause->setObjectName(QString::fromUtf8("pb_pause"));
        pb_pause->setGeometry(QRect(610, 660, 60, 30));
        pb_pause->setStyleSheet(QString::fromUtf8(""));
        pb_resume = new QPushButton(ShowForm);
        pb_resume->setObjectName(QString::fromUtf8("pb_resume"));
        pb_resume->setGeometry(QRect(680, 660, 60, 30));

        retranslateUi(ShowForm);

        QMetaObject::connectSlotsByName(ShowForm);
    } // setupUi

    void retranslateUi(QWidget *ShowForm)
    {
        ShowForm->setWindowTitle(QApplication::translate("ShowForm", "Video", 0, QApplication::UnicodeUTF8));
        pb_pause->setText(QApplication::translate("ShowForm", "pause", 0, QApplication::UnicodeUTF8));
        pb_resume->setText(QApplication::translate("ShowForm", "resume", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShowForm: public Ui_ShowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFORM_H
