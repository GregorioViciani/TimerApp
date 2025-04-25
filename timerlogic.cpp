#include "timerlogic.h"

timerlogic::timerlogic(QObject *parent)
        : QObject(parent), timer(new QTimer(this)) {
    connect(timer, &QTimer::timeout, this, &timerlogic::updateCountdown);
}

void timerlogic::setTime(int totalSeconds) {
    remainingSeconds = totalSeconds;
}

void timerlogic::start() {
    if (remainingSeconds > 0) {
        timer->start(1000);
    }
}

void timerlogic::stop() {
    timer->stop();
}

int timerlogic::remainingTime() const {
    return remainingSeconds;
}

void timerlogic::updateCountdown() {
    if (remainingSeconds <= 0) {
        timer->stop();
        emit timeFinished();
        return;
    }

    remainingSeconds--;

    int h = remainingSeconds / 3600;
    int m = (remainingSeconds % 3600) / 60;
    int s = remainingSeconds % 60;

    emit timeUpdated(h, m, s);

    if (remainingSeconds == 0) {
        emit timeFinished();
    }
}
