
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NUM_PUEBLO 10

void imprimirMenu();
void llenarDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void imprimirTablaDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void encontrarPueblosMasLejos(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void puebloMasLejano(int distancias[NUM_PUEBLO][NUM_PUEBLO], int pueblo);
void puebloMasCentrico(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void calcularKilometrosLechero(int (*distancias)[10]);

#endif // FUNCIONES_H
