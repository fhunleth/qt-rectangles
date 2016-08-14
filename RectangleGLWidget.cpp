#include "RectangleGLWidget.h"

#include <QPainter>
#include <QElapsedTimer>
#include <QApplication>

RectangleGLWidget::RectangleGLWidget(int side, bool withAlpha, QWidget *parent)
    : QOpenGLWidget(parent)
    , font_("DejaVu Sans Mono", 16)
    , withAlpha_(withAlpha)
    , side_(side)
{
    startTimer(500);
}

void RectangleGLWidget::paintEvent(QPaintEvent *)
{
    QElapsedTimer timer;
    timer.start();
    QPainter p(this);

    int w = width();
    int h = height();
    int gray = 128; // Start at non-zero since if doing only 1 rectangle,
                    // we don't want it to be completely transparent

    p.fillRect(0, 0, w, h, Qt::blue);

    for (int y = 0; y < h; y += side_) {
        int rh = qMin(h - y, side_);
        for (int x = 0; x < w; x += side_) {
            int rw = qMin(w - x, side_);
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

void RectangleGLWidget::timerEvent(QTimerEvent *)
{
    update();
}

void RectangleGLWidget::keyPressEvent(QKeyEvent *)
{
    // Exit on any key
    QApplication::exit();
}
