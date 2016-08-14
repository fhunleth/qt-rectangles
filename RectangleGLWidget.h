#ifndef RECTANGLEGLWIDGET_H
#define RECTANGLEGLWIDGET_H

#include <QOpenGLWidget>

class RectangleGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    RectangleGLWidget(int side, bool withAlpha, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    QFont font_;
    bool withAlpha_;
    int side_; // yes, the rectangles became squares...
};

#endif // RECTANGLEGLWIDGET_H
