#ifndef QtApp_COUNTDOWNWINDOW_H
#define QtApp_COUNTDOWNWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSoundEffect>
#include <QMovie>
#include <QFile>
#include <QString>
#include <QDir>


QT_BEGIN_NAMESPACE
namespace Ui { class countdownwindow; }
QT_END_NAMESPACE

class countdownwindow : public QMainWindow {
Q_OBJECT

public:
    explicit countdownwindow(int totalSeconds, QWidget *parent = nullptr);
    ~countdownwindow() override;

private slots:
    void updateTime();
    void flashTimeLabel();
    void cleanup();

private:
    Ui::countdownwindow *ui;
    QTimer *timer;
    int remainingSeconds;
    QSoundEffect *soundEffect;

    QString gifPath = ":/Gif/Metronome.gif";
    QMovie *movie = new QMovie(gifPath);
};

#endif
