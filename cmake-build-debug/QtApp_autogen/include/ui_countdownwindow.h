/********************************************************************************
** Form generated from reading UI file 'countdownwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDOWNWINDOW_H
#define UI_COUNTDOWNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_countdownwindow
{
public:
    QWidget *centralwidget;
    QLabel *label_time;
    QPushButton *stopbutton;
    QLabel *metronomelabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *countdownwindow)
    {
        if (countdownwindow->objectName().isEmpty())
            countdownwindow->setObjectName("countdownwindow");
        countdownwindow->resize(610, 485);
        centralwidget = new QWidget(countdownwindow);
        centralwidget->setObjectName("centralwidget");
        label_time = new QLabel(centralwidget);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(250, 280, 101, 61));
        label_time->setAutoFillBackground(false);
        label_time->setLineWidth(1);
        label_time->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stopbutton = new QPushButton(centralwidget);
        stopbutton->setObjectName("stopbutton");
        stopbutton->setGeometry(QRect(250, 350, 101, 51));
        stopbutton->setStyleSheet(QString::fromUtf8("ui->stopbutton->setStyleSheet(\n"
"    \"QPushButton {\"\n"
"    \"   background-color: #d32f2f;\"        // rosso base\n"
"    \"   color: white;\"\n"
"    \"   border-radius: 8px;\"\n"
"    \"   padding: 6px 12px;\"\n"
"    \"}\"\n"
"    \"QPushButton:hover {\"\n"
"    \"   background-color: #f44336;\"      \n"
"    \"}\"\n"
"    \"QPushButton:pressed {\"\n"
"    \"   background-color: #b71c1c;\"        \n"
"    \"}\"\n"
");\n"
""));
        metronomelabel = new QLabel(centralwidget);
        metronomelabel->setObjectName("metronomelabel");
        metronomelabel->setGeometry(QRect(160, 20, 321, 261));
        metronomelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        countdownwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(countdownwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 610, 33));
        countdownwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(countdownwindow);
        statusbar->setObjectName("statusbar");
        countdownwindow->setStatusBar(statusbar);

        retranslateUi(countdownwindow);

        QMetaObject::connectSlotsByName(countdownwindow);
    } // setupUi

    void retranslateUi(QMainWindow *countdownwindow)
    {
        countdownwindow->setWindowTitle(QCoreApplication::translate("countdownwindow", "countdownwindow", nullptr));
        label_time->setText(QCoreApplication::translate("countdownwindow", "0", nullptr));
        stopbutton->setText(QCoreApplication::translate("countdownwindow", "Stop", nullptr));
        metronomelabel->setText(QCoreApplication::translate("countdownwindow", "Metronome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class countdownwindow: public Ui_countdownwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDOWNWINDOW_H
