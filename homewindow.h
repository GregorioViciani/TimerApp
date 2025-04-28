
#ifndef QtApp_HOMEWINDOW_H
#define QtApp_HOMEWINDOW_H

#include "globalusage.h"
#include "timerwindow.h"

#include <QMainWindow>
#include <QPixmap>
#include <QPalette>
#include <QResizeEvent>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class homewindow; }
QT_END_NAMESPACE

class homewindow : public QMainWindow {
    Q_OBJECT
    friend class testhomewindow;  // Permette l'accesso ai membri privati nella classe di test

public:
    explicit homewindow(QWidget *parent = nullptr);

    ~homewindow() override;

private slots:
    void on_timerbutton_clicked();
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override ;
    void on_closebutton_clicked();

private:
    Ui::homewindow *ui;
    timerwindow* timerwin;
    QString background = ":/Images/background1.png";
    QSize lastSize;
};


#endif //C___HOMEWINDOW_H
