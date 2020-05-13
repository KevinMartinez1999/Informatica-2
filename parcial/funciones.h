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
string seleccionar_funcion(int a);
void seleccionar_asiento(string);
void imprimir_sala(int);

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

}
void agregar_pelicula(){

}
void ofertar_asientos(){

}
void generar_reporte(){

}

void user(){
    limpiar_pantalla();
    int id=mostrar_funciones();
    string sala=seleccionar_funcion(id);
    seleccionar_asiento(sala);
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
    cout<<"Seleccionar: "; cin>>op;
    return op;
}

string seleccionar_funcion(int a){
    string contenido, sala;
    char *token;
    int cont=1, col;
    ifstream file("../parcial/cartelera.txt");
    while(!file.eof()){
        getline(file, contenido);
        if(cont==a){
            char cadena[100]="";
            for(int i=0; i<int(contenido.size()); i++)
                cadena[i]=contenido[i];
            token=strtok(cadena, ",");
            col=0;
            while(token!=NULL){
                token=strtok(NULL, ",");
                col++;
                if(token!=NULL)
                    if(col==4){
                        sala=token;
                        return sala;
                    }
            }
        }
        cont++;
    }
    file.close();
    return NULL;
}

void seleccionar_asiento(string sala){
    limpiar_pantalla();
    printf("%4s  ", "Tipo"); printf("%13s  ", "Clasificacion"); printf("%6s\n\n", "Costo");
    printf("%4s  ", "1"); printf("%13s  ", "General 2D"); printf("%6s\n", "7900$");
    printf("%4s  ", "2"); printf("%13s  ", "General 3D"); printf("%6s\n", "10800$");
    printf("%4s  ", "3"); printf("%13s  ", "VibroSound 2D"); printf("%6s\n", "9900$");
    printf("%4s  ", "4"); printf("%13s  ", "VibroSound 3D"); printf("%6s\n", "11900$");
    cout<<"<----------------------------"
          "----------    /    ----------"
          "---------------------------->\n\n";
    int op=stoi(sala)-3;
    switch(op){
    case 1:
        imprimir_sala(50);
        break;
    case 2:
    case 3:
    case 4:
    case 7:
        imprimir_sala(140);
        break;
    case 5:
    case 6:
        imprimir_sala(100);
        break;
    }

    char fila, col;
    cout<<"\nSelecciona fila: "; cin>>fila;
    cout<<"Selecciona columna: "; cin>>col;

    cin.ignore().get();
}

void imprimir_sala(int asientos){
    int filas=asientos/10, col=10;
    cout<<"  ";
    for(int i=1; i<=col; i++)
        printf("%2u ", i);
    cout<<endl;
    for(int i=1; i<=filas; i++){
        printf("%1c ", char(i+64));
        for(int j=1; j<=col; j++){
            printf("%2c ", '-');
        }
        cout<<endl;
    }
}

#endif // FUNCIONES_H
