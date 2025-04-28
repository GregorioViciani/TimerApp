#include "test_homewindow.h"
#include <QPushButton>
#include <QtTest>
#include <QApplication>
#include "../homewindow.h"

void testhomewindow::testTimerButtonOpensTimerWindow() {
    int argc = 1;
    const char *argv[] = {"test"};  // Puoi passare un nome arbitrario
    QApplication app(argc, const_cast<char **>(argv));  // Inizializza QApplication

    homewindow win;
    QVERIFY(win.timerwin == nullptr);  // Verifica che timerwin non sia inizializzato

    auto* button = win.findChild<QPushButton*>("timerbutton");
    QVERIFY(button);  // Verifica che il bottone sia presente nella finestra

    QTest::mouseClick(button, Qt::LeftButton);  // Simula il click sul bottone
    QTest::qWait(100);  // Attende un po' di tempo per l'aggiornamento della UI

    // Verifica che la finestra del timer sia visibile e che la finestra principale non lo sia più
    QVERIFY(win.timerwin != nullptr);  // Verifica che timerwin sia stato creato
    QVERIFY(win.timerwin->isVisible());  // Verifica che la finestra del timer sia visibile
    QVERIFY(!win.isVisible());  // La finestra principale non dovrebbe essere visibile
}

#include "test_homewindow.moc"
