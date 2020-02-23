#include "form.h"
#include "ui_form.h"
#include <QTimer>

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

    //agregar jugador
    jugador=new Jugador(escena);
    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador->setFocus();
    escena->addItem(jugador);

    //spaw del enemigo
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),jugador,SLOT(spawn()));
    timer->start(2000);
}

Form::~Form()
{
    delete ui;
}
