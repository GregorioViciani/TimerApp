#ifndef TEST_TIMERWINDOW_H
#define TEST_TIMERWINDOW_H

#include <QObject>

class testtimerwindow : public QObject {
Q_OBJECT

private slots:
    void testInitialValues();                // Test per verificare i valori iniziali degli slider
    void testSlidersUpdate();                // Test per verificare l'aggiornamento degli slider
    void testStartButtonCreatesCountdown();  // Test per verificare che il pulsante di avvio crei il countdown

};

#endif // TEST_TIMERWINDOW_H
