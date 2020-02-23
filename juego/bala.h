#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Bala : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bala(QObject *parent = nullptr);

signals:

public slots:
    void move();

};

#endif // BALA_H
