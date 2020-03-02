#ifndef OPCIONES_H
#define OPCIONES_H

#include <QWidget>

namespace Ui {
class Opciones;
}

class Opciones : public QWidget
{
    Q_OBJECT

public:
    explicit Opciones(QWidget *parent = nullptr);
    ~Opciones();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Opciones *ui;
};

#endif // OPCIONES_H
