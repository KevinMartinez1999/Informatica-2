#include "widget.h"
#include "ui_widget.h"
#include "orbitas.h"
#include "objetoscayendo.h"

#include <QDebug>

QList<Orbitas *> planetas;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(NULL));

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 782, 582);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);

    Orbitas * planeta1 = new Orbitas(this, 0, 0, 0, 0, 50000);
    Orbitas * planeta2 = new Orbitas(this, -5000, 0, 0, -2, 70);
    Orbitas * planeta3 = new Orbitas(this, 5000, 0, 0, 2, 70);
    Orbitas * planeta4 = new Orbitas(this, 0, -5000, 2, 0, 70);
    Orbitas * planeta5 = new Orbitas(this, 0, 5000, -2, 0, 70);

    planetas.append(planeta1);
    planetas.append(planeta2);
    planetas.append(planeta3);
    planetas.append(planeta4);
    planetas.append(planeta5);

    scene->addItem(planeta1);
    scene->addItem(planeta2);
    scene->addItem(planeta3);
    scene->addItem(planeta4);
    scene->addItem(planeta5);

    QTimer * timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Widget::generarObjetos);
    timer->start(2000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::generarObjetos()
{
    int Aaleatoria = 1 + (rand() % 20);
    qDebug()<<Aaleatoria;
    int Xaleatoria = 1 + (rand() % 780);
    ObjetosCayendo * obj = new ObjetosCayendo(this, Xaleatoria, 0, 3, Aaleatoria);
    scene->addItem(obj);
}

