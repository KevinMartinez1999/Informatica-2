#include "alien.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <cstdlib>
#include <ctime>
#include "jugador.h"
#include "form.h"
#include <QMessageBox>
#include "widget.h"

extern Form *form;

Alien::Alien(QObject *parent) : QObject(parent)
{
    int num=10+(rand()%700);
    setPos(num,0);
    setPixmap(QPixmap(":/images/nave.png"));
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Alien::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //destruir enemigo cundo colisionan
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Jugador)){
            scene()->removeItem(colliding_items[i]);
            //scene()->removeItem(this);
            delete colliding_items[i];
            //delete this;
            /*
             * no se debe dar delete al objeto Alien
             * porque en el momento que borramos el objeto Jugador
             * se borra el objeto Alien que se creo dentro de él.
             */

            QMessageBox::information(form, "Game Over", "Perdiste wexd.");
            Widget *w=new Widget;
            w->show();
            form->close();
        }
        return;
    }

    setPos(x(),y()+2);
    if (pos().y() > 550){
        scene()->removeItem(this);
        delete this;
    }
}
