#ifndef ORBITAS_H
#define ORBITAS_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

class Orbitas : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit Orbitas(QObject *parent = nullptr,
                     double x = 0, double y = 0,
                     double vx = 0, double vy = 0,
                     double masa = 0);

    inline int getX() {return X;}
    inline int getY() {return Y;}
    inline int getVX() {return VX;}
    inline int getVY() {return VY;}
    inline int getMASA() {return MASA;}

public slots:
    void move();

private:
    double X,Y,VX,VY,MASA;

signals:

};

#endif // ORBITAS_H
