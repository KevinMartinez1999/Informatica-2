#include "orbitas.h"
#include "objetoscayendo.h"

#include <QDebug>

#define G 1
#define T 0.01
#define e 0.0375 //Es la escala

extern QList<Orbitas *> planetas;
extern QList<ObjetosCayendo *> objetos;

Orbitas::Orbitas(QObject *parent, double x, double y, double vx, double vy, double masa)
    : QObject(parent), X(400+x*e), Y(300+y*e), VX(vx), VY(vy), MASA(masa*e)
{
    srand(time(0));
    int color = 0 + (rand() % 6);
    //Lista para generar los colores aleatorios
    colors = {QBrush(Qt::red), QBrush(Qt::yellow),
              QBrush(Qt::blue), QBrush(Qt::black),
              QBrush(Qt::cyan), QBrush(Qt::magenta),
              QBrush(Qt::gray)};

    setRect(0,0,20,20);
    setBrush(colors[color]);
    setPos(X,Y);


    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Orbitas::move);
    timer->start();

    QTimer * colision = new QTimer;
    connect(colision, &QTimer::timeout, this, &Orbitas::colision);
    colision->start(200);
}

void Orbitas::move()
{
    double ax = 0.00, ay = 0.00;
    int len = planetas.size();
    for (int i = 0; i < len; i++)
    {
        if (planetas[i] != this)
        {
            double r = sqrt(pow(planetas[i]->getX()-X, 2)+pow(planetas[i]->getY()-Y, 2));
            ax += G*planetas[i]->getMASA()*(planetas[i]->getX()-X)/(pow(r, 3));
            ay += G*planetas[i]->getMASA()*(planetas[i]->getY()-Y)/(pow(r, 3));
        }
    }
    VX += ax*T;
    VY += ay*T;
    X += VX*T;
    Y += VY*T;
    setPos(X,Y);
}

void Orbitas::colision()
{
    int len = objetos.count();
    for (int i = 0; i < len; i++){
        if (collidesWithItem(objetos[i])){
            int color = 0 + (rand() % 6);
            do{
                color = 0 + (rand() % 6);
            }while(brush() == colors[color]);
            setBrush(colors[color]);
            return;
        }
    }
}
