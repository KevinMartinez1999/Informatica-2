#include "user.h"

/*
 Interfaz del usuario.

 Se compone de las siguientes partes:

 * Una ventana donde se muestran las peliculas en cartelera
 * Una ventana donde se muestran los precios y los asientos disponibles
 */

//En este interfaz se ejecuta todo el proceso de compra de una entrada,
//seactualizan las bases de datos de asientos disponibles de cada sala y
//el reporte de ventas.
user::user()
{

}

#ifdef _WIN32
    #include <windows.h>
#endif

void user::limpiar_pantalla(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

void user::usuario(){
    limpiar_pantalla();
    int id=mostrar_funciones();
    string sala=seleccionar_funcion(id);
    seleccionar_asiento(sala, id);
}

//Muestra las funciones que hay en el momento, su nombre, sala, asientos disponibles, etc.
int user::mostrar_funciones(){
    // 'cont' controla cuando el token esta parado en el nombre
    // 'op' es la opcion quue toma el usuario de que pelicula quiere ver
    // 'num' es el numero de peliculas que hay disponibles, op no puede ser mayor que num para garantizar existencia de las peliculas
    int cont, op, num=0;

    //Aqui se imprime el encabezdo de la cartelera
    cout<<endl;
    cout<<"<----------------------------"
          "----------FUNCIONES----------"
          "---------------------------->\n\n";
    printf("%2s", "ID"); printf("%20s ", "Nombre"); printf("%10s ", "Genero"); printf("%10s ", "Duracion");
    printf("%10s ", "Sala"); printf("%10s ", "Hora"); printf("%10s ", "Asientos"); printf("%10s\n\n", "Clasif.");


    string contenido; //Es el contenido de cada linea del archivo que se va a leer
    char *token; //El token es un puntero a char que va a guardar los datos separados por comas (',')
    ifstream file("../parcial/cartelera.txt");
    while(!file.eof()){
        cont=0;
        getline(file, contenido); //Se obtiene cada linea del archivo
        char cadena[100]="";//Esta cadena es necesaria ya que la funcion strtok solo recibe arreglos de char y no string
        for(int i=0; i<int(contenido.size()); i++)
            //En este for se transforma el string de contenido a un arreglo de char
            cadena[i]=contenido[i];

        //La funcion se usa para obtener datos de un arreglo que estan separados
        //por algun separador especifico, en este caso el separador es la coma (',')
        token=strtok(cadena, ","); //Casa el primer dato
        if(token!=NULL)
            cout<<token<<' ';
        while(token!=NULL){
            //Recorre todo el archivo hasta que el token sea NULL
            //lo que significa que llegó a su fin
            token=strtok(NULL, ","); //Saca un dato con cada iteracion
            if(cont==0){
                //Cuando cont=0 significa que esta parado en el nombre, solo en este caso se imprime
                //con 20 espacios para garantizar que el nombre se imprima completo, para los demas casos
                //solo se le dan 10 espacios.
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
    cout<<"Seleccionar (ID): "; cin>>op; //Seleccion de la pelicula
    while(op>num){
        cout<<"Esta funcion no existe.\n";
        cout<<"Seleccionar (ID): "; cin>>op;
    }
    return op; //retorna el ID de la pelocula que esogió el usuario
}

// La funcion anterior retorna un ID, ese mismo ID se le pasa a esta funcion y busca
// la sala correspondiente de es ID
string user::seleccionar_funcion(int a){
    string contenido, sala;
    char *token;
    int cont=1, col;
    ifstream file("../parcial/cartelera.txt");
    while(!file.eof()){

        //El proceso de encontrar la sala correspondiente es muy
        //similar al proceso de la funcion mostrar_funciones().
        //Se hace uso de un token y se separan los datos del arhivo
        //por comas (',').
        //Cuando el token sea igual a el ID entonces estamos ubucados en
        //la pelicula correcta.

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
                        // 4 es la columna donde esta ubicada la sala de cada ID
                        sala=token;
                        file.close();
                        return sala;
                    }
            }
        }
        cont++;
    }
    file.close();
    return NULL;
}

void user::seleccionar_asiento(string sala, int id){
    limpiar_pantalla();

    //Aqui se imprime la tabla de valores de cada uno de los asientos
    //Se usó un mapa para guardar los precios segun el simbolo que tengan.
    //para las sillas normales '-' y para las vibrosound '='.

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

    //Aqui dependiendo de la sala que que se escogio debido al ID que el
    //usuario escogio anteriormente se imprime la sala con todos sus asientos,
    //disponibles y no disponibles marcdos con una 'x'.

    switch(stoi(sala)){
    case 1:
        imprimir_sala("../parcial/salas/sala1.txt", costos, id);
        break;
    case 2:
        imprimir_sala("../parcial/salas/sala2.txt", costos, id);
        break;
    case 3:
        imprimir_sala("../parcial/salas/sala3.txt", costos, id);
        break;
    case 4:
        imprimir_sala("../parcial/salas/sala4.txt", costos, id);
        break;
    case 7:
        imprimir_sala("../parcial/salas/sala7.txt", costos, id);
        break;
    case 5:
        imprimir_sala("../parcial/salas/sala5.txt", costos, id);
        break;
    case 6:
        imprimir_sala("../parcial/salas/sala6.txt", costos, id);
        break;
    }
}

//Se encarga de imprimir la sala requerida.
void user::imprimir_sala(string sala, map<char, int> &costos, int id){
    char letra=65; //Hace referencia a la A
    cout<<"  ";
    for(int i=1; i<=10; i++) //imprime las 10 columnas numeradas del 1-10
        printf("%2u ", i);
    cout<<endl;
    ifstream file(sala);
    char contenido; //Con este char se sacan los datos del archivo
    int cont=0; //Controla cuando debe haber un salto de linea para imprimir correctamente

    if(file.is_open()){
        printf("%1c ", char(letra++));
        file>>contenido;
        while(!file.eof()){
            if(cont==10){ //Como son 10 columnas, cuando cont=10 hace un salto y reinicia la variable
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

    file.close();
    char fila, col, gafas;
    cout<<"\n\nSelecciona fila: "; cin>>fila;
    fila=toupper(fila); //En caso de ingresar fila con una letra minuscula se transforma a mayuscula
    while(int(fila)<65 and int(fila)>90){ //El caracter debe estar entre el rango de las mayusculas segun el codigo ASCII
        cout<<"Asiento no disponible...\n";
        cout<<"\n\nSelecciona fila: "; cin>>fila;
        fila=toupper(fila);
    }
    cout<<"Selecciona columna: "; cin>>col;
    while(int(col<49) and int(col)>57){ //El caracter debe estar entre el rango de los numeros segun el codigo ASCII
        cout<<"Asiento no disponible...\n";
        cout<<"\n\nSelecciona columna: "; cin>>col;
    }
    cout<<"Gafas 3D (y/n):"; cin>>gafas;
    gafas=tolower(gafas); //En caso de ingresar una letra mayuscula se transforma a minuscula
    while(gafas!='y' and gafas!='n'){
        cout<<"Gafas 3D (y/n):"; cin>>gafas;
        gafas=tolower(gafas);
    }
    comprar(id, sala, fila, col, gafas, costos); //Luego de todo el proceso de seleccion, se procede a hacer la compra
}

void user::comprar(int id, string sala, char fila, char col, char gafas, map<char, int> &costos){
    map<char, int> mapa1; //controla las filas de las salas
    map<char, int> mapa2; //Controla las columnas de las salas
    int pos;
    int val_fila=0, val_col=1;
    for(int i=65; i<=90; i++){

        //Viendo la sala como una matriz y recorriendola uno a uno
        //se puede notar que cada que pasa a una nueva fila se recorrieron
        //10 elementos, por eso se le suma 10 a cada letra, se vería asi:
        /*
         * A=0
         * B=10
         * C=20
         * .
         * .
         * .
         * Z=250
         */

        mapa1[char(i)]=val_fila;
        val_fila+=10;
    }
    for(int i=1; i<=10; i++){

        //Como la matriz se recorre componente a componente entonces solo
        //suma 1 a cada numero de la columna, se ver+ia asi:
        /*
         * col1=1
         * col2=2
         * col3=3
         * .
         * .
         * .
         * col10=10
         */

        mapa2[char(i+48)]=val_col;
        val_col++;
    }

    //pos es la posicion final donde esta ubicado el asiento deseado
    pos=mapa1[fila]+mapa2[col];

    //cont es la variable que verifica cuando llega a pos
    //saltos controla cuando hay que dar un salto de linea a la hora de escribir en el nuevo archivo
    int cont=0, saltos=0;

    //Se crea un archivo nuevo.txt para guardar los cambios.
    //file solo sirve para leer y luego se borra para ser reeemplazada
    //por el nuevo archivo que contiene los cambios.

    ofstream salida("../parcial/salas/nuevo.txt");
    ifstream file(sala);
    char contenido;
    if(file.is_open()){
        file>>contenido;
        cont++;
        saltos++;
        while(!file.eof()){
            if(cont==pos){
                //cuando cumple la condicion se le manda 'x', que significa asiento reservado,
                //a la posicion deseada y quedar guardada en el archivo
                salida<<'x';
                if(saltos==10){
                    salida<<'\n';
                    saltos=0;
                }

                reporte(costos, contenido, gafas);//cuando ya esta lista la compra se hace un reporte de la compra
                asientos_disp(id); //Se actualiza la base de datos de las salas con el asiento reservado
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

    //Se debe borra el archivo actual y reemplazarlo con el nuevo para guardar la informacion
    //que se actualizó
    remove(sala.c_str());
    rename("../parcial/salas/nuevo.txt", sala.c_str());
}

void user::reporte(map<char, int> &costos, char contenido, char gafas){
    time_t fecha_hora=time(NULL); //time_t obtiene la fecha y hora del sistema en segundos
    char *time=ctime(&fecha_hora); //Obtiene la fecha y hora actual en forma de string
    int valor=0;

    //Se verifica cual fue la compra, asientos normales o vibrosound, gafas 3D o no.
    if(contenido=='='){ //Asiento con vibrosound
        if(gafas=='y') //Con gafas 3D
            valor=costos['4'];
        else //Sin gafas 3D
            valor=costos['3'];
    }
    else if(contenido=='-'){ //Asiento sin vibrosound
        if(gafas=='y') //Con gafas 3D
            valor=costos['2'];
        else //Sin gafas 3D
            valor=costos['1'];
    }

    //Depues de verificar cual fue la compra se procede a escribirla en el reporte
    //con su respectivo valor de compra y la fecha y hora actual.
    ofstream file("../parcial/reporte.txt", ios::app);
    file<<valor<<" Hora local: "<<time<<'\n';
    file.close();
}

int user::contar_id()
{
    int cont=0;
    string contenido;
    ifstream file("../parcial/cartelera.txt");
    if(file.is_open()){
        getline(file, contenido);
        cont++;
        while(!file.eof()){
            getline(file, contenido);
            cont++;
        }
    }
    file.close();
    return cont;
}

//Se actualiza la cartelera con la cantidad de asientos que quedan disponibles
void user::asientos_disp(int id){

    //En esta funcion nuevamente se hace uso del token para
    //lograr obtener los datos separados por una coma (',')

    string contenido;
    char *token;
    int cont=1, num=0;

    ofstream arch("../parcial/nuevo.txt");
    ifstream file("../parcial/cartelera.txt");
    while(!file.eof()){
        getline(file, contenido); //obtiene linea por linea el contenido del archivo
        num++;
        //Solo en el caso de que cont corresponda al ID de la pelicula seleccionada se va a meter
        //a la condicion para realizar el cambio.
        //En caso de no cincidir el ID se le pasa al nuevo archivo tal cual, sin modificaciones.

        if(cont==id){
            int c; //controla cuando el token es igual al numero de asientos que es lo que se va a actualizar
            char cadena[100]="";
            for(int i=0; i<int(contenido.size()); i++) //se transforma el string cadena a un arreglo
                cadena[i]=contenido[i];
            token=strtok(cadena, ","); //Se obtiene el token separado por coma (',')
            c=1; //Se inicializa c en 1 que es la posicion donde esta ubicado el ID
            while(token!=NULL){
                if(c==7) //7 es la posicion del numero de asientos que se va a editar
                    arch<<stoi(token)-1<<','; //se actualiza restando 1 a ese numero actual de asientos
                else
                    //Como no es el numero de asientos se para tal cual al nuevo archivo.
                    arch<<token<<',';
                token=strtok(NULL, ","); //se busca el siguiente dato.
                c++;
            }
            arch<<'\n';
        }
        else{
            //Se le pasa al nuevo archivo sin modificaciones.
            if(num==contar_id()){
                arch<<contenido;
            }
            else
                arch<<contenido<<'\n';
        }
        cont++;

    }
    file.close();
    arch.close();

    //Se crea un archivo nuevo.txt para guardar los cambios.
    //cartelera.txt solo sirve para leer y luego se borra para ser reeemplazada
    //por el nuevo archivo que contiene los cambios.
    remove("../parcial/cartelera.txt");
    rename("../parcial/nuevo.txt", "../parcial/cartelera.txt");
}
