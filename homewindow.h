//
// Created by grego on 22/04/2025.
//

#ifndef QtApp_HOMEWINDOW_H
#define QtApp_HOMEWINDOW_H

#include <QMainWindow>
#include "timerwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class homewindow; }
QT_END_NAMESPACE

class homewindow : public QMainWindow {
    Q_OBJECT

public:
    explicit homewindow(QWidget *parent = nullptr);

    ~homewindow() override;

private slots:
    void on_timerbutton_clicked();

private:
    Ui::homewindow *ui;
    timerwindow* timerwin;
};


#endif //C___HOMEWINDOW_H
