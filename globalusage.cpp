#include "globalusage.h"

#include <QPixmap>
#include <QPalette>
#include <QBrush>

void resizeAndSetBackgroundImage(QWidget* window, const QString& background) {
    QPixmap backgroundPixmap(background);
    backgroundPixmap = backgroundPixmap.scaled(window->size(),
                                               Qt::IgnoreAspectRatio,
                                               Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(backgroundPixmap));

    window->setAutoFillBackground(true);
    window->setPalette(palette);
}