#include "countdownwindow.h"
#include "ui_countdownwindow.h"




countdownwindow::countdownwindow(int totalSeconds, QWidget *parent)
        : QMainWindow(parent), ui(new Ui::countdownwindow), remainingSeconds(totalSeconds), timer(new QTimer(this)), soundEffect(new QSoundEffect(this)) {
    ui->setupUi(this);
    // Inizializza il QSoundEffect
    soundEffect->setSource(QUrl::fromLocalFile("C:/Windows/Media/Windows Notify System Generic.wav")); // Usa il percorso del suono
    if (!soundEffect->source().isValid()) {
        qDebug() << "Errore nel caricamento del suono!";
    }

    //soundEffect->setSource(QUrl::fromLocalFile("sounds/alarm.wav"));   quando metto il suono
    soundEffect->setVolume(1.0);  // Imposta il volume (1.0 è massimo)

    if(!movie->isValid()){
        qDebug() << "Formato supportato?:" << QMovie::supportedFormats();
    }else {
        ui->metronomelabel->setMovie(movie);
        ui->metronomelabel->setVisible(false);  // La nascondiamo all'inizio
        //ui->metronomelabel->setMinimumSize(100, 100);  // Imposta una dimensione minima per la QLabel
        ui->metronomelabel->setScaledContents(true);
    }

    ui->stopbutton->setStyleSheet(
            "QPushButton {"
            "   background-color: #d32f2f;"        // rosso base
            "   color: white;"
            "   border-radius: 8px;"
            "   padding: 6px 12px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #f44336;"        // rosso più chiaro
            "}"
            "QPushButton:pressed {"
            "   background-color: #b71c1c;"        // rosso più scuro
            "}"
    );


    connect(timer, &QTimer::timeout, this, &countdownwindow::updateTime);
    timer->start(1000);  // ogni secondo

    updateTime();  // mostra subito il tempo iniziale

    connect(ui->stopbutton, &QPushButton::clicked, this, [=]() {
        timer->stop();
        cleanup();
        close();  // chiude la finestra (puoi anche tornare a timerwindow se vuoi)
    });
}

countdownwindow::~countdownwindow() {
    delete ui;
}

void countdownwindow::updateTime() {
    // Calcola ore, minuti e secondi
    int h = remainingSeconds / 3600;
    int m = (remainingSeconds % 3600) / 60;
    int s = remainingSeconds % 60;

    // Mostra il tempo rimanente nel formato HH:MM:SS
    ui->label_time->setText(QString("%1:%2:%3")
                                    .arg(h, 2, 10, QChar('0'))
                                    .arg(m, 2, 10, QChar('0'))
                                    .arg(s, 2, 10, QChar('0')));

    // Cambia il colore quando mancano meno di 10 secondi
    if (remainingSeconds <= 10) {
        ui->label_time->setStyleSheet("color: red;");
        if (ui->metronomelabel->movie() && ui->metronomelabel->movie()->state() != QMovie::Running) {
            ui->metronomelabel->movie()->start();  // Avvia l’animazione se non è già in corso
        }
        ui->metronomelabel->setVisible(true);  // Mostra la GIF
    } else {
        ui->label_time->setStyleSheet("color: black;");
        ui->metronomelabel->setVisible(false);  // Nascondi la GIF se mancano più di 10s
    }

    // Se il tempo è scaduto
    if (--remainingSeconds < 0) {
        timer->stop();  // Ferma il timer
        ui->label_time->setText("00:00:00");  // Mostra il tempo scaduto
        soundEffect->play();  // Riproduci il suono

        // Fai lampeggiare il timer
        QTimer::singleShot(500, this, &countdownwindow::flashTimeLabel); // Cambia il colore dopo 500ms
    }
}

// Funzione per far lampeggiare il tempo
void countdownwindow::flashTimeLabel() {
    static bool flash = false;  //impostata su false la prima volta
    flash = !flash;  //cambia a true poi false e cosi via per i flash

    if (flash) {
        ui->label_time->setStyleSheet("color: red;"); //se true scritta rossa
    } else {
        ui->label_time->setStyleSheet("color: black;"); //se false scritta nera
    }

    // Se il timer è ancora scaduto, continua a lampeggiare
    if (remainingSeconds < 0) {
        QTimer::singleShot(500, this, &countdownwindow::flashTimeLabel);
        // dopo 500 ms chiama una sola volta(singleShot) flashTimeLabel contenuta in this
    }
}
void countdownwindow::cleanup() {
    timer->stop();
    soundEffect->stop();
    delete timer;
    delete soundEffect;
}

