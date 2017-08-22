#ifndef SHOWFORM_H
#define SHOWFORM_H
#include "chead.h"
#include <QWidget>
#include <QCloseEvent>
#include <QTimer>

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
    void signalFastPlay();
    void signalSlowPlay();
    void signalRealPlay();
private slots:
    void slotTimerOut();
    void on_pb_pause_clicked();

    void on_pb_fast_clicked();

    void on_pb_slow_clicked();

    void on_pb_realplay_clicked();

private:
    int max;
    Ui::ShowForm *ui;
    bool m_videoFlag;//0:play 1:pause
    int m_status;
    QTimer *m_timer;
};

#endif // SHOWFORM_H
