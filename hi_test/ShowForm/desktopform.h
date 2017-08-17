#ifndef DESKTOPFORM_H
#define DESKTOPFORM_H

#include <QWidget>
#include <QCloseEvent>
namespace Ui {
class DesktopForm;
}

class DesktopForm : public QWidget
{
    Q_OBJECT

public:
    explicit DesktopForm(QWidget *parent = 0);
    ~DesktopForm();

signals:
    void signalVideoShow(QString filepath,bool status);
    void signalSelectFile();
private slots:
    void on_pb_show_clicked();

    void on_pb_document_clicked();

private:
    Ui::DesktopForm *ui;
};

#endif // DESKTOPFORM_H
