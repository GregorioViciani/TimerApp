#ifndef QtApp_COUNTDOWNWINDOW_H
#define QtApp_COUNTDOWNWINDOW_H

#include "timerlogic.h"

#include <QMainWindow>
#include <QTimer>
#include <QSoundEffect>
#include <QMovie>
#include <QFile>
#include <QString>
#include <QDir>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class countdownwindow; }
QT_END_NAMESPACE

class countdownwindow : public QMainWindow {
Q_OBJECT
    friend class testcountdownwindow;  // Permette l'accesso ai membri privati nella classe di test

public:
    explicit countdownwindow(int totalSeconds, QWidget *parent = nullptr);
    ~countdownwindow() override;

signals:
    void countdownClosed();

private slots:
    void flashTimeLabel();
    void resizeEvent(QResizeEvent *event) override;
    void updateTimeDisplay(int secondsRemaining);
    void closeEvent(QCloseEvent *event) override;
    void cleanup();


private:
    Ui::countdownwindow *ui;
    timerlogic *logic;
    QSoundEffect *ringsound;
    QSoundEffect *metronomesound;
    QMovie *movie;
    QString gifPath = ":/Images/Metronome.gif";
    QString background = ":/Images/background2.jpg";
    QString ringsoundPath = ":/Sounds/ringsound.wav";
    QString metronomesoundPath = ":/Sounds/metronomesound.wav";
    QSize lastSize;
};

#endif // QtApp_COUNTDOWNWINDOW_H
