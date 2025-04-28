#include "globalusage.h"
#include "homewindow.h"
#include "ui_homewindow.h"

homewindow::homewindow(QWidget *parent) :
        QMainWindow(parent)
        , ui(new Ui::homewindow)
        , timerwin(nullptr) {
    ui->setupUi(this);
    resizeAndSetBackgroundImage(this, background);
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
void homewindow::on_closebutton_clicked() {
    close();
}

void homewindow::closeEvent(QCloseEvent *event) {
    QApplication::quit();  // chiude tutta l'app quando questa finestra si chiude
}

void homewindow::resizeEvent(QResizeEvent *event) {
    if (event->size() != lastSize) {
        resizeAndSetBackgroundImage(this, background);
        lastSize = event->size();
    }
    QMainWindow::resizeEvent(event);
}
