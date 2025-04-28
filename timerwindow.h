

#ifndef QtApp_TIMERWINDOW_H
#define QtApp_TIMERWINDOW_H

#include "globalusage.h"
#include "countdownwindow.h"
#include "timerlogic.h"

#include <QMainWindow>
#include <QDateTime>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class timerwindow; }
QT_END_NAMESPACE

class timerwindow : public QMainWindow {
Q_OBJECT
    friend class testtimerwindow;
    friend class countdownwindow;

public:
    explicit timerwindow(QWidget *parent = nullptr);

    ~timerwindow() override;

private slots:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void onTimerFinished();
    void onTimerUpdated(int h, int m, int s);
    void updateRingLabelPreview();
    int getTotalTimeInSeconds();
    void updateLabelAndPreview(int value);
    void resetTimer();
    void stopTimer();
    void on_returnbutton_clicked();

private:
    Ui::timerwindow *ui;
    timerlogic *logic;
    QDateTime currentTime = QDateTime::currentDateTime();
    QString background = ":/Images/background1.png";
    QSize lastSize;
    QString colorlabelblack = "QLabel { color: white; font-weight: bold; font-size: 16px; background-color: rgba(0, 0, 0, 160); padding: 8px; border-radius: 6px; border: 2px solid rgba(170, 0, 255, 0.7);}";
};


#endif //TimerApp_TIMERWINDOW_H
