#ifndef TEST_COUNTDOWNWINDOW_H
#define TEST_COUNTDOWNWINDOW_H

#include "../countdownwindow.h"

#include <QObject>

class testcountdownwindow : public QObject {
Q_OBJECT

private slots:

    void testTimeUpdates();  // Test per verificare che il tempo si aggiorni correttamente
    void testTimeFinishedSignal();  // Test per verificare che il segnale timeFinished venga emesso
    void testStopButton();  // Test per verificare che il pulsante STOP fermi il timer
    void testTimeLabelColor();  // Test per verificare che il colore del testo cambi

private:
    countdownwindow* countdownWindow;
    int totalSeconds;

};

#endif // TEST_COUNTDOWNWINDOW_H
