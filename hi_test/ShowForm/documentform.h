#ifndef DOCUMENTFORM_H
#define DOCUMENTFORM_H

#include <QWidget>
#include <QModelIndex>
#include <QListWidgetItem>
namespace Ui {
class DocumentForm;
}

class DocumentForm : public QWidget
{
    Q_OBJECT

public:
    explicit DocumentForm(QWidget *parent = 0);
    ~DocumentForm();
    void updateDocumentForm();
signals:
    void signalVideoShow(QString filepath,bool status);
public slots:
   // void slotSelectFile();
    void slotItem(QListWidgetItem *item);

private:
    Ui::DocumentForm *ui;
};

#endif // DOCUMENTFORM_H
