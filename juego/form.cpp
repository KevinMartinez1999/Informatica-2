#include "form.h"
#include "ui_form.h"
#include <QTimer>
#include <QDebug>

Jugador *jugador;
Jugador *jugador2;

extern int numero_de_jugadores;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    //agregar escena
    escena=new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 750, 550);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(750,550);
    ui->graphicsView->setScene(escena);

    if(numero_de_jugadores==1){
        //agregar jugador 1
        jugador=new Jugador(escena);
        jugador->setPixmap(QPixmap(":/images/cohete.png"));
        jugador->setPos(200,450);
        escena->addItem(jugador);
    }
    else if(numero_de_jugadores==2){
        pj2=true;

        //agregar jugador 1
        jugador=new Jugador(escena);
        jugador->setPixmap(QPixmap(":/images/cohete.png"));
        jugador->setPos(200,450);
        escena->addItem(jugador);

        //agregar jugador 2
        jugador2=new Jugador(jugador);
        jugador2->setPixmap(QPixmap(":/images/cohete2.png"));
        jugador2->setPos(280,450);
        escena->addItem(jugador2);
    }

    //spaw del enemigo
    /*
     *El spawn de los enemigos depende unicamente del jugador1,
     * por esta razon cuando el enemigo golpea al jugador2 se
     * debe remover tambien el jugador1 porque es quien es padre del
     * objeto alien.
     */
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),jugador,SLOT(spawn()));
    timer->start(2000);
}

//Esta funcion se ejecuta cuando se oprime una tecla.
/*Lo que hace es que en el momento que se presiona la tecla
 * de movimiento, pone las banderas en 1 y asi inicia el movimiento.
 * */
void Form::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A){
        jugador->setBanderaLeft();
    }
    else if(event->key()==Qt::Key_D){
        jugador->setBanderaRight();
    }
    else if(event->key()==Qt::Key_V){
        bala1=new Bala(jugador);
        bala1->setPos(jugador->x()+45,jugador->y());
        escena->addItem(bala1);
    }
    else if(event->key()==Qt::Key_J){
        if(pj2)
            jugador2->setBanderaLeft();
    }
    else if(event->key()==Qt::Key_L){
        if(pj2)
            jugador2->setBanderaRight();
    }
    else if(event->key()==Qt::Key_P){
        if(pj2){
            bala2=new Bala(jugador);
            bala2->setPos(jugador2->x()+45,jugador2->y());
            escena->addItem(bala2);
        }
    }
}

//Esta funcion se ejecuta cuando no se esta pulsando ninguna tecla.
/*Lo que hace es que en el momento que se deja de presionar la tecla
 * de movimiento, pone las banderas en 0 y asi el movimiento para.
 * */
void Form::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A){
        jugador->resetBanderaLeft();
    }
    else if(event->key()==Qt::Key_D){
        jugador->resetBanderaRight();
    }
    else if(event->key()==Qt::Key_J){
        if(pj2)
            jugador2->resetBanderaLeft();
    }
    else if(event->key()==Qt::Key_L){
        if(pj2)
            jugador2->resetBanderaRight();
    }
}

Form::~Form()
{
    delete ui;
}
