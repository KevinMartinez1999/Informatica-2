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

public slots:
    void move();

signals:

private:
    double X,Y,VY,AY,T;

};

#endif // OBJETOSCAYENDO_H
