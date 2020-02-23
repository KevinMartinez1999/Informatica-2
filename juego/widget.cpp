#include "widget.h"
#include "ui_widget.h"
#include "form.h"

Form *form;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(close()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    form=new Form;
    close();
    form->show();
}
