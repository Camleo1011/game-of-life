#if !defined(FUNCTIONS_H)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FUNCTIONS_H
#define ANCHO 50
#define ALTO 25
#define VIVO 1
#define MUERTO 0
void imprimir(unsigned char tablero[ALTO][ANCHO]);
int contar_vecinos(unsigned char tablero[ALTO][ANCHO], int i, int j);
void actualizar(unsigned char (*actual)[ANCHO], unsigned char (*siguiente)[ANCHO]);
void inicializar(unsigned char (*actual)[ANCHO]);

#endif // FUNCTIONS_H
