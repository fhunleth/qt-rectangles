#include <QApplication>
#include "RectangleWidget.h"
#include "RectangleGLWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool useGL = false;
    bool withAlpha = true;
    int side = 16;

    foreach (QString arg, a.arguments()) {
        bool ok;
        if (arg == "noalpha")
            withAlpha = false;
        else if (arg == "alpha")
            withAlpha = true;
        else if (arg == "gl")
            useGL = true;
        else if (arg.toInt(&ok) && ok)
            side = arg.toInt();
    }
    if (argc > 1 && qstrcmp(argv[1], "noalpha") == 0)
        withAlpha = false;

    if (!useGL) {
        RectangleWidget rectangles(side, withAlpha);
        rectangles.setMinimumSize(1280, 720);
        rectangles.showFullScreen();

        return a.exec();
    } else {
        RectangleGLWidget rectangles(side, withAlpha);
        rectangles.setMinimumSize(1280, 720);
        rectangles.showFullScreen();

        return a.exec();
    }
}
