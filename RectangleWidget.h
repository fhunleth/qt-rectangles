#ifndef RECTANGLEWIDGET_H
#define RECTANGLEWIDGET_H

#include <QWidget>

class RectangleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RectangleWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    QFont font_;
};

#endif // RECTANGLEWIDGET_H
