#include "functions.h"

// Función para imprimir el array
void imprimir(unsigned char tablero[ALTO][ANCHO])
{
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            if (tablero[i][j] == VIVO)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        if (i < ALTO - 1)
        {
            printf("\n");

        }
    }
}

/* Función para contar vecinos vivos
validamos que no se cuente asi mismo,
que no acceda a memoria no permitida >= ALTO o >= ANCHO o <= -1 */
int contar_vecinos(unsigned char tablero[ALTO][ANCHO], int i, int j)
{
    int sum_vivos = 0;
    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int g = j - 1; g <= j + 1; g++)
        {
            if (k <= -1 || g <= -1 || k >= ALTO || g >= ANCHO || (k == i && g == j))
            {
                continue;
            }

            if (tablero[k][g] == VIVO)
            {
                sum_vivos++;
            }
        }
    }
    return sum_vivos;
}

/* En esta función con base en un tablero de elementos, 
validamos el estado de cada elemento en el siguiente tablero,
a través de los vecinos que tenga a su alrededor, a medida que
vamos leyendo un tablero, vamos escribiendo en el siguiente */
void actualizar(unsigned char (*actual)[ANCHO], unsigned char (*siguiente)[ANCHO])
{
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            int vecinos = contar_vecinos(actual, i, j);
            if (actual[i][j] == VIVO && (vecinos == 2 || vecinos == 3))
            {
                siguiente[i][j] = VIVO;
            }
            else if (actual[i][j] == MUERTO && vecinos == 3)
            {
                siguiente[i][j] = VIVO;
            }
            else
            {
                siguiente[i][j] = MUERTO;
            }
        }
    }
}

void inicializar(unsigned char (*actual)[ANCHO])
{
    srand(time(NULL));
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            actual[i][j] = rand() % 2;
        }
    }
}
