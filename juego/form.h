#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsItem>
#include "jugador.h"
#include "bala.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::Form *ui;
    QGraphicsScene *escena;
    Bala *bala1, *bala2;
    bool pj2=false; //Variable que controla si el jugador 2 estará activo o no.
};

#endif // FORM_H
