#include <QApplication>
#include "RectangleWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RectangleWidget rectangles;
    rectangles.setMinimumSize(1280, 720);
    rectangles.showFullScreen();

    //rectangles.setFocus();

    return a.exec();
}
