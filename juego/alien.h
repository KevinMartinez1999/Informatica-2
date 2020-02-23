#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Alien : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Alien(QObject *parent = nullptr);

signals:

public slots:
    void move();

};

#endif // ALIEN_H
