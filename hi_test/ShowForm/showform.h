#ifndef SHOWFORM_H
#define SHOWFORM_H
#include "chead.h"
#include <QWidget>
#include <QCloseEvent>
namespace Ui {
class ShowForm;
}

class ShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShowForm(QWidget *parent = 0);
    ~ShowForm();
    void closeEvent(QCloseEvent *e);

signals:
    void signalPause();
    void signalResume();
    void signalDesktopFormShow();
private slots:
    void on_pb_pause_clicked();

    void on_pb_resume_clicked();

private:
    Ui::ShowForm *ui;

    int m_status;
};

#endif // SHOWFORM_H
