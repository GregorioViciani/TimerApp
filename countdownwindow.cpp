#include "countdownwindow.h"
#include "ui_countdownwindow.h"
#include "globalusage.h"
#include "timerwindow.h"

#include <QFile>
#include <QDebug>
#include <QPushButton>

countdownwindow::countdownwindow(int totalSeconds, QWidget *parent)
        : QMainWindow(parent), ui(new Ui::countdownwindow),
          ringsound(new QSoundEffect(this)), metronomesound(new QSoundEffect(this)),
          movie(nullptr) {

    ui->setupUi(this);

    // Imposta suono di fine timer
    if (QFile::exists(ringsoundPath)) {
        ringsound->setSource(QUrl::fromLocalFile(ringsoundPath));
        ringsound->setVolume(0.3f);
        ringsound->setLoopCount(QSoundEffect::Infinite);
    }

    if (QFile::exists(metronomesoundPath)) {
        metronomesound->setSource(QUrl::fromLocalFile(metronomesoundPath));
        metronomesound->setVolume(0.1f); // Imposta il volume a 0.5
        metronomesound->setLoopCount(1);
    }

    // Inizializza QMovie se il formato è valido
    if (QMovie::supportedFormats().contains("gif")) {
        movie = new QMovie(gifPath);
        if (movie && movie->isValid()) {
            ui->metronomelabel->setMovie(movie);
            ui->metronomelabel->setVisible(false);  // Label nascosta all'inizio
            ui->metronomelabel->setScaledContents(true);
        }
    }
    // Inizializza il timer
    logic = new timerlogic(this);
    logic->setTime(totalSeconds);
    updateTimeDisplay(totalSeconds);
    logic->start();

    // Collegamenti per aggiornare il tempo
    connect(logic, &timerlogic::timeUpdated, this, [=](int h, int m, int s){
        const QString timeText = QString("%1:%2:%3")
                .arg(h, 2, 10, QChar('0'))
                .arg(m, 2, 10, QChar('0'))
                .arg(s, 2, 10, QChar('0'));
        ui->label_time->setText(timeText);
        if (logic->remainingTime() <= 10) {
            ui->label_time->setStyleSheet("color: red;");
            ui->metronomelabel->setVisible(true);
            if(!metronomesound->isPlaying()) { metronomesound->play();}
            if (movie && movie->isValid() && movie->state() != QMovie::Running) {movie->start();}
        } else {
            ui->label_time->setStyleSheet("color: black;");
        }
    });
    // Quando il timer finisce
    connect(logic, &timerlogic::timeFinished, this, [=]() {
        ui->label_time->setText("00:00:00");
        ui->label_time->setStyleSheet("color: red;");
        if (movie && movie->isValid() && movie->state() == QMovie::Running) {movie->stop();}
        if(metronomesound->isPlaying()) { metronomesound->stop();}

        if (ringsound && !ringsound->isPlaying()) {ringsound->play();}
        flashTimeLabel();
    });

    // Pulsante STOP
    connect(ui->stopbutton, &QPushButton::clicked, this, [=]() {
        logic->stop();
        updateTimeDisplay(0);
        if (metronomesound->isPlaying()) {
            metronomesound->stop();
        }
        if (ringsound->isPlaying()) {
            ringsound->stop();
        }

        // Qui invece di close(), chiamiamo stopTimer in timerwindow
        if (parentWidget()) {
            auto *parentWindow = qobject_cast<timerwindow *>(parentWidget());
            if (parentWindow) {
                parentWindow->stopTimer();  // Ferma il timer e resetta il display
            }
        }
        emit countdownClosed();
        this->hide(); // Nascondi countdownwindow
    });


}

countdownwindow::~countdownwindow() {
    cleanup();
}

void countdownwindow::closeEvent(QCloseEvent *event) {
    cleanup();
    emit countdownClosed();
    QMainWindow::closeEvent(event);
}


void countdownwindow::updateTimeDisplay(int secondsRemaining) {
    int hours = secondsRemaining / 3600;
    int minutes = (secondsRemaining % 3600) / 60;
    int seconds = secondsRemaining % 60;

    ui->label_time->setText(QString::asprintf("%02d:%02d:%02d", hours, minutes, seconds));
}

// Funzione per far lampeggiare il tempo rosso e nero
void countdownwindow::flashTimeLabel() {
    static bool flash = false;
    flash = !flash;

    ui->label_time->setStyleSheet(flash ? "color: red;" : "color: black;");

    if (logic->remainingTime() <= 0) {
        QTimer::singleShot(500, this, &countdownwindow::flashTimeLabel);
    }
}
void countdownwindow::resizeEvent(QResizeEvent *event) {
    if (event->size() != lastSize) {
        resizeAndSetBackgroundImage(this, background);
        lastSize = event->size();
    }
    QMainWindow::resizeEvent(event);
}
void countdownwindow::cleanup() {

    if (metronomesound->isPlaying()) {
        metronomesound->stop();
    }
    if (ringsound->isPlaying()) {
        ringsound->stop();
    }

    disconnect(logic, &timerlogic::timeUpdated, this, nullptr);
    disconnect(logic, &timerlogic::timeFinished, this, nullptr);
    disconnect(ui->stopbutton, &QPushButton::clicked, this, nullptr);

    delete metronomesound;
    delete ringsound;
}
