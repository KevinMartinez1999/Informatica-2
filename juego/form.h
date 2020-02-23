#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QGraphicsScene>
#include "jugador.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    QGraphicsScene *escena;
    Jugador *jugador;
};

#endif // FORM_H
