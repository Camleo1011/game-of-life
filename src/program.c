#include "functions.h"
#include <unistd.h>

int main(void)
{
    // Variables almacenamiento
    unsigned char tableroA[ALTO][ANCHO];
    unsigned char tableroB[ALTO][ANCHO];

    // Variables direccionales
    unsigned char (*actual)[ANCHO] = tableroA;
    unsigned char (*siguiente)[ANCHO] = tableroB;

    //Inicializar tablero
    inicializar(actual);
    

    // Limpiar pantalla
    printf("\033[2J");
    
    while (true)
    {
        // Mover el cursor al inicio
        printf("\033[H");

        imprimir(actual);

        actualizar(actual, siguiente);
        
        // Actuaaliar direcciones a tableros
        unsigned char (*tmp)[ANCHO] = actual;
        actual = siguiente;
        siguiente = tmp;

        // Esperar 100 milisegundos
        usleep(100000);
    }
    return 0;
}
