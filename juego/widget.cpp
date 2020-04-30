#include "widget.h"
#include "ui_widget.h"
#include "form.h"
#include "opciones.h"
#include <QDebug>

Form *form;
int numero_de_jugadores=1; //Variable global para saber cuantos jugadores serán
int dificultad=2;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Esto conecta al boton cerrar con la señal de close de la ventana.
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //Al pulsar el boton Nueva Partida se crea la interfaz
    //en donde se desarolla el juego.
    form=new Form;
    form->show();
    close();
}

void Widget::on_pushButton_3_clicked()
{
    Opciones *op=new Opciones;
    op->show();
    close();
}
