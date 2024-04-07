#include <stdio.h>
#include "funciones.h"

int main() {
    int distancias[NUM_PUEBLO][NUM_PUEBLO] = {0};
    int opcion;

    llenarDistancias(distancias);

    do {
        imprimirMenu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                imprimirTablaDistancias(distancias);
                break;
            case 2:
                encontrarPueblosMasLejos(distancias);
                break;
            case 3:
                // Aquí necesitas pedir al usuario el número del pueblo
                int pueblo;
                printf("Introduce el número de un pueblo: ");
                scanf("%d", &pueblo);
                puebloMasLejano(distancias, pueblo);
                break;
            case 4:
                puebloMasCentrico(distancias);
                break;
            case 5:
                calcularKilometrosLechero(distancias);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}
