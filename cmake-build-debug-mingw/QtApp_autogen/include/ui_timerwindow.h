/********************************************************************************
** Form generated from reading UI file 'timerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMERWINDOW_H
#define UI_TIMERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_timerwindow
{
public:
    QWidget *centralwidget;
    QSlider *oreslider;
    QSlider *minslider;
    QSlider *secslider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *orelabel;
    QLabel *minlabel;
    QLabel *seclabel;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QPushButton *starttimer;
    QLabel *ringlabel;
    QMenuBar *menubar;
    QMenu *menuTimer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *timerwindow)
    {
        if (timerwindow->objectName().isEmpty())
            timerwindow->setObjectName("timerwindow");
        timerwindow->resize(610, 485);
        timerwindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #66BB6A;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;\n"
"}\n"
""));
        centralwidget = new QWidget(timerwindow);
        centralwidget->setObjectName("centralwidget");
        oreslider = new QSlider(centralwidget);
        oreslider->setObjectName("oreslider");
        oreslider->setGeometry(QRect(50, 90, 20, 100));
        oreslider->setMaximum(23);
        oreslider->setOrientation(Qt::Orientation::Vertical);
        minslider = new QSlider(centralwidget);
        minslider->setObjectName("minslider");
        minslider->setGeometry(QRect(190, 90, 20, 100));
        minslider->setMaximum(59);
        minslider->setOrientation(Qt::Orientation::Vertical);
        secslider = new QSlider(centralwidget);
        secslider->setObjectName("secslider");
        secslider->setGeometry(QRect(310, 90, 21, 100));
        secslider->setSizeIncrement(QSize(5, 5));
        secslider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    height: 10px;\n"
"    background: rgba(0,0,0,80);\n"
"    border-radius: 5px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    background: white;\n"
"    border: 2px solid rgba(0,0,0,120);\n"
"    margin: -5px 0;\n"
"    border-radius: 10px;\n"
"}"));
        secslider->setMaximum(59);
        secslider->setOrientation(Qt::Orientation::Vertical);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(27, 200, 41, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"               color: white;                                      \n"
"               font-weight: bold;                                 \n"
"               text-shadow: 1px 1px 2px black;                    \n"
"               background-color: rgba(0, 0, 0, 128);            \n"
"               padding: 4px;                                    \n"
"               border-radius: 4px;                                \n"
"            }"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(156, 200, 51, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"               color: white;                                      \n"
"               font-weight: bold;                                 \n"
"               text-shadow: 1px 1px 2px black;                    \n"
"               background-color: rgba(0, 0, 0, 128);            \n"
"               padding: 4px;                                    \n"
"               border-radius: 4px;                                \n"
"            }"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(282, 200, 61, 21));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"               color: white;                                      \n"
"               font-weight: bold;                                 \n"
"               text-shadow: 1px 1px 2px black;                    \n"
"               background-color: rgba(0, 0, 0, 128);            \n"
"               padding: 4px;                                    \n"
"               border-radius: 4px;                                \n"
"            }"));
        orelabel = new QLabel(centralwidget);
        orelabel->setObjectName("orelabel");
        orelabel->setGeometry(QRect(85, 191, 30, 38));
        minlabel = new QLabel(centralwidget);
        minlabel->setObjectName("minlabel");
        minlabel->setGeometry(QRect(224, 191, 30, 38));
        seclabel = new QLabel(centralwidget);
        seclabel->setObjectName("seclabel");
        seclabel->setGeometry(QRect(355, 191, 30, 38));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 190, 111, 41));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(150, 190, 111, 41));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(270, 190, 121, 41));
        starttimer = new QPushButton(centralwidget);
        starttimer->setObjectName("starttimer");
        starttimer->setGeometry(QRect(170, 300, 131, 81));
        starttimer->setAutoFillBackground(false);
        starttimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #66BB6A;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;\n"
"}\n"
""));
        ringlabel = new QLabel(centralwidget);
        ringlabel->setObjectName("ringlabel");
        ringlabel->setGeometry(QRect(110, 250, 241, 31));
        timerwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(timerwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 610, 33));
        menuTimer = new QMenu(menubar);
        menuTimer->setObjectName("menuTimer");
        timerwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(timerwindow);
        statusbar->setObjectName("statusbar");
        timerwindow->setStatusBar(statusbar);

        menubar->addAction(menuTimer->menuAction());

        retranslateUi(timerwindow);

        QMetaObject::connectSlotsByName(timerwindow);
    } // setupUi

    void retranslateUi(QMainWindow *timerwindow)
    {
        timerwindow->setWindowTitle(QCoreApplication::translate("timerwindow", "timerwindow", nullptr));
        label->setText(QCoreApplication::translate("timerwindow", "Ore", nullptr));
        label_2->setText(QCoreApplication::translate("timerwindow", "Minuti", nullptr));
        label_3->setText(QCoreApplication::translate("timerwindow", "Secondi", nullptr));
        orelabel->setText(QCoreApplication::translate("timerwindow", "0", nullptr));
        minlabel->setText(QCoreApplication::translate("timerwindow", "0", nullptr));
        seclabel->setText(QCoreApplication::translate("timerwindow", "0", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        starttimer->setText(QCoreApplication::translate("timerwindow", "Start timer", nullptr));
        ringlabel->setText(QCoreApplication::translate("timerwindow", "L'ora corrente \303\250: ", nullptr));
        menuTimer->setTitle(QCoreApplication::translate("timerwindow", "Timer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class timerwindow: public Ui_timerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMERWINDOW_H
