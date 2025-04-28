//
// Created by grego on 22/04/2025.
//

#ifndef QtApp_TIMERWINDOW_H
#define QtApp_TIMERWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QResizeEvent>
#include "globalusage.h"
#include "countdownwindow.h"
#include "timerlogic.h"


QT_BEGIN_NAMESPACE
namespace Ui { class timerwindow; }
QT_END_NAMESPACE

class timerwindow : public QMainWindow {
Q_OBJECT
    friend class testtimerwindow;

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

private:
    Ui::timerwindow *ui;
    timerlogic *logic;
    QDateTime currentTime = QDateTime::currentDateTime();
    QString background = ":/Images/background1.png";
    QSize lastSize;
    QString colorlabel = "QLabel { color: white; font-weight: bold; font-size: 16px; background-color: rgba(0,0,0,160); padding:4px; border-radius:4px; }";
    QString greenbutton = "QPushButton { background-color: #4CAF50; color: white;border-radius: 8px;padding: 8px 16px;font-weight: bold;}QPushButton:hover {background-color: #66BB6A;}QPushButton:pressed {background-color: #388E3C;}";
};


#endif //TimerApp_TIMERWINDOW_H
