/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homewindow
{
public:
    QWidget *centralwidget;
    QPushButton *timerbutton;
    QPushButton *svegliabutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *homewindow)
    {
        if (homewindow->objectName().isEmpty())
            homewindow->setObjectName("homewindow");
        homewindow->resize(610, 485);
        centralwidget = new QWidget(homewindow);
        centralwidget->setObjectName("centralwidget");
        timerbutton = new QPushButton(centralwidget);
        timerbutton->setObjectName("timerbutton");
        timerbutton->setGeometry(QRect(120, 160, 151, 101));
        svegliabutton = new QPushButton(centralwidget);
        svegliabutton->setObjectName("svegliabutton");
        svegliabutton->setGeometry(QRect(380, 160, 161, 101));
        homewindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(homewindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 610, 33));
        homewindow->setMenuBar(menubar);
        statusbar = new QStatusBar(homewindow);
        statusbar->setObjectName("statusbar");
        homewindow->setStatusBar(statusbar);

        retranslateUi(homewindow);

        QMetaObject::connectSlotsByName(homewindow);
    } // setupUi

    void retranslateUi(QMainWindow *homewindow)
    {
        homewindow->setWindowTitle(QCoreApplication::translate("homewindow", "homewindow", nullptr));
        timerbutton->setText(QCoreApplication::translate("homewindow", "Timer", nullptr));
        svegliabutton->setText(QCoreApplication::translate("homewindow", "Sveglia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class homewindow: public Ui_homewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
