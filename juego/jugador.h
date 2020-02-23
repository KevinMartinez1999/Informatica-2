#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Jugador : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Jugador(QObject *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);

signals:

public slots:
    void spawn();

};

#endif // JUGADOR_H
