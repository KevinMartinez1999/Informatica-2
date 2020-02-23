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

            QMessageBox msgBox;
            msgBox.setText("Game Over.");
            msgBox.setInformativeText("Quieres reintentar?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int ret = msgBox.exec();
            if(ret==QMessageBox::Yes){
                Form *f=new Form;
                f->show();
                form->close();
            }
            else if(ret==QMessageBox::No){
                Widget *w=new Widget;
                w->show();
                form->close();
            }
            else{
                form->close();
            }
        }
        return;
    }

    setPos(x(),y()+2);
    if (pos().y() > 550){
        scene()->removeItem(this);
        delete this;
    }
}
