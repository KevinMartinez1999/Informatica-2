#include "widget.h"
#include "ui_widget.h"
#include "orbitas.h"
#include "objetoscayendo.h"

#include <QDebug>

QList<Orbitas *> planetas;
QList<ObjetosCayendo *> objetos;

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

    //Screen lenght.
    QRect lenScreen = QApplication::desktop()->screenGeometry();
    x=lenScreen.x();
    y=lenScreen.y();
    width=lenScreen.width();
    height=lenScreen.height();

    //line delimiter.
    top     = new QGraphicsLineItem(x,y,width,y);
    bottom  = new QGraphicsLineItem(0,550,800,550);
    left    = new QGraphicsLineItem(x,y,x,height);
    rigth   = new QGraphicsLineItem(width,y,width,height);

    scene->addItem(top);
    scene->addItem(bottom);
    scene->addItem(left);
    scene->addItem(rigth);

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
    connect(timer, &QTimer::timeout, this, &Widget::move);
    timer->start(30);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int Aaleatoria = 1 + (rand() % 3);
    int Xaleatoria = 1 + (rand() % 780);
    ObjetosCayendo * obj = new ObjetosCayendo(this, Xaleatoria, 0, 0, Aaleatoria);
    scene->addItem(obj);
    objetos.append(obj);
}

void Widget::move()
{
    for (int i = 0; i < objetos.length(); i++)
    {
        if (objetos[i]->collidesWithItem(bottom))
        {
            qDebug()<<"Colision";
            objetos[i]->colision();
        }

        objetos[i]->move();
    }
}
