#include <QtTest>
#include "timerlogic.h"

class TestTimerLogic : public QObject {
Q_OBJECT

private slots:
    void testInitialTime();
    void testSetTime();
    void testCountdown();
};

void TestTimerLogic::testInitialTime() {
    timerlogic logic;
    QCOMPARE(logic.remainingTime(), 0);
}

void TestTimerLogic::testSetTime() {
    timerlogic logic;
    logic.setTime(10);
    QCOMPARE(logic.remainingTime(), 10);
}

void TestTimerLogic::testCountdown() {
    timerlogic logic;
    logic.setTime(2);
    logic.start();
    QTest::qWait(2200);  // aspetta 2.2 secondi
    QCOMPARE(logic.remainingTime(), 0);
}

// QTEST_MAIN genera automaticamente la funzione main
QTEST_MAIN(TestTimerLogic)
#include "test_timerlogic.moc"
