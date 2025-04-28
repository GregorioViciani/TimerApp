#include "timerlogic.h"
#include <QDebug>

timerlogic::timerlogic(QObject *parent)
        : QObject(parent), timer(new QTimer(this))
{
    timer->setInterval(1000);  // Imposta l'intervallo nel costruttore
    connect(timer, &QTimer::timeout, this, &timerlogic::updateCountdown);
}

void timerlogic::setTime(int totalSeconds) {
    remainingSeconds = totalSeconds;
}

void timerlogic::start() {
    if (remainingSeconds > 0 && !timer->isActive()) {
        timer->start();
        qDebug() << "Starting the timer...";
    }
}

void timerlogic::stop() {
    if (timer->isActive()) {
        timer->stop();
        remainingSeconds=0;
    }
}

int timerlogic::remainingTime() const {
    return remainingSeconds;
}

void timerlogic::updateCountdown() {
    if (remainingSeconds > 0) {
        --remainingSeconds;
        qDebug() << "Remaining seconds:" << remainingSeconds;  // Debug
        emit timeUpdated(
                remainingSeconds / 3600,
                (remainingSeconds % 3600) / 60,
                remainingSeconds % 60
        );
    }

    if (remainingSeconds == 0) {
        qDebug() << "Timer finished!";
        timer->stop();
        emit timeFinished();
    }
}
