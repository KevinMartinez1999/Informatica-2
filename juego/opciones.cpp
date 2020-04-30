#include "opciones.h"
#include "ui_opciones.h"
#include "widget.h"
#include <QDebug>

extern int numero_de_jugadores;
extern int dificultad;

Opciones::Opciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Opciones)
{
    ui->setupUi(this);
}

Opciones::~Opciones()
{
    delete ui;
}

void Opciones::on_pushButton_clicked()
{
    //Obtener los datos señalados en los radioButton
    if(ui->radioButton->isChecked())
        numero_de_jugadores=1;
    else if(ui->radioButton_2->isChecked())
        numero_de_jugadores=2;

    if(ui->facil->isChecked())
        dificultad=1;
    else if(ui->medio->isChecked())
        dificultad=2;
    else if(ui->dificil->isChecked())
        dificultad=3;

    Widget *w=new Widget;
    w->show();
    close();
}
