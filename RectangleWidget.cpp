#include "RectangleWidget.h"

#include <QPainter>
#include <QElapsedTimer>
#include <QApplication>

RectangleWidget::RectangleWidget(bool withAlpha, QWidget *parent)
    : QWidget(parent)
    , font_("DejaVu Sans Mono", 16)
    , withAlpha_(withAlpha)
{
    startTimer(500);
}

void RectangleWidget::paintEvent(QPaintEvent *)
{
    QElapsedTimer timer;
    timer.start();
    QPainter p(this);

    int w = width();
    int h = height();
    int rw = 16;
    int rh = 16;
    int gray = 0;

    p.fillRect(0, 0, w, h, Qt::blue);

    for (int y = 0; y < h; y += rh) {
        for (int x = 0; x < w; x += rw) {
            p.fillRect(x, y, rw, rh, QColor(gray, gray, gray, withAlpha_ ? gray : 255));
            gray += 3;
            if (gray >= 256)
                gray -= 256;
        }
    }

    p.setFont(font_);
    p.setPen(Qt::green);
    p.drawText(10, 100, QString("Redraw time: %1 ms").arg(timer.elapsed()));
}

void RectangleWidget::timerEvent(QTimerEvent *)
{
    update();
}

void RectangleWidget::keyPressEvent(QKeyEvent *)
{
    // Exit on any key
    QApplication::exit();
}
