#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>

class Jugador : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Jugador(QObject *parent = nullptr);
    void setBanderaLeft();
    void resetBanderaLeft();
    void setBanderaRight();
    void resetBanderaRight();
    void setBandera();
    void resetBandera();

signals:

public slots:
    void spawn();
    void moveLeft();
    void moveRight();

private:
    int banLeft;
    int banRight;
    int bandera;

};

#endif // JUGADOR_H
