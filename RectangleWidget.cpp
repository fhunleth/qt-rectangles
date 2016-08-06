#include "RectangleWidget.h"

#include <QPainter>
#include <QElapsedTimer>
#include <QApplication>

RectangleWidget::RectangleWidget(QWidget *parent) : QWidget(parent)
{
    font_ = QFont("DejaVu Sans Mono", 16);
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
    for (int y = 0; y < h; y += rh) {
        for (int x = 0; x < w; x += rw) {
            p.fillRect(x, y, rw, rh, QColor(gray, gray, gray));
            gray += 4;
            if (gray >= 256)
                gray = 0;
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
