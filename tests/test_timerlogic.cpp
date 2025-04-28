#include "../timerlogic.h"
#include "test_timerlogic.h"
#include <QSignalSpy>
#include <QApplication>
#include <QTest>

void testtimerlogic::testSetTime() {
    timerlogic t;
    t.setTime(3661);
    QCOMPARE(t.remainingTime(), 3661);
}

void testtimerlogic::testStartAndCountdown() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));  // Inizializza QApplication

    timerlogic t;
    t.setTime(3);

    QSignalSpy upd(&t, &timerlogic::timeUpdated);
    QSignalSpy fin(&t, &timerlogic::timeFinished);

    t.start();

    // Aspettiamo che il segnale timeUpdated venga emesso 3 volte
    for (int i = 0; i < 3; ++i) {
        QVERIFY2(upd.wait(1100), "timeUpdated non è arrivato in tempo");
    }

    // Verifica che timeFinished sia stato emesso una sola volta
    QTRY_COMPARE(fin.count(), 1);

    // Verifica che non ci siano segnali timeFinished doppi
    QTest::qWait(1100);
    QCOMPARE(fin.count(), 1);
}

void testtimerlogic::testStop() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));  // Inizializza QApplication

    timerlogic t;
    t.setTime(5);

    QSignalSpy upd(&t, &timerlogic::timeUpdated);  // Osserviamo gli aggiornamenti del tempo

    t.start();

    // Aspettiamo 2 aggiornamenti
    for (int i = 0; i < 2; ++i) {
        QVERIFY2(upd.wait(1100), "Non è arrivato un aggiornamento previsto");
    }

    t.stop();  // Fermiamo il timer
    int rem = t.remainingTime();

    QTest::qWait(2000);  // Aspettiamo 2 secondi

    QCOMPARE(upd.count(), 2); // Verifica che gli aggiornamenti siano solo 2
    QCOMPARE(t.remainingTime(), rem); //Verifica che il tempo residuo non sia cambiato
}

void testtimerlogic::testTimeFinishedSignal() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));

    timerlogic t;
    t.setTime(2);

    QSignalSpy fin(&t, &timerlogic::timeFinished);  // Osserviamo il segnale timeFinished

    t.start();

    // Verifica che il segnale timeFinished venga emesso
    QVERIFY2(fin.wait(3000), "Non è arrivato il segnale di fine nei tempi previsti");

    // Verifica che il segnale timeFinished sia stato emesso una sola volta
    QCOMPARE(fin.count(), 1);
}

#include "test_timerlogic.moc"

