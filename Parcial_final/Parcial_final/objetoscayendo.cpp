#include "objetoscayendo.h"

ObjetosCayendo::ObjetosCayendo(QObject *parent, double x, double y, double vy, double ay)
    : QObject(parent), X(x), Y(y), VY(vy), AY(ay)
{
    T = 0;

    setRect(0,0,20,20);
    setBrush(QBrush(Qt::green));
    setPos(X,Y);

    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &ObjetosCayendo::move);
    timer->start(30);
}

void ObjetosCayendo::move()
{
    T += 0.03;
    Y += VY*T + (0.5)*AY*pow(T,2);
    setY(Y);
}
