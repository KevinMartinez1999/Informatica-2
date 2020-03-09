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


/*
 *Estos objetos son externos para poder eliminarlos en caso
 * de que los jugadores mueran y se deba cerrar la ventana del juego
 * para volver al menu principal.
 */
extern Form *form;
extern Jugador *jugador, *jugador2;

Alien::Alien(QObject *parent) : QObject(parent)
{
    //Aqui en el constructor obtenemos la imagen y el timer
    //para el movimiento del alien.
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
            //Al remover el objeto jugador, se remueve tambien
            //el objeto alien porque jugador es su padre.
            delete jugador;
            /*
             * no se debe dar delete al objeto Alien
             * porque en el momento que borramos el objeto Jugador
             * se borra el objeto Alien que se creo dentro de él.
             */

            //Aqui se muestra un mensaje de Game Over y vuelve al menu principal.
            QMessageBox::information(form, "Game Over", "Perdiste wexd.");
            Widget *w=new Widget;
            w->show();
            form->close();
        }
        return;
    }

    //Movimiento del alien enemigo.
    setPos(x(),y()+2);
    if (pos().y() > 550){
        //Se elimina cuando sobrepasa la margen.
        scene()->removeItem(this);
        delete this;
    }
}
