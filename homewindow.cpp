//
// Created by grego on 22/04/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_homewindow.h" resolved

#include "homewindow.h"
#include "ui_homewindow.h"



homewindow::homewindow(QWidget *parent) :
        QMainWindow(parent)
        , ui(new Ui::homewindow)
        , timerwin(nullptr) {
    ui->setupUi(this);
    connect(ui->timerbutton, &QPushButton::clicked, this, &homewindow::on_timerbutton_clicked);
}
homewindow::~homewindow() {
    delete ui;
}
void homewindow::on_timerbutton_clicked() {
    if (!timerwin) {
        timerwin = new timerwindow(this);  // o senza `this` se vuoi una finestra separata
    }
    timerwin->show();
    this->hide();  // nascondi la home se vuoi solo mostrare la nuova
}