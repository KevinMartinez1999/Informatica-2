#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <map>

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
void imprimir_sala(string, map<char, int> &);
void comprar(string, char, char, char, map<char, int> &);
void reporte(map<char, int> &, char, char);

void menu(){
    int a=0;
    do{
        limpiar_pantalla();
        cout<<"1. Administrador\n";
        cout<<"2. Usuario\n";
        cout<<"3. Salir\n";
        cout<<"\nSelecciones una: "; cin>>a;
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
        cout<<"2. Generar registro\n";
        cout<<"3. Salir\n";
        cout<<"\nSelecciones una: "; cin>>a;
        switch (a) {
        case 1:
            agregar_pelicula();
            break;
        case 2:
            generar_reporte();
            break;
        default:
            break;
        }
    }while(a!=3);
}

void agregar_pelicula(){
    limpiar_pantalla();
    char nombre[20], genero[10], duracion[10], hora[5], clas[5];
    int id, sala, asientos;
    cin.ignore();
    cout<<"Nombre: "; cin.getline(nombre, 20);
    cout<<"Genero: "; cin.getline(genero, 10);
    cout<<"Duracion: "; cin.getline(duracion, 10);
    cout<<"Sala: "; cin>>sala; cin.ignore();
    cout<<"Hora: "; cin.getline(hora, 5);
    cout<<"Clasif: "; cin.getline(clas, 5);
    switch (sala) {
        case 1:
            asientos=50;
            break;
        case 2:
        case 3:
        case 4:
        case 7:
            asientos=140;
            break;
        case 5:
        case 6:
            asientos=100;
            break;
    }
    ifstream file("../parcial/cartelera.txt");
    char s[100];
    int cont=0;
    if(file.is_open()){
        while(!file.eof()){
            file.getline(s, 100);
            cont++;
        }
    }
    else
        cout<<"Error"<<endl;
    file.close();
    id=cont+1;
    ofstream arch("../parcial/cartelera.txt", ios::app);
    if(arch.is_open()){
        arch<<'\n';
        arch<<id<<','<<nombre<<','<<genero<<','<<duracion<<','<<sala<<','<<hora<<','<<asientos<<','<<clas<<',';
    }
    else
        cout<<"Error"<<endl;
    arch.close();
}

void generar_reporte(){
    limpiar_pantalla();
    cout<<"<-----REPORTE DE ENTRADAS DE CINE----->\n\n";
    ifstream file("../parcial/reporte.txt");
    string s;
    if(file.is_open()){
        file>>s;
        while(!file.eof()){
            cout<<s<<endl;
            file>>s;
        }
    }
    else
        cout<<"No hay un reporte aun..."<<endl;
    cin.ignore().get();
}

void user(){
    limpiar_pantalla();
    int id=mostrar_funciones();
    string sala=seleccionar_funcion(id);
    seleccionar_asiento(sala);
}

int mostrar_funciones(){
    int cont, op, num=0;
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
        num++;
        cout<<endl;
    }
    file.close();
    cout<<"Seleccionar (ID): "; cin>>op;
    while(op>num){
        cout<<"Esta funcion no existe.\n";
        cout<<"Seleccionar (ID): "; cin>>op;
    }
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
    map<char, int> costos;
    costos['1']=7900; costos['2']=10800; costos['3']=9900; costos['4']=11900;
    printf("%4s  ", "Tipo"); printf("%13s  ", "Clasificacion"); printf("%6s  ", "Costo"); printf("%7s\n\n", "Simbolo");
    printf("%4s  ", "1"); printf("%13s  ", "General 2D"); printf("%6u  ", costos['1']); printf("%4c\n", '-');
    printf("%4s  ", "2"); printf("%13s  ", "General 3D"); printf("%6u  ", costos['2']); printf("%4c\n", '-');
    printf("%4s  ", "3"); printf("%13s  ", "VibroSound 2D"); printf("%6u  ", costos['3']); printf("%4c\n", '=');
    printf("%4s  ", "4"); printf("%13s  ", "VibroSound 3D"); printf("%6u  ", costos['4']); printf("%4c\n", '=');
    cout<<"<----------------------------"
          "----------    /    ----------"
          "---------------------------->\n\n";
    int op=stoi(sala)-3;
    switch(op){
    case 1:
        imprimir_sala("../parcial/salas/sala1.txt", costos);
        break;
    case 2:
    case 3:
    case 4:
    case 7:
        imprimir_sala("../parcial/salas/sala2347.txt", costos);
        break;
    case 5:
    case 6:
        imprimir_sala("../parcial/salas/sala56.txt", costos);
        break;
    }
}

void imprimir_sala(string sala, map<char, int> &costos){
    char letra=65;
    cout<<"  ";
    for(int i=1; i<=10; i++)
        printf("%2u ", i);
    cout<<endl;
    ifstream file(sala);
    char contenido;
    int cont=0;
    if(file.is_open()){
        printf("%1c ", char(letra++));
        file>>contenido;
        while(!file.eof()){
            if(cont==10){
                cout<<endl;
                printf("%1c ", char(letra++));
                cont=0;
            }
            printf("%2c ", contenido);
            file>>contenido;
            cont++;
        }
    }
    else
        cout<<"No abierto..."<<endl;

    char fila, col, gafas;
    cout<<"\n\nSelecciona fila: "; cin>>fila;
    fila=toupper(fila);
    while(int(fila)<65 and int(fila)>90){
        cout<<"Asiento no disponible...\n";
        cout<<"\n\nSelecciona fila: "; cin>>fila;
        fila=toupper(fila);
    }
    cout<<"Selecciona columna: "; cin>>col;
    while(int(col<49) and int(col)>57){
        cout<<"Asiento no disponible...\n";
        cout<<"\n\nSelecciona columna: "; cin>>col;
    }
    cout<<"Gafas 3D (y/n):"; cin>>gafas;
    gafas=tolower(gafas);
    while(gafas!='y' and gafas!='n'){
        cout<<"Gafas 3D (y/n):"; cin>>gafas;
        gafas=tolower(gafas);
    }
    comprar(sala, fila, col, gafas, costos);
}

void comprar(string sala, char fila, char col, char gafas, map<char, int> &costos){
    map<char, int> mapa1;
    map<char, int> mapa2;
    int pos;
    int val_fila=0, val_col=1;
    for(int i=65; i<=90; i++){
        mapa1[char(i)]=val_fila;
        val_fila+=10;
    }
    for(int i=1; i<=10; i++){
        mapa2[char(i+48)]=val_col;
        val_col++;
    }
    pos=mapa1[fila]+mapa2[col];
    int cont=0, saltos=0;
    ofstream salida("../parcial/salas/nuevo.txt");
    ifstream file(sala);
    char contenido;
    if(file.is_open()){
        file>>contenido;
        cont++;
        saltos++;
        while(!file.eof()){
            if(cont==pos){
                salida<<'x';
                if(saltos==10){
                    salida<<'\n';
                    saltos=0;
                }
                reporte(costos, contenido, gafas);
            }
            else{
                salida<<contenido;
                if(saltos==10){
                    salida<<'\n';
                    saltos=0;
                }
            }
            cont++;
            saltos++;
            file>>contenido;
        }
    }
    file.close();
    salida.close();
    remove(sala.c_str());
    rename("../parcial/salas/nuevo.txt", sala.c_str());
}

void reporte(map<char, int> &costos, char contenido, char gafas){
    int valor=0;
    if(contenido=='='){
        if(gafas=='y')
            valor=costos['4'];
        else
            valor=costos['3'];
    }
    else if(contenido=='-'){
        if(gafas=='y')
            valor=costos['2'];
        else
            valor=costos['1'];
    }
    ofstream file("../parcial/reporte.txt");
    file<<valor<<'\n';
    file.close();
}

#endif // FUNCIONES_H
