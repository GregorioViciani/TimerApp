//
// Created by grego on 22/04/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_timerwindow.h" resolved

#include "timerwindow.h"
#include "ui_timerwindow.h"


timerwindow::timerwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::timerwindow) {
    ui->setupUi(this);

    this->setStyleSheet(
            "QMainWindow {"
            "   background-image: url(:/images/background.png);"
            "   background-repeat: no-repeat;"
            "   background-position: center;"
            "}"
    );
    ui->ringlabel->setText("L'orario corrente è: " + currentTime.toString("hh:mm"));

    connect(ui->oreslider, &QSlider::valueChanged, this, [=](int value){
        ui->orelabel->setText(QString::number(value));
        currentTime = QDateTime::currentDateTime();
        QDateTime ringtime = currentTime.addSecs(value * 3600);
        ui->ringlabel->setText("Il timer suonerà alle: " + ringtime.toString("hh:mm:ss"));
    });

    connect(ui->minslider, &QSlider::valueChanged, this, [=](int value){
        ui->minlabel->setText(QString::number(value));
        currentTime = QDateTime::currentDateTime();
        QDateTime ringtime = currentTime.addSecs(value*60);
        ui->ringlabel->setText("Il timer suonerà alle: " + ringtime.toString("hh:mm:ss"));
    });

    connect(ui->secslider, &QSlider::valueChanged, this, [=](int value){
        ui->seclabel->setText(QString::number(value));
        currentTime = QDateTime::currentDateTime();
        QDateTime ringtime = currentTime.addSecs(value);
        ui->ringlabel->setText("Il timer suonerà alle: " + ringtime.toString("hh:mm:ss"));
    });
    connect(ui->starttimer, &QPushButton::clicked, this, [=]() {
        int ore = ui->oreslider->value();
        int min = ui->minslider->value();
        int sec = ui->secslider->value();

        int total = ore * 3600 + min * 60 + sec;
        if (total == 0) {
            ui->ringlabel->setText("L'orario corrente è: " + currentTime.toString("hh:mm"));
            return;  // niente timer a 0
        }


        // Imposta il testo della QLabel per l'orario in cui il timer suonerà

        auto *countdown = new countdownwindow(total, this);
        countdown->show();
    });

    ui->starttimer->setStyleSheet (
            "QPushButton {"
            "   background-color: #4CAF50;"        // rosso base
            "   color: white;"
            "   border-radius: 8px;"
            "   padding: 8px 16px;"
            "   font-weight: bold;"
            "}"
            "QPushButton:hover {"
            "   background-color: #66BB6A;"        // rosso più chiaro
            "}"
            "QPushButton:pressed {"
            "   background-color: #388E3C;"        // rosso più scuro
            "}"
    );


}
void timerwindow::closeEvent(QCloseEvent *event) {
    QApplication::quit();  // chiude tutta l'app quando questa finestra si chiude
}
timerwindow::~timerwindow() {
    delete ui;
}
