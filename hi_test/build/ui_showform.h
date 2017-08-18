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
        pb_pause->setEnabled(true);
        pb_pause->setGeometry(QRect(190, 660, 30, 30));
        pb_pause->setFocusPolicy(Qt::NoFocus);
        pb_pause->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:3px}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_pause->setIcon(icon1);
        pb_pause->setIconSize(QSize(30, 30));
        pb_pause->setAutoRepeatDelay(300);
        pb_pause->setAutoRepeatInterval(100);
        pb_pause->setAutoDefault(false);
        pb_pause->setFlat(false);
        pb_resume = new QPushButton(ShowForm);
        pb_resume->setObjectName(QString::fromUtf8("pb_resume"));
        pb_resume->setGeometry(QRect(230, 660, 30, 30));
        pb_resume->setFocusPolicy(Qt::NoFocus);
        pb_resume->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:3px}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/slow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_resume->setIcon(icon2);
        pb_resume->setIconSize(QSize(30, 30));

        retranslateUi(ShowForm);

        QMetaObject::connectSlotsByName(ShowForm);
    } // setupUi

    void retranslateUi(QWidget *ShowForm)
    {
        ShowForm->setWindowTitle(QApplication::translate("ShowForm", "Video", 0, QApplication::UnicodeUTF8));
        pb_pause->setText(QString());
        pb_resume->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShowForm: public Ui_ShowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFORM_H
