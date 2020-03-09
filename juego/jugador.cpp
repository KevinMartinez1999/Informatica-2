#include "jugador.h"
#include "bala.h"
#include "form.h"
#include "alien.h"

Jugador::Jugador(QObject *parent) : QObject(parent)
{
    srand(time(0)); //semilla aleatoria para el spawn de enemigos.
    banLeft=0; //Bandera para moverse a la izquierda.
    banRight=0; //Bandera para moverse a la derecha.

    //Aqui se conecta el timer con el movimiento a la izquierda y a la derecha.
    /*
     * Lo que hacen los SLOTS de moveLeft y moveRight es que
     * cada 30 mseg llama a la funcion y estas verifican si las
     * banderas estan en 1, si estan en 1 el personaje se mueve,
     * si no el personaje mantiene quieto
    */
    QTimer *timer=new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
    timer->start(10);

}

void Jugador::setBanderaLeft()
{
    banLeft=1;
}

void Jugador::resetBanderaLeft()
{
    banLeft=0;
}

void Jugador::setBanderaRight()
{
    banRight=1;
}

void Jugador::resetBanderaRight()
{
    banRight=0;
}

void Jugador::setBandera()
{
    bandera=1;
}

void Jugador::resetBandera()
{
    bandera=0;
}

//Aparicion de los enemigos
void Jugador::spawn()
{
    Alien *alien=new Alien(this);
    scene()->addItem(alien);
}

void Jugador::moveLeft()
{
    if(banLeft==1){
        if(pos().x()>0){
            setPos(x()-3, y());
        }
    }
}

void Jugador::moveRight()
{
    if(banRight==1){
        if(pos().x()<650){
            setPos(x()+3, y());
        }
    }
}
