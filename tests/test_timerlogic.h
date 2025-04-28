#ifndef TEST_TIMERLOGIC_H
#define TEST_TIMERLOGIC_H

#include <QObject>

class testtimerlogic : public QObject {
Q_OBJECT  // Necessario per le classi di test di Qt

private slots:
    void testSetTime();              // Testa il metodo setTime
    void testStartAndCountdown();    // Testa la partenza e il countdown
    void testStop();                 // Testa l'arresto del timer
    void testTimeFinishedSignal();   // Verifica che il segnale timeFinished venga emesso

};

#endif // TEST_TIMERLOGIC_H
