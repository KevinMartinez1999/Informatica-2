#include "jugador.h"
#include "bala.h"
#include "form.h"
#include "alien.h"

Jugador::Jugador(QObject *parent) : QObject(parent)
{
    srand(time(0));
    setPixmap(QPixmap(":/images/cohete.png"));
    this->setPos(280,450);
}

void Jugador::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if(pos().x()>20){
            setPos(x()-20, y());
        }
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x()<680){
            setPos(x()+20, y());
        }
    }
    else if (event->key()==Qt::Key_Space){
        Bala *bala=new Bala(this);
        bala->setPos(x()+45, y());
        scene()->addItem(bala);
    }
}

void Jugador::spawn()
{
    Alien *alien=new Alien(this);
    scene()->addItem(alien);
}
