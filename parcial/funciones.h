#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
 La funcion de limpiar pantalla implementada abajo funciona tant para Linux
 como para windows gracias a una MACRO que lo que busca es que este definido
 el WIN32 que en ese caso seria el SO Windows, en caso de no estar definido
 el sistema donde se ejecua es un linux.
 */

#ifdef _WIN32
  #include<windows.h>
#endif

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

//Aqui la declaracion de las funciones que van a ser usadas.

void interfaz();
void interfaz_de_admin();
void ingresar_pelicula();
void asientos_disponibles();

void interfaz_de_usuario();

/*
 Aqui se muestra la primera interfaz donde se elije si acceder como
 un usuario corriente o un administrador y una opcion para acabar el
 programa si asi lo desea.
 */

void interfaz(){
    int opcion=0;
    do{
        limpiar_pantalla();
        cout<<"1. Administrador\n2. Usuario\n3. Salir\nElija una opcion: "; cin>>opcion;
        switch(opcion) {
        case 1:
            interfaz_de_admin();
            break;
        case 2:
            interfaz_de_usuario();
            break;
        }
    }while(opcion!=3);
}

/*
 Aqui la interfaz del admin donde puede hacer cambios a la cartelera, precios
 las ventas, etc.
 */

void interfaz_de_admin(){
    limpiar_pantalla();
    int opcion=0;
    cout<<"1. Ingresar pelicula\nElija una opcion: "; cin>>opcion;
    switch(opcion) {
    case 1:
        ingresar_pelicula();
        break;
    }
}

//ingresa los daros de la pelicula y van a la base de datos
void ingresar_pelicula(){
    string nombre, genero, duracion, sala, hora, asientos, clas;
    cout<<"Nombre   : "; cin>>nombre;
    cout<<"Genero   : "; cin>>genero;
    cout<<"Duracion : "; cin>>duracion;
    cout<<"Sala     : "; cin>>sala;
    cout<<"Hora     : "; cin>>hora;
    cout<<"Asientos : "; cin>>asientos;
    cout<<"Clasif.  : "; cin>>clas;
    cout<<nombre<<endl;
    cin.ignore().get();
    ofstream file("peliculas.txt");
    file<<nombre<<" "<<genero<<" "<<duracion<<" "<<sala<<" ";
    file<<hora<<" "<<asientos<<" "<<clas<<"\n";
    file.close();
}

void asientos_disponibles(){

}

void interfaz_de_usuario(){

}

#endif // FUNCIONES_H
