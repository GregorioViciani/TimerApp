#include "../timerwindow.h"
#include "test_timerwindow.h"
#include <QSignalSpy>
#include <QSlider>
#include <QPushButton>
#include <QApplication>
#include <QTest>
#include <QLabel>
#include <QMovie>

void testtimerwindow::testInitialValues() {
    int argc = 1;
    const char *argv[] = {"test"};  // Puoi passare un nome arbitrario
    QApplication app(argc, const_cast<char **>(argv));  // Inizializza QApplication

    timerwindow w;
    QCOMPARE(w.findChild<QSlider*>("oreslider")->value(), 0);
    QCOMPARE(w.findChild<QSlider*>("minslider")->value(), 0);
    QCOMPARE(w.findChild<QSlider*>("secslider")->value(), 0);
}

void testtimerwindow::testSlidersUpdate() {
    int argc = 1;
    const char *argv[] = {"test"};  // Puoi passare un nome arbitrario
    QApplication app(argc, const_cast<char **>(argv));  // Inizializza QApplication

    timerwindow w;
    auto oreslider = w.findChild<QSlider*>("oreslider");
    auto minslider = w.findChild<QSlider*>("minslider");
    auto secslider = w.findChild<QSlider*>("secslider");

    oreslider->setValue(2);
    minslider->setValue(30);
    secslider->setValue(45);

    QCOMPARE(oreslider->value(), 2);
    QCOMPARE(minslider->value(), 30);
    QCOMPARE(secslider->value(), 45);

    int total = w.getTotalTimeInSeconds();
    QCOMPARE(total, 2 * 3600 + 30 * 60 + 45);
}

void testtimerwindow::testStartButtonCreatesCountdown() {
    // Inizializza QApplication
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));


    timerwindow w;

    // Imposta i valori degli slider
    w.findChild<QSlider*>("oreslider")->setValue(2);  // 2 ore
    w.findChild<QSlider*>("minslider")->setValue(30); // 30 minuti
    w.findChild<QSlider*>("secslider")->setValue(45); // 45 secondi

    // Verifica che le etichette siano aggiornate
    QCOMPARE(w.findChild<QLabel*>("orelabel")->text(), "2");
    QCOMPARE(w.findChild<QLabel*>("minlabel")->text(), "30");
    QCOMPARE(w.findChild<QLabel*>("seclabel")->text(), "45");

    // Calcola il totale dei secondi
    int totalTimeInSeconds = 2 * 3600 + 30 * 60 + 45;
    QCOMPARE(w.getTotalTimeInSeconds(), totalTimeInSeconds);

    // Trova il pulsante Start e simula il click
    auto* startButton = w.findChild<QPushButton*>("starttimer");
    QVERIFY(startButton != nullptr);  // Verifica che il pulsante esista

    // Simula il click sul pulsante Start
    QTest::mouseClick(startButton, Qt::LeftButton);

    // Verifica che il timer sia stato creato correttamente
    auto* timerLogic = w.findChild<timerlogic*>();
    QVERIFY(timerLogic != nullptr);

    // Verifica che il tempo rimanente sia positivo
    QVERIFY(timerLogic->remainingTime() > 0);

    // Ottieni l'orario previsto per il suono del timer
    QString expectedTime = "Il timer suonerà alle: " + QDateTime::currentDateTime().addSecs(totalTimeInSeconds).toString("hh:mm:ss");

    // Ottieni il tempo effettivo mostrato
    QString actualTime = w.findChild<QLabel*>("ringlabel")->text();

    QTime expected = QTime::fromString(expectedTime.mid(17), "hh:mm:ss");
    QTime actual = QTime::fromString(actualTime.mid(17), "hh:mm:ss");

    // Confronta la differenza tra i tempi, accettando una tolleranza di 2 secondi
    int diff = expected.msecsTo(actual);//Contronta expected con actual
    QVERIFY(qAbs(diff) <= 2000);  //  Test passato se |diff| minore uguale a 2 secondi di margine
}

#include "test_timerwindow.moc"
