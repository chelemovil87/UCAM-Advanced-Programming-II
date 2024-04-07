#include "funciones.h"

void imprimirMenu() {
    printf("\nMenú del análisis de pueblos:\n");
    printf("1. Ver la tabla de distancias entre los pueblos.\n");
    printf("2. Mostrar qué 2 pueblos están más lejos entre sí.\n");
    printf("3. Dado un pueblo determinado, mostrar cuál es el pueblo más lejano.\n");
    printf("4. Mostrar el pueblo más céntrico.\n");
    printf("5. Calcular el número de kilómetros que hace el lechero.\n");
    printf("6. Salir.\n");
    printf("\n"); // Agrega un salto de línea después de imprimir las opciones del menú
    printf("Elige una opción: ");
}

void llenarDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO]) {
    for (int i = 0; i < NUM_PUEBLO; i++) {
        printf("Introduce la distancia desde el pueblo %d a los siguientes pueblos (en km):\n", i);
        for (int j = 0; j < NUM_PUEBLO; j++) {
            if (i == j) {
                distancias[i][j] = 0; // No se pide la distancia del pueblo a sí mismo
            } else if (j < i) {
                printf("Pueblo %d: ", j);
                scanf("%d", &distancias[i][j]);
                distancias[j][i] = distancias[i][j]; // Asigna la misma distancia para la dirección inversa
            } else {
                distancias[i][j] = -1; // Marca con -1 las distancias que no se han preguntado
            }
        }
    }
}


void imprimirTablaDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO]) {
    printf("\nTabla de distancias:\n");
    printf("   "); // Espacio para los índices de los pueblos
    for (int i = 0; i < NUM_PUEBLO; i++) {
        printf("%2d ", i); // Imprime los índices de los pueblos en el eje Y
    }
    printf("\n");
    for (int i = 0; i < NUM_PUEBLO; i++) {
        printf("%2d ", i); // Imprime los índices de los pueblos en el eje X
        for (int j = 0; j < NUM_PUEBLO; j++) {
            if (i == j) {
                printf(" - "); // Marca con un símbolo '-' las distancias del pueblo a sí mismo
            } else {
                printf("%2d ", distancias[i][j]); // Imprime la distancia entre los pueblos
            }
        }
        printf("\n");
    }
}


void encontrarPueblosMasLejos(int distancias[NUM_PUEBLO][NUM_PUEBLO]) {
    int maxDistancia = 0;
    int pueblo1 = 0, pueblo2 = 0;
    for (int i = 0; i < NUM_PUEBLO; i++) {
        for (int j = i + 1; j < NUM_PUEBLO; j++) {
            if (distancias[i][j] > maxDistancia) {
                maxDistancia = distancias[i][j];
                pueblo1 = i;
                pueblo2 = j;
            }
        }
    }
    printf("\nLos dos pueblos más alejados entre sí son el %d y el %d.\n", pueblo1, pueblo2);
}

void puebloMasLejano(int distancias[NUM_PUEBLO][NUM_PUEBLO], int pueblo) {
    int maxDistancia = 0;
    int puebloMasLejano = 0;
    for (int i = 0; i < NUM_PUEBLO; i++) {
        if (distancias[pueblo][i] > maxDistancia) {
            maxDistancia = distancias[pueblo][i];
            puebloMasLejano = i;
        }
    }
    printf("\nEl pueblo más alejado del %d es el %d.\n", pueblo, puebloMasLejano);
}

void puebloMasCentrico(int distancias[NUM_PUEBLO][NUM_PUEBLO]) {
    int sumaDistancias[NUM_PUEBLO] = {0};
    for (int i = 0; i < NUM_PUEBLO; i++) {
        for (int j = 0; j < NUM_PUEBLO; j++) {
            if (i != j) {
                sumaDistancias[i] += distancias[i][j];
            }
        }
    }
    int minSuma = sumaDistancias[0];
    int puebloMasCentrico = 0;
    for (int i = 1; i < NUM_PUEBLO; i++) {
        if (sumaDistancias[i] < minSuma) {
            minSuma = sumaDistancias[i];
            puebloMasCentrico = i;
        }
    }
    printf("\nEl pueblo más céntrico es el %d.\n", puebloMasCentrico);
}



void calcularKilometrosLechero(int (*distancias)[10]) {
    int distancia = 0;
    int puebloOrigen, puebloDestino;
    char ruta[1000];

    printf("Introduce el pueblo en el que se encuentra el lechero: ");
    scanf("%d", &puebloOrigen);
    getchar(); // consumir salto de línea
    printf("\n");

    printf("Introduce los pueblos que recorre el lechero separados por espacios: ");
    fgets(ruta, sizeof(ruta), stdin);
    printf("\n");

    char *token = strtok(ruta, " ");
    puebloDestino = atoi(token); // Establecer el primer pueblo como destino
    while (token != NULL && strcmp(token, "-1\n") != 0) {
        // Calcular la distancia desde el pueblo origen hasta el destino actual
        distancia += distancias[puebloOrigen][puebloDestino];
        puebloOrigen = puebloDestino; // Actualizar el pueblo origen al actual
        token = strtok(NULL, " ");
        if (token != NULL) {
            puebloDestino = atoi(token); // Establecer el próximo pueblo como destino
        }
    }

    printf("La distancia recorrida es: %d km.\n", distancia);
}