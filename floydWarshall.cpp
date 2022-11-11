/* 11/11/2022
Gamaliel A. Palomo B.
Analisis y Diseño de Algoritmos Avanzados TC2038

Integrantes: Kevin Fernando Meza Narvaez   | A01639770
             Diego Kury Rivera             | A00227097
             Carlos David Blanco Lizarraga | A01633323
             Karla Gonzalez Sanchez        | A01541526
			 
Algoritmo de Floyd Warshall - Algoritmos para encontar la ruta mas corta. */

#include<stdio.h>
 
// Numero de vertices en el grafo
#define V 4
 
// Definimos a infinito con un numero lo suficientemente grande. El cual se usara para los vertices que no estan conectados entre si.
#define INF 99999
 
// Funcion que imprime el resultado
void printSolution(int dist[][V]);
 
// Resuelve el problema de la ruta más corta de todos los pares
void floydWarshall (int graph[][V])
{
     // dist[][] sera la matriz de salida que va a tener el camino mas corto entre cada par de vertices
    int dist[V][V], i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    // Comparacion entre cada suma de cada par de vertices 
    for (k = 0; k < V; k++)
    {
        // Se agregan cada suma de cada par de vertices
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                //Si el vértice k está en el camino más corto desde
                // i a j, entonces se actualiza el valor de dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Imprime la matriz con el camino mas corto
    printSolution(dist);
}
 
void printSolution(int dist[][V])
{
    printf ("Matriz con el camino mas corto entre cada par de vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
int main()
{
    /* Grafo que vamos a resolver 
            2
       (A)------->(B)
        | \       /|\
      3 |  \  6    |
        |   \      | 4
       \|/    \    |
       (C)------->(D)
            9           */
    
    int graph[V][V] = { {0,   2,    3,   6},
                        {2,   0,   INF,  4},
                        {3,  INF,   0,   9},
                        {6,   4,    9,   0}
                      };



 
    // Imprimir solucion
    floydWarshall(graph);
    return 0;
}