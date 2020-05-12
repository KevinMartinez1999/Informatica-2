#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <string.h>

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
int mostrar_funciones();
int seleccionar_asiento();

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
    limpiar_pantalla();
    int a=mostrar_funciones();
    int b=seleccionar_asiento();
    cout<<a<<endl;
}

int mostrar_funciones(){
    int cont, op=0;
    cout<<endl;
    cout<<"<----------------------------"
          "----------FUNCIONES----------"
          "---------------------------->\n\n";
    printf("%2s", "ID"); printf("%20s ", "Nombre"); printf("%10s ", "Genero"); printf("%10s ", "Duracion");
    printf("%10s ", "Sala"); printf("%10s ", "Hora"); printf("%10s ", "Asientos"); printf("%10s\n\n", "Clasif.");
    string contenido;
    char *token;
    ifstream file("../parcial/cartelera.txt");
    while(!file.eof()){
        cont=0;
        getline(file, contenido);
        char cadena[100]="";
        for(int i=0; i<int(contenido.size()); i++)
            cadena[i]=contenido[i];
        token=strtok(cadena, ",");
        cout<<token<<" ";
        while(token!=NULL){
            token=strtok(NULL, ",");
            if(cont==0){
                if(token!=NULL){
                    printf("%20s ", token);
                }
            }
            else{
                if(token!=NULL){
                    printf("%10s ", token);
                }
            }
            cont++;
        }
        cout<<endl;
    }
    file.close();
    cout<<"\nSEleccione una: "; cin>>op;
    return op;
}

int seleccionar_asiento(){
    limpiar_pantalla();
    int op;
    printf("%4s  ", "Tipo"); printf("%13s  ", "Clasificacion"); printf("%6s\n\n", "Costo");
    printf("%4s  ", "1"); printf("%13s  ", "General 2D"); printf("%6s\n", "7900$");
    printf("%4s  ", "2"); printf("%13s  ", "General 3D"); printf("%6s\n", "10800$");
    printf("%4s  ", "3"); printf("%13s  ", "VibroSound 2D"); printf("%6s\n", "9900$");
    printf("%4s  ", "4"); printf("%13s  ", "VibroSound 3D"); printf("%6s\n", "11900$");
    cout<<"\nSeleccione una: "; cin>>op;
    return op;
}

#endif // FUNCIONES_H
