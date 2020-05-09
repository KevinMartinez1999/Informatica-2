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
void generar_reporte();

void interfaz_de_usuario();

/*
 Aqui se muestra la primera interfaz donde se elije si acceder como
 un usuario corriente o un administrador y una opcion para acabar el
 programa si asi lo desea.
 */

void interfaz(){
    limpiar_pantalla();
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
    cout<<"1. Ingresar pelicula\n";
    cout<<"2. Consultar asientos disponibles\n";
    cout<<"3. Generar reporte\n";
    cout<<"Elija una opcion: "; cin>>opcion;
    switch(opcion) {
    case 1:
        ingresar_pelicula();
        break;
    case 2:
        asientos_disponibles();
        break;
    case 3:
        generar_reporte();
        break;
    }
}

//ingresa los daros de la pelicula y van a la base de datos
void ingresar_pelicula(){
    cin.ignore();
    char nombre[20], genero[20], duracion[20], sala[20], hora[20], asientos[20], clas[20];
    cout<<"Nombre   : "; cin.getline(nombre, 20, '\n');
    cout<<"Genero   : "; cin.getline(genero, 20, '\n');
    cout<<"Duracion : "; cin.getline(duracion, 20, '\n');
    cout<<"Sala     : "; cin.getline(sala, 20, '\n');
    cout<<"Hora     : "; cin.getline(hora, 20, '\n');
    cout<<"Asientos : "; cin.getline(asientos, 20, '\n');
    cout<<"Clasfic. : "; cin.getline(clas, 20, '\n');
    ofstream file("cartelera.txt", ios::binary);
    file<<nombre<<" "<<genero<<" "<<duracion<<" "<<sala<<" ";
    file<<hora<<" "<<asientos<<" "<<clas<<'\n';
    file.close();
}

void asientos_disponibles(){
    cin.ignore();
    char nombre[20], genero[20], duracion[20], sala[20], hora[20], asientos[20], clas[20];
    char pelicula[20];
    cout<<"Nombre   : "; cin.getline(pelicula, 20, '\n');
    ifstream file("cartelera.txt");
    if(file.is_open()){
        file>>nombre;
        while(!file.eof()){
            file>>genero;
            file>>duracion;
            file>>sala;
            file>>hora;
            file>>asientos;
            file>>clas;
            if(nombre==string(pelicula)){
                cout<<"Hay "<<asientos<<" disponibles"<<endl;
                cin.ignore();
            }
            file>>nombre;
        }
    }
    file.close();
}

void generar_reporte(){

}

void interfaz_de_usuario(){
    cout<<"\n\n";
    printf("%10s  ", "nombre"); printf("%10s  ", "Genero"); printf("%8s  ", "Duracion"); printf("%4s  ", "Sala");
    printf("%4s  ", "Hora"); printf("%8s  ", "Asientos"); printf("%13s  ", "Clasificacion"); cout<<"\n\n";
    char nombre[20], genero[20], duracion[20], sala[20], hora[20], asientos[20], clas[20];
    ifstream file("cartelera.txt");
    if(file.is_open()){
        file>>nombre;
        while(!file.eof()){
            file>>genero;
            file>>duracion;
            file>>sala;
            file>>hora;
            file>>asientos;
            file>>clas;
            printf("%10s  ", nombre); printf("%10s  ", genero); printf("%8s  ", duracion); printf("%4s  ", sala);
            printf("%4s  ", hora); printf("%8s  ", asientos); printf("%13s  ", clas); printf("\n");
            file>>nombre;
        }
    }
    file.close();
    cin.ignore().get();
}

#endif // FUNCIONES_H
