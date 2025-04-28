#include <QCoreApplication>
#include <QTest>


#include "test_homewindow.h"
#include "test_timerwindow.h"
#include "test_timerlogic.h"
#include "test_countdownwindow.h"

int main(int argc, char *argv[]) {
    // Inizializza l'app Qt per eseguire i test
    QCoreApplication app(argc, argv);

    // Esegui i singoli test separatamente
    int status = 0;

    testhomewindow thw;
    status |= QTest::qExec(&thw, argc, argv);  // Esegui il test della homewindow

    testtimerwindow ttw;
    status |= QTest::qExec(&ttw, argc, argv);  // Esegui il test della timerwindow

    testtimerlogic ttl;
    status |= QTest::qExec(&ttl, argc, argv);  // Esegui il test della timerlogic

    testcountdownwindow tcw;
    status |= QTest::qExec(&tcw, argc, argv);  // Esegui il test della countdownwindow

    // Restituisci il risultato finale dei test
    return status;

}
