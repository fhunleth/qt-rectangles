#include <QApplication>
#include "RectangleWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool withAlpha = true;
    if (argc > 1 && qstrcmp(argv[1], "noalpha") == 0)
        withAlpha = false;

    RectangleWidget rectangles(withAlpha);
    rectangles.setMinimumSize(1280, 720);
    rectangles.showFullScreen();

    return a.exec();
}
