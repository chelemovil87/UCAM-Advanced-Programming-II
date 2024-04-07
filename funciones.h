/**
 * @file funciones.h
 * @brief Archivo de cabecera con las declaraciones de funciones para el análisis de distancias entre pueblos.
 *
 * Este archivo contiene las declaraciones de las funciones utilizadas en el programa
 * para llenar la matriz de distancias, imprimir el menú de opciones, calcular
 * distancias, y realizar otros cálculos basados en las distancias entre los pueblos.
 *
 * @author Jose Eduardo Rodriguez Fernandez
 * @date 13 Abril 2024
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

/**
 * @note librerias del lenguaje para utilizar en main a trabes de la cabecera de funciones.h
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** 
 * @details Aqui se definen el numero de pueblo especificado en la PEC y se utilizan los prototipos de todas las 
 * funciones para utilizar en el main con solo un include
*/
#define NUM_PUEBLO 10

void imprimirMenu();
void llenarDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void imprimirTablaDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void encontrarPueblosMasLejos(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void puebloMasLejano(int distancias[NUM_PUEBLO][NUM_PUEBLO], int pueblo);
void puebloMasCentrico(int distancias[NUM_PUEBLO][NUM_PUEBLO]);
void calcularKilometrosLechero(int (*distancias)[10]);

#endif 
