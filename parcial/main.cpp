#include "admin.h"
#include "user.h"

//Estas directivas a continuacion permiten ejercutar la limpieza de la pantalla
//de forma que cuando se esta trabajando en windows se importa la libreria windows.h
//donde se almacena la funcion de limpieza de consola.
//En el caso de estar trabando con linux se ejecuta una funcion diferente que tambien
//permite limpiar la consola.


//Identifica en que sistema operativo se esta ejecutando el programa
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

int main()
{

    //Aqui en el main se desarrolla el menu principal donde se escoge
    //entrar como administrador o como usuario corriente.
    admin obj1;
    user obj2;
    int a=0;
    do{
        limpiar_pantalla();
        cout<<"1. Administrador\n";
        cout<<"2. Usuario\n";
        cout<<"3. Salir\n";
        cout<<"\nSelecciones una: "; cin>>a;
        switch (a) {
        case 1:
            obj1.administrador();
            break;
        case 2:
            obj2.usuario();
            break;
        }
    }while(a!=3);
    return 0;
}
