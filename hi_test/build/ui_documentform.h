/********************************************************************************
** Form generated from reading UI file 'documentform.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTFORM_H
#define UI_DOCUMENTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentForm
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;

    void setupUi(QWidget *DocumentForm)
    {
        if (DocumentForm->objectName().isEmpty())
            DocumentForm->setObjectName(QString::fromUtf8("DocumentForm"));
        DocumentForm->setEnabled(true);
        DocumentForm->resize(568, 571);
        gridLayout = new QGridLayout(DocumentForm);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(DocumentForm);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 68, 68);"));
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setMovement(QListView::Static);
        listWidget->setLayoutMode(QListView::Batched);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setSortingEnabled(true);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);


        retranslateUi(DocumentForm);

        QMetaObject::connectSlotsByName(DocumentForm);
    } // setupUi

    void retranslateUi(QWidget *DocumentForm)
    {
        DocumentForm->setWindowTitle(QApplication::translate("DocumentForm", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DocumentForm: public Ui_DocumentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTFORM_H
