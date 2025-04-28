#include "test_homewindow.h"
#include "../homewindow.h"

#include <QPushButton>
#include <QtTest>


void testhomewindow::testTimerButtonOpensTimerWindow() {
    int argc = 1;
    const char *argv[] = {"test"};
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
