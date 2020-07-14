#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //Librearia para hacer uso de los hilos

//Este es el hilo de ejecución
void *hilo(void *data)
{
    char *texto = (char *) data; //Texto que va a imprimir cada hilo para distinguirlos.
    struct timespec tiempo = {2, 0}; //Se hace un proceso cada 2 segundos.
    while(1)
    {
        //Se queda en este while hasta que se cierra el programa pero a su vez
        //tambien se esta ejecutando otro while infinito paralelamente.
        printf("%s\n", texto);
        pthread_delay_np(&tiempo);
    }
}

int main(void)
{
    //Se crean los hilos
    pthread_t hilo1;
    pthread_t hilo2;

    //Se preparan los hilos de ejecucion. Cada uno va a imprimir una palabra distinta
    //que va a servir para identificar cuando se ejecuta cada hilo.
    pthread_create(&hilo1, NULL, &hilo, "Hilo1");
    pthread_create(&hilo2, NULL, &hilo, "Hilo2");

    //Se ejecutan los hilos en paralelo y muestran sus resultados finales
    //en el hilo principal del programa una vez finalicen.
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    return 0;
}

/*SALIDA DEL PROGRAMA EN CONSOLA

 Va a poder notar que en cada ciclo se imprimen los dos textos a la misma vez
 y tambien que no siempre se va a imprimir primero el Hilo1 que el Hilo2, lo que
 claramente muestra que la ejecución es en paralelo.


 Hilo1
 Hilo2 --Primer ciclo
 Hilo2
 Hilo1 --Segundo ciclo
 Hilo2
 Hilo1 --Tercer ciclo
 Hilo1
 Hilo2 --Cuarto ciclo
 Hilo2
 Hilo1 --Quinto ciclo
 Hilo2
 Hilo1 --Sexto ciclo
 */
