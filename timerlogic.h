#ifndef TIMERLOGIC_H
#define TIMERLOGIC_H

#include <QObject>
#include <QTimer>
#include <QMessageBox>

class timerlogic : public QObject {
Q_OBJECT

public:
    explicit timerlogic(QObject *parent = nullptr);

    void setTime(int totalSeconds);
    void start();
    void stop();
    int remainingTime() const;

signals:
    void timeUpdated(int hours, int minutes, int seconds);
    void timeFinished();

private slots:
    void updateCountdown();

private:
    int remainingSeconds = 0;
    QTimer *timer;
};

#endif // TIMERLOGIC_H
