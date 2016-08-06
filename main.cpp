#include <QApplication>
#include "RectangleWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool withAlpha = true;
    int side = 16;

    foreach (QString arg, a.arguments()) {
        bool ok;
        if (arg == "noalpha")
            withAlpha = false;
        else if (arg == "alpha")
            withAlpha = true;
        else if (arg.toInt(&ok) && ok)
            side = arg.toInt();
    }
    if (argc > 1 && qstrcmp(argv[1], "noalpha") == 0)
        withAlpha = false;

    RectangleWidget rectangles(side, withAlpha);
    rectangles.setMinimumSize(1280, 720);
    rectangles.showFullScreen();

    return a.exec();
}
