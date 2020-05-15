#include "admin.h"

/*
 Interfaz del administrador.

 Se compone de las siguientes partes:

 * Agregar peliculas
 * Mostrar reporte de ventas
 */

//Menu principal para el administrador.
//Tiene las opciones de agregar una pelicula y mostar el reporte de ventas
admin::admin()
{

}

#ifdef _WIN32
    #include <windows.h>
#endif

void admin::limpiar_pantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

bool admin::verificar()
{
    string clave, sudo;
    ifstream file("../parcial/sudo.txt");
    if(file.is_open()){
        file>>sudo;
        cout<<"Ingrese clave de administrador: "; cin>>clave;
        if(sudo==clave)
            return true;
        else
            return false;
    }
    else{
        cout<<"Error, no existe una clave de administrador.\n";
        cin.ignore().get();
        return false;
    }
}

void admin::administrador(){
    int a=0;
    limpiar_pantalla();
    if(verificar()){
        limpiar_pantalla();
        cout<<"1. Agregar pelicula\n";
        cout<<"2. Generar reporte\n";
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
    }
    else{
        cout<<"Acceso denegado."<<endl;
        cin.ignore().get();
        return;
    }
}

void admin::agregar_pelicula(){
    limpiar_pantalla();
    char nombre[20], genero[10], duracion[10], hora[5], clas[5];
    int id, sala, asientos;
    cin.ignore();
    //cin.ignore() se usa para limpiar el ultimo salto de linea en el buffer
    //y no generar errores a la hota de ingresar datos por consola
    cout<<"Nombre: "; cin.getline(nombre, 20); //Se usa cin.getline() para obtener cadenas de caracteres con espacios
    cout<<"Genero: "; cin.getline(genero, 10);
    cout<<"Duracion: "; cin.getline(duracion, 10);
    cout<<"Sala: "; cin>>sala; cin.ignore(); //Se debe usar cin.ignore() de nuevo ya que
                                             //se uso el cin y queda almacenado un salto de linea en el buffer.
    cout<<"Hora: "; cin.getline(hora, 5);
    cout<<"Clasif: "; cin.getline(clas, 5);

    //El cine tiene ya sus salas contruidas asi que cuando se le ingresa una sala
    //al momento de agregar una pelicula ya se sabe cuantos asientos tiene la respectiva sala.
    //Esto se hace con un switch-case que verifica que valor tiene la variable sala.

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
    default:
        asientos=80;
        break;

    }

    //Aqui se cuentan cuantas peluclas hay registradas para asignarle un ID a la nueva pelicula
    ifstream file("../parcial/cartelera.txt");
    char s[100];
    int cont=0;
    if(file.is_open()){ //Verifica que el archivo esta bierto correctamente
        while(!file.eof()){ //Itera hasta el final del archivo
            file.getline(s, 100); //Obtiene una linea completa del archivo
            cont++; //Por cada linea suma uno al contador que va a servir como referencia para dar un nuevo ID
        }
    }
    else
        cout<<"Error"<<endl; //Errorr en caso de no poder abrir el archivo
    file.close();
    id=cont+1; //Se le suma 1 ya que por ejemplo si hay 3 peliculas del ID de la nueva debe ser 4.
    ofstream arch("../parcial/cartelera.txt", ios::app); //Se abre como escritura al final del archivo
    if(arch.is_open()){
        //Aqui se agrega toda la informacion en una nueva linea del archivo seprado por comas (',')

        arch<<'\n';
        arch<<id<<','<<nombre<<','<<genero<<','<<duracion<<','<<sala<<','<<hora<<','<<asientos<<','<<clas<<',';
    }
    else
        cout<<"Error"<<endl;
    arch.close();
}

//Genera el reporte de las ventas que se han tenido con su fecha y hora en que se hizo la compra.
void admin::generar_reporte(){
    limpiar_pantalla();
    cout<<"<-----REPORTE DE ENTRADAS DE CINE----->\n\n";
    ifstream file("../parcial/reporte.txt"); //Abre el archivo en lectura
    char contenido[100];
    if(file.is_open()){
        // Se saca la informacion del archivo con el bucle while y se imprime en pantalla
        file.getline(contenido, 100);
        while(!file.eof()){
            cout<<contenido<<endl;
            file.getline(contenido, 100);
        }
    }
    else
        //En caso de no abrir el archivo es porque no hay un reporte aun, esto se notifica por consola
        cout<<"No hay un reporte aun..."<<endl;
    file.close();
    cin.ignore().get(); //Se pausa la consola hasta ingresar un salto de linea
}
