#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QRect>
#include <QDesktopWidget>
#include <ctime>
#include <math.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void move();

private:
    Ui::Widget *ui;
    QGraphicsScene * scene;
    QGraphicsLineItem *bottom, *bottom2, *top, *left, *rigth;
    float x;
    float y;
    float width;
    float height;
};
#endif // WIDGET_H
