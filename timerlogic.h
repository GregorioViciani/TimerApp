#ifndef TIMERLOGIC_H
#define TIMERLOGIC_H

#include <QObject>
#include <QTimer>

class timerlogic : public QObject {
Q_OBJECT
    friend class testtimerlogic;

public:
    explicit timerlogic(QObject *parent = nullptr);

    void setTime(int totalSeconds);
    void start();
    void stop();
    int remainingTime() const;

public: signals:
    void timeUpdated(int hours, int minutes, int seconds);
    void timeFinished();

private slots:
    void updateCountdown();

private:
    QTimer *timer;
    int remainingSeconds = 0;
};

#endif // TIMERLOGIC_H
