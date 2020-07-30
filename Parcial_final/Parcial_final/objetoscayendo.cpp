#include "objetoscayendo.h"

#define e 0.8

ObjetosCayendo::ObjetosCayendo(QObject *parent, double x, double y, double vy, double ay)
    : QObject(parent), X(x), Y(y), VY(vy), AY(ay)
{
    T = 0;

    setRect(0,0,20,20);
    setBrush(QBrush(Qt::green));
    setPos(X,Y);
}

void ObjetosCayendo::move()
{
    T += 0.01;
    VY += AY*T;
    Y += VY*T + (0.5)*AY*pow(T,2);
    setY(Y);
}

void ObjetosCayendo::colision()
{
    VY = -VY*e;
}
