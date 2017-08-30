#ifndef SHOWFORM_H
#define SHOWFORM_H
#include "chead.h"
#include <QWidget>
#include <QCloseEvent>
#include <QTimer>
#include <QMouseEvent>
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
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void setPlayStatus(const bool &status);
    const bool &getPlayStatus()const;
    void setMaxSeconds();
signals:
    void signalPause();
    void signalResume();
    void signalDesktopFormShow();
    void signalFastPlay();
    void signalSlowPlay();
    void signalRealPlay();
    void signalDelay10(int value);
    void signalDelay2(int value);
    void signalFF10(int value,bool realPlay);
    void signalFF2(int value,bool realPlay);
    void signalSliderReleased(int value);
private slots:
    void slotTimerOut();
    void on_pb_pause_clicked();

    void on_pb_fast_clicked();

    void on_pb_slow_clicked();

    void on_pb_realplay_clicked();

    void on_pb_delay10_clicked();

    void on_pb_delay1_clicked();

    void on_pb_FF10_clicked();

    void on_pb_FF1_clicked();
    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderReleased();

private:
    int max;
    Ui::ShowForm *ui;
    int m_FastorSlow;//0:fast 1:slow
    bool m_videoFlag;//0:play 1:pause
    bool m_playStatus;//0:realPlay 1: filePlay
    QTimer *m_timer;
    int m_timerCount;
};

#endif // SHOWFORM_H
