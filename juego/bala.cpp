#include "bala.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <alien.h>
#include "form.h"

Bala::Bala(QObject *parent) : QObject(parent)
{
    /*
     *Establece la imagen de la bala y un timer con el movimiento
     *de la bala.
     */
    setPixmap(QPixmap(":/images/bala.png"));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(5);
}

void Bala::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

        //destruir enemigo cundo colisionan
        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Alien)){
                // increase the score
                //form->score->increase();

                // remove them from the scene (still on the heap)

                // delete them from the heap to save memory
                delete colliding_items[i];
                delete this;

                // return (all code below refers to a non existint bullet)
                return;
            }
        }

    setPos(x(),y()-2);
    if (pos().y() < 50){
        scene()->removeItem(this);
        delete this;
    }
}
