#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#endif

void limpiar_pantalla(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

}

void admin();
void agregar_pelicula();
void ofertar_asientos();
void generar_reporte();

void user();
void mostrar_funciones();
void seleccionar_asiento();

void menu(){
    int a=0;
    do{
        limpiar_pantalla();
        cout<<"1. Administrador\n";
        cout<<"2. Usuario\n";
        cout<<"3. Salir\n";
        cout<<"Selecciones una: "; cin>>a;
        switch (a) {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        default:
            break;
        }
    }while(a!=3);
}

void admin(){
    int a=0;
    do{
        limpiar_pantalla();
        cout<<"1. Agregar pelicula\n";
        cout<<"2. Ofertar asientos\n";
        cout<<"4. Generar reporte\n";
        cout<<"4. Salir\n";
        cout<<"Selecciones una: "; cin>>a;
        switch (a) {
        case 1:
            agregar_pelicula();
            break;
        case 2:
            ofertar_asientos();
            break;
        case 3:
            generar_reporte();
            break;
        default:
            break;
        }
    }while(a!=4);
}

void agregar_pelicula(){

}

void ofertar_asientos(){

}

void generar_reporte(){

}

void user(){
    int a=0;
    do{
        limpiar_pantalla();
        cout<<"1. Mostrar funciones\n";
        cout<<"2. Seleccionar asientos\n";
        cout<<"3. Salir\n";
        cout<<"Selecciones una: "; cin>>a;
        switch (a) {
        case 1:
            mostrar_funciones();
            break;
        case 2:
            seleccionar_asiento();
            break;
        default:
            break;
        }
    }while(a!=3);
}

void mostrar_funciones(){

}

void seleccionar_asiento(){

}

#endif // FUNCIONES_H
