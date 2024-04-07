/**
 * @file funciones.c
 * @brief Archivo de implementación de las funciones para el programa.
 *
 * Este archivo contiene las implementaciones de las funciones declaradas en funciones.h.
 * Estas funciones realizan operaciones como llenar la matriz de distancias, imprimir
 * el menú de opciones, calcular distancias, y realizar otros cálculos basados en las
 * distancias entre los pueblos.
 *
 * @author Jose Eduardo Rodriguez Fernandez
 * @date 13 Abril 2024
 */
#include "funciones.h"

/**
 * @brief Imprime el menú de opciones disponibles para el usuario.
 */
void imprimirMenu()
{
    printf("\nMenú del análisis de pueblos:\n");
    printf("1. Ver la tabla de distancias entre los pueblos.\n");
    printf("2. Mostrar qué 2 pueblos están más lejos entre sí.\n");
    printf("3. Dado un pueblo determinado, mostrar cuál es el pueblo más lejano.\n");
    printf("4. Mostrar el pueblo más céntrico.\n");
    printf("5. Calcular el número de kilómetros que hace el lechero.\n");
    printf("6. Salir.\n");
    printf("\n");
    printf("Elige una opción: ");
}

/**
 * @brief Llena la matriz de distancias con los valores ingresados por el usuario.
 * @param distancias Matriz bidimensional que almacena las distancias entre los pueblos.
 */
void llenarDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO])
{
    for (int i = 0; i < NUM_PUEBLO; i++)
    {
        printf("Introduce la distancia desde el pueblo %d a los siguientes pueblos (en km):\n", i);
        for (int j = 0; j < NUM_PUEBLO; j++)
        {
            if (i == j)
            {
                /**
                 * @note No se pide la distancia del pueblo a sí mismo
                 */
                distancias[i][j] = 0;
            }
            else if (j < i)
            {
                printf("Pueblo %d: ", j);
                scanf("%d", &distancias[i][j]);
                /**
                 * @note Asigna la misma distancia para la dirección inversa
                 */
                distancias[j][i] = distancias[i][j];
            }
            else
            {
                /**
                 * @note // Marca con -1 las distancias que no se han preguntado
                 */
                distancias[i][j] = -1;
            }
        }
    }
}

/**
 * @brief Imprime la tabla de distancias entre los pueblos.
 * @param distancias Matriz bidimensional que contiene las distancias entre los pueblos.
 */
void imprimirTablaDistancias(int distancias[NUM_PUEBLO][NUM_PUEBLO])
{
    printf("\nTabla de distancias:\n");
    printf("   "); // Espacio para los índices de los pueblos
    for (int i = 0; i < NUM_PUEBLO; i++)
    { /**
       * @note Imprime los índices de los pueblos en el eje Y
       */
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < NUM_PUEBLO; i++)
    { /**
       * @note Imprime los índices de los pueblos en el eje X
       */
        printf("%2d ", i);
        for (int j = 0; j < NUM_PUEBLO; j++)
        {
            if (i == j)
            { /**
               * @note Marca con un símbolo '-' las distancias del pueblo a sí mismo
               */
                printf(" - ");
            }
            else
            { /**
               * @note Imprime la distancia entre los pueblos
               */
                printf("%2d ", distancias[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Encuentra y muestra los dos pueblos más lejos entre sí.
 *
 * Esta función recorre la matriz de distancias para encontrar la distancia máxima
 * entre dos pueblos y luego muestra los dos pueblos que están a esa distancia máxima.
 *
 * @param distancias Matriz bidimensional que contiene las distancias entre los pueblos.
 *                   Cada elemento distancias[i][j] representa la distancia entre el pueblo i y el pueblo j.
 *
 * @note La función asume que la matriz de distancias ya ha sido llenada con los valores correctos.
 */
void encontrarPueblosMasLejos(int distancias[NUM_PUEBLO][NUM_PUEBLO])
{
    int maxDistancia = 0;
    int pueblo1 = 0, pueblo2 = 0;
    for (int i = 0; i < NUM_PUEBLO; i++)
    {
        for (int j = i + 1; j < NUM_PUEBLO; j++)
        {
            if (distancias[i][j] > maxDistancia)
            {
                maxDistancia = distancias[i][j];
                pueblo1 = i;
                pueblo2 = j;
            }
        }
    }
    printf("\nLos dos pueblos más alejados entre sí son el %d y el %d.\n", pueblo1, pueblo2);
}

/**
 * @brief Muestra el pueblo más lejano de un pueblo dado.
 *
 * Esta función recorre la matriz de distancias para encontrar el pueblo más lejano
 * del pueblo especificado por el usuario y luego muestra ese pueblo.
 *
 * @param distancias Matriz bidimensional que contiene las distancias entre los pueblos.
 *                   Cada elemento distancias[i][j] representa la distancia entre el pueblo i y el pueblo j.
 * @param pueblo Número del pueblo del cual se quiere encontrar el pueblo más lejano.
 *
 * @note La función asume que la matriz de distancias ya ha sido llenada con los valores correctos.
 */
void puebloMasLejano(int distancias[NUM_PUEBLO][NUM_PUEBLO], int pueblo)
{
    int maxDistancia = 0;
    int puebloMasLejano = 0;
    for (int i = 0; i < NUM_PUEBLO; i++)
    {
        if (distancias[pueblo][i] > maxDistancia)
        {
            maxDistancia = distancias[pueblo][i];
            puebloMasLejano = i;
        }
    }
    printf("\nEl pueblo más alejado del %d es el %d.\n", pueblo, puebloMasLejano);
}
/**
 * @brief Muestra el pueblo más céntrico.
 *
 * La función calcula la suma de distancias de cada pueblo a todos los demás pueblos
 * y luego muestra el pueblo con la menor suma total. El pueblo más céntrico es aquel
 * que tiene la menor suma total de distancias a todos los demás pueblos, lo que indica
 * que es el punto medio o central en términos de conectividad entre los pueblos.
 *
 * @param distancias Matriz bidimensional que contiene las distancias entre los pueblos.
 *                   Cada elemento distancias[i][j] representa la distancia entre el pueblo i y el pueblo j.
 *
 * @note La función asume que la matriz de distancias ya ha sido llenada con los valores correctos.
 */
void puebloMasCentrico(int distancias[NUM_PUEBLO][NUM_PUEBLO])
{
    int sumaDistancias[NUM_PUEBLO] = {0};
    for (int i = 0; i < NUM_PUEBLO; i++)
    {
        for (int j = 0; j < NUM_PUEBLO; j++)
        {
            if (i != j)
            {
                sumaDistancias[i] += distancias[i][j];
            }
        }
    }
    int minSuma = sumaDistancias[0];
    int puebloMasCentrico = 0;
    for (int i = 1; i < NUM_PUEBLO; i++)
    {
        if (sumaDistancias[i] < minSuma)
        {
            minSuma = sumaDistancias[i];
            puebloMasCentrico = i;
        }
    }
    printf("\nEl pueblo más céntrico es el %d.\n", puebloMasCentrico);
}

/**
 * @brief Calcula la distancia total recorrida por el lechero.
 *
 * Esta función solicita al usuario que ingrese el pueblo de origen y una lista de pueblos
 * que el lechero visita. Luego, calcula la distancia total recorrida por el lechero
 * sumando las distancias entre cada par de pueblos consecutivos en la ruta.
 *
 * @param distancias Puntero a la matriz bidimensional que contiene las distancias entre los pueblos.
 *                   Cada elemento distancias[i][j] representa la distancia entre el pueblo i y el pueblo j.
 * 
 * @note utilizo la funcion strtok para dividir el string de pueblos en token o subcadenas
 *  y delimitandolas con el espacio " ". Despues utilizo el atoi para convertir el token en entero
 *  y el strcmp para validar la condicion y asi poder comenzar el bucle que calcula los km.
 * 
 */
void calcularKilometrosLechero(int (*distancias)[10])
{
    int distancia = 0;
    int puebloOrigen, puebloDestino;
    char ruta[1000];

    printf("Introduce el pueblo en el que se encuentra el lechero: ");
    scanf("%d", &puebloOrigen);
    getchar(); // consume el salto de línea
    printf("\n");

    printf("Introduce los pueblos que recorre el lechero separados por espacios: ");
    fgets(ruta, sizeof(ruta), stdin);
    printf("\n");

    char *token = strtok(ruta, " ");
    /** 
     * @note Establecer el primer pueblo como destino
    */
    puebloDestino = atoi(token); 
    while (token != NULL && strcmp(token, "-1\n") != 0)
    {
        /**
         * @note Calcular la distancia desde el pueblo origen hasta el destino actual
         */
        distancia += distancias[puebloOrigen][puebloDestino];
        /**
         * @note Actualizar el pueblo origen al actual
         */
        puebloOrigen = puebloDestino;
        token = strtok(NULL, " ");
        if (token != NULL)
        {
            /**
             * @note Establecer el próximo pueblo como destino
             */
            puebloDestino = atoi(token);
        }
    }

    printf("La distancia recorrida es: %d km.\n", distancia);
}