#include "globalusage.h"
#include "timerwindow.h"
#include "ui_timerwindow.h"

#include <QApplication>
#include <QSlider>
#include <QPushButton>

timerwindow::timerwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::timerwindow) {
    ui->setupUi(this);

    logic = new timerlogic(this);
    connect(logic, &timerlogic::timeFinished, this, &timerwindow::onTimerFinished);
    connect(logic, &timerlogic::timeUpdated, this, &timerwindow::onTimerUpdated);

    // Connessione degli slider a un'unica funzione per aggiornare l'etichetta
    connect(ui->oreslider, &QSlider::valueChanged, this, &timerwindow::updateLabelAndPreview);
    connect(ui->minslider, &QSlider::valueChanged, this, &timerwindow::updateLabelAndPreview);
    connect(ui->secslider, &QSlider::valueChanged, this, &timerwindow::updateLabelAndPreview);

    connect(ui->starttimer, &QPushButton::clicked, this, [=]() {
        int total = getTotalTimeInSeconds();
        logic->setTime(total);
        logic->start();

        if (total == 0) {
            currentTime = QDateTime::currentDateTime();
            ui->ringlabel->setText("L'orario corrente è: " + currentTime.toString("hh:mm"));
            return;  // niente timer a 0
        }

        // Imposta il testo della QLabel per l'orario in cui il timer suonerà
        auto *countdown = new countdownwindow(total, this);
        countdown->show();

        connect(countdown, &countdownwindow::countdownClosed, this, &timerwindow::resetTimer);
        connect(ui->returnbutton, &QPushButton::clicked, this, &timerwindow::on_returnbutton_clicked);

    });
    resizeAndSetBackgroundImage(this, background);
    ui->ringlabel->setText("L'orario corrente è: " + currentTime.toString("hh:mm"));

}
timerwindow::~timerwindow() {
    delete ui;
}
void timerwindow::closeEvent(QCloseEvent *event) {
    QApplication::quit();  // chiude tutta l'app quando questa finestra si chiude
}

void timerwindow::resizeEvent(QResizeEvent *event) {
    if (event->size() != lastSize) {
        resizeAndSetBackgroundImage(this, background);
        lastSize = event->size();
    }
    QMainWindow::resizeEvent(event);
}

void timerwindow::onTimerUpdated(int h, int m, int s) {
    QString timeString = QString("%1:%2:%3")
            .arg(h, 2, 10, QChar('0'))
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'));

    ui->ringlabel->setText("Tempo rimanente: " + timeString);
}

void timerwindow::onTimerFinished() {
    //QMessageBox::information(this, "Timer", "Tempo scaduto!");
}

void timerwindow::updateRingLabelPreview() {
    int total = getTotalTimeInSeconds();
    QDateTime ringtime = QDateTime::currentDateTime().addSecs(total);
    ui->ringlabel->setText("Il timer suonerà alle: " + ringtime.toString("hh:mm:ss"));
}

int timerwindow::getTotalTimeInSeconds() {
    int ore = ui->oreslider->value();
    int min = ui->minslider->value();
    int sec = ui->secslider->value();
    return ore * 3600 + min * 60 + sec;
}

// Funzione per aggiornare le etichette e la preview
void timerwindow::updateLabelAndPreview(int value) {
    // Determina quale slider ha inviato il segnale e aggiorna l'etichetta corretta
    if (sender() == ui->oreslider) {
        ui->orelabel->setText(QString::number(value));
    } else if (sender() == ui->minslider) {
        ui->minlabel->setText(QString::number(value));
    } else if (sender() == ui->secslider) {
        ui->seclabel->setText(QString::number(value));
    }
    // Aggiorna la preview del tempo
    updateRingLabelPreview();
}
void timerwindow::resetTimer() {
    ui->ringlabel->setText("L'orario corrente è: " + QDateTime::currentDateTime().toString("hh:mm"));
    ui->ringlabel->setStyleSheet(colorlabelblack);
    ui->oreslider->setValue(0);
    ui->minslider->setValue(0);
    ui->secslider->setValue(0);

}
void timerwindow::stopTimer() {
    logic->stop();  // Ferma il timer
    updateLabelAndPreview(0);  // Reset del display
    ui->ringlabel->setText("L'orario corrente è: " + QDateTime::currentDateTime().toString("hh:mm:ss"));
    ui->ringlabel->setStyleSheet(colorlabelblack);  // Ripristina il colore originale

    disconnect(logic, &timerlogic::timeUpdated, this, &timerwindow::onTimerUpdated);
}


void timerwindow::on_returnbutton_clicked() {
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->hide();  // invece di close(), se vuoi riutilizzare timerwindow più avanti
}
