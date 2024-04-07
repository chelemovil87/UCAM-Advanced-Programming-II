/**
 * @file main.c
 * @version V1.0
 * 
 * Archivo que contiene la función principal del programa, que inicializa
 * la matriz de distancias, muestra un menú de opciones y ejecuta
 * las operaciones seleccionadas por el usuario.
 *
 * @author Jose Eduardo Rodriguez Fernandez
 * @date 13 Abril 2024
 */

#include "funciones.h"

/**
 * @brief Función principal del programa.
 *
 * Esta función inicializa la matriz de distancias y muestra
 * un menú de opciones al usuario y ejecuta las operaciones seleccionadas por el usuario.
 * 
 * @param distancias Matriz bidimensional que almacena las distancias entre los pueblos.
 *
 * @return 0 al finalizar el programa.
 */
#include <stdio.h>
#include "funciones.h"

/**
 * @see todas las funcines utilizadas se encuentran en el archivo funciones.c
*/
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
