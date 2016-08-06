#ifndef RECTANGLEWIDGET_H
#define RECTANGLEWIDGET_H

#include <QWidget>

class RectangleWidget : public QWidget
{
    Q_OBJECT
public:
    RectangleWidget(int side, bool withAlpha, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    QFont font_;
    bool withAlpha_;
    int side_; // yes, the rectangles became squares...
};

#endif // RECTANGLEWIDGET_H
