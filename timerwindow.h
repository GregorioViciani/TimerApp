//
// Created by grego on 22/04/2025.
//

#ifndef QtApp_TIMERWINDOW_H
#define QtApp_TIMERWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include "countdownwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class timerwindow; }
QT_END_NAMESPACE

class timerwindow : public QMainWindow {
Q_OBJECT

public:
    explicit timerwindow(QWidget *parent = nullptr);

    ~timerwindow() override;

private slots:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::timerwindow *ui;
    QDateTime currentTime = QDateTime::currentDateTime();

};


#endif //TimerApp_TIMERWINDOW_H
