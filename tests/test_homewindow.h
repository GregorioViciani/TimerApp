#ifndef TEST_HOMEWINDOW_H
#define TEST_HOMEWINDOW_H

#include <QObject>


class testhomewindow : public QObject {
Q_OBJECT

private slots:
    void testTimerButtonOpensTimerWindow();  // Test per verificare che il pulsante apra la finestra del timer

};

#endif // TEST_HOMEWINDOW_H
