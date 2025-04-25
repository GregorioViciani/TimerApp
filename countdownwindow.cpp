#include "countdownwindow.h"
#include "ui_countdownwindow.h"
#include "globalusage.h"
#include <QFile>
#include <QDebug>

countdownwindow::countdownwindow(int totalSeconds, QWidget *parent)
        : QMainWindow(parent), ui(new Ui::countdownwindow),
          ringsound(new QSoundEffect(this)), metronomesound(new QSoundEffect(this)),
          movie(nullptr) {

    ui->setupUi(this);

    // Imposta suono di fine timer
    if (QFile::exists("Sounds/ringsound.wav")) {
        ringsound->setSource(QUrl::fromLocalFile("Sounds/ringsound.wav"));
        ringsound->setVolume(0.3f);
        ringsound->setLoopCount(QSoundEffect::Infinite);
    } else {
        qDebug() << "Errore nel caricamento della sveglia!";
    }

    if (QFile::exists("Sounds/metronomesound.wav")) {
        metronomesound->setSource(QUrl::fromLocalFile("Sounds/metronomesound.wav"));
        metronomesound->setVolume(0.1f); // Imposta il volume a 0.5
        metronomesound->setLoopCount(1);
    } else {
        qDebug() << "Errore nel caricamento del metronomo!";
    }

    // Inizializza QMovie se il formato è valido
    if (QMovie::supportedFormats().contains("gif")) {
        movie = new QMovie(gifPath);
        if (movie && movie->isValid()) {
            ui->metronomelabel->setMovie(movie);
            ui->metronomelabel->setVisible(false);  // Label nascosta all'inizio
            ui->metronomelabel->setScaledContents(true);
        } else {
            qDebug() << "Formato GIF non valido o non supportato.";
        }
    }

    // Stile del pulsante stop
    ui->stopbutton->setStyleSheet(
            "QPushButton { background-color: #d32f2f; color: white; border-radius: 8px; padding: 6px 12px; }"
            "QPushButton:hover { background-color: #f44336; }"
            "QPushButton:pressed { background-color: #b71c1c; }"
    );

    // Inizializza il timer
    logic = new timerlogic(this);
    logic->setTime(totalSeconds);
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
        // Suono
        if (ringsound && !ringsound->isPlaying()) {ringsound->play();}
        flashTimeLabel();
    });

    // Pulsante STOP
    connect(ui->stopbutton, &QPushButton::clicked, this, [=]() {
        logic->stop();
        delete ringsound;
        close();
    });
}

countdownwindow::~countdownwindow() {
    logic->stop();
    delete ui;
}

// Funzione per far lampeggiare il tempo
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
