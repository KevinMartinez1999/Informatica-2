#ifndef ADMIN_H
#define ADMIN_H

#include <iostream> //Entrada y salida de datos
#include <fstream> //Manejo de archivos

using namespace std;

class admin
{
public:
    admin();
    void administrador();
    void limpiar_pantalla();
    void agregar_pelicula();
    void ofertar_asientos();
    void generar_reporte();
};

#endif // ADMIN_H