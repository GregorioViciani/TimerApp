#include "../ui_countdownwindow.h"
#include "test_countdownwindow.h"

#include <QPushButton>
#include <QTest>
#include <QSignalSpy>
#include <QApplication>


void testcountdownwindow::testTimeUpdates() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));

    // Crea un oggetto countdownWindow con parametro 30 secondi
    auto *window = new countdownwindow(30);

    window->updateTimeDisplay(30);  // Chiama la funzione per aggiornare la label
    QCoreApplication::processEvents();

    // Verifica che il tempo iniziale venga visualizzato correttamente
    QCOMPARE(window->ui->label_time->text(), QString("00:00:30"));

    QTest::qWait(1000);  // Aspetta 1 secondo

    window->updateTimeDisplay(29);
    QCoreApplication::processEvents();

    // Verifica che il tempo si aggiorni correttamente
    QCOMPARE(window->ui->label_time->text(), QString("00:00:29"));

    delete window;
}

void testcountdownwindow::testTimeFinishedSignal() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));

    // Crea un oggetto countdownWindow con parametro 2 secondi
    auto *window = new countdownwindow(2);

    QSignalSpy spy(window->logic, &timerlogic::timeFinished);

    // Imposta inizialmente la label a 2 secondi
    window->updateTimeDisplay(2);
    QCoreApplication::processEvents();

    // Verifica che il tempo iniziale venga visualizzato correttamente
    QCOMPARE(window->ui->label_time->text(), QString("00:00:02"));

    // Avvia il timer
    window->logic->start();

    qDebug() << "Test started...";


    QTest::qWait(3000);


    QCOMPARE(window->ui->label_time->text(), QString("00:00:00"));

    QCOMPARE(spy.count(), 1);  // Controlla che il segnale 'timeFinished' sia stato emesso una volta

    delete window;
}

void testcountdownwindow::testStopButton() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));

    // Crea un oggetto countdownWindow
    auto *window = new countdownwindow(30);  // Imposta inizialmente il timer a 30 secondi

    QPushButton *stopButton = window->ui->stopbutton;
    QSignalSpy spyStop(stopButton, &QPushButton::clicked);

    // Simula il click sul pulsante STOP
    QTest::mouseClick(stopButton, Qt::LeftButton);

    // Verifica che il pulsante STOP sia stato cliccato
    QCOMPARE(spyStop.count(), 1);

    // Forza l'elaborazione degli eventi per garantire che la UI venga aggiornata
    QCoreApplication::processEvents();

    QCOMPARE(window->logic->remainingTime(), 0);
    QCOMPARE(window->ui->label_time->text(), QString("00:00:00"));

    // Pulisci dopo il test
    delete window;
}

void testcountdownwindow::testTimeLabelColor() {
    int argc = 1;
    const char *argv[] = {"test"};
    QApplication app(argc, const_cast<char **>(argv));  // Inizializza QApplication

    // Crea l'oggetto countdownWindow con 10 secondi
    auto *window = new countdownwindow(10);

    // Avvia il timer
    window->logic->start();
    QTest::qWait(1000);

    // Forza l'elaborazione degli eventi per garantire che la UI venga aggiornata
    QCoreApplication::processEvents();
    QCOMPARE(window->ui->label_time->styleSheet(), "color: red;");

    delete window;
}

#include "test_countdownwindow.moc"

