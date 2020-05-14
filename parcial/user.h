#ifndef USER_H
#define USER_H

#include <iostream> //Entrada y salida de datos
#include <fstream> //Manejo de archivos
#include <string.h> //Manejo de los string
#include <map> //Contenedor mapa para trabajar los precios y los asientos
#include <ctime> //Manejo del tiempo para hacer los reportes de ventas

using namespace std;

class user
{
public:
    user();
    void usuario();
    void limpiar_pantalla();
    int mostrar_funciones();
    string seleccionar_funcion(int a);
    void seleccionar_asiento(string, int);
    void imprimir_sala(string, map<char, int> &, int);
    void comprar(int, string, char, char, char, map<char, int> &);
    void reporte(map<char, int> &, char, char);
    void asientos_disp(int);
};

#endif // USER_H
