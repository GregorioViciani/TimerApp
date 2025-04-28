#include "homewindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    homewindow window;
    window.show();

    return app.exec();
}
