#ifndef OBJETOSCAYENDO_H
#define OBJETOSCAYENDO_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class ObjetosCayendo : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit ObjetosCayendo(QObject *parent = nullptr,
                            double x = 0, double y = 0,
                            double vy = 0, double ay = 0);

    void move();
    void colision();

    inline void setVY(int v) {VY = v;}
    inline void setAY(int a) {AY = a;}

signals:

private:
    double X,Y,VY,AY,T;
    bool flag;

};

#endif // OBJETOSCAYENDO_H
