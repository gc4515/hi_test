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
    QPushButton *pb_delay1;
    QPushButton *pb_delay10;
    QPushButton *pb_fast1;
    QPushButton *pb_fast10;
    QPushButton *pb_fast;
    QPushButton *pb_slow;
    QPushButton *pb_realplay;

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
        pb_delay1 = new QPushButton(ShowForm);
        pb_delay1->setObjectName(QString::fromUtf8("pb_delay1"));
        pb_delay1->setGeometry(QRect(270, 660, 30, 30));
        pb_delay1->setFocusPolicy(Qt::NoFocus);
        pb_delay1->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:3px}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/delay1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_delay1->setIcon(icon2);
        pb_delay1->setIconSize(QSize(30, 30));
        pb_delay10 = new QPushButton(ShowForm);
        pb_delay10->setObjectName(QString::fromUtf8("pb_delay10"));
        pb_delay10->setGeometry(QRect(230, 660, 30, 30));
        pb_delay10->setFocusPolicy(Qt::NoFocus);
        pb_delay10->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:3px}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/delay10.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_delay10->setIcon(icon3);
        pb_delay10->setIconSize(QSize(30, 30));
        pb_fast1 = new QPushButton(ShowForm);
        pb_fast1->setObjectName(QString::fromUtf8("pb_fast1"));
        pb_fast1->setGeometry(QRect(310, 660, 30, 30));
        pb_fast1->setFocusPolicy(Qt::NoFocus);
        pb_fast1->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:3px}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/fast1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_fast1->setIcon(icon4);
        pb_fast1->setIconSize(QSize(30, 30));
        pb_fast10 = new QPushButton(ShowForm);
        pb_fast10->setObjectName(QString::fromUtf8("pb_fast10"));
        pb_fast10->setGeometry(QRect(350, 659, 31, 31));
        pb_fast10->setFocusPolicy(Qt::NoFocus);
        pb_fast10->setStyleSheet(QString::fromUtf8("QPushButton{border-radius:3px}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/fast10.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_fast10->setIcon(icon5);
        pb_fast10->setIconSize(QSize(30, 30));
        pb_fast = new QPushButton(ShowForm);
        pb_fast->setObjectName(QString::fromUtf8("pb_fast"));
        pb_fast->setGeometry(QRect(380, 660, 31, 27));
        pb_slow = new QPushButton(ShowForm);
        pb_slow->setObjectName(QString::fromUtf8("pb_slow"));
        pb_slow->setGeometry(QRect(420, 660, 31, 27));
        pb_realplay = new QPushButton(ShowForm);
        pb_realplay->setObjectName(QString::fromUtf8("pb_realplay"));
        pb_realplay->setGeometry(QRect(460, 660, 31, 27));

        retranslateUi(ShowForm);

        QMetaObject::connectSlotsByName(ShowForm);
    } // setupUi

    void retranslateUi(QWidget *ShowForm)
    {
        ShowForm->setWindowTitle(QApplication::translate("ShowForm", "Video", 0, QApplication::UnicodeUTF8));
        pb_pause->setText(QString());
        pb_delay1->setText(QString());
        pb_delay10->setText(QString());
        pb_fast1->setText(QString());
        pb_fast10->setText(QString());
        pb_fast->setText(QApplication::translate("ShowForm", "f", 0, QApplication::UnicodeUTF8));
        pb_slow->setText(QApplication::translate("ShowForm", "s", 0, QApplication::UnicodeUTF8));
        pb_realplay->setText(QApplication::translate("ShowForm", "r", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ShowForm: public Ui_ShowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFORM_H
