#include <limits.h>
#include <stdio.h>
 
//Define los vértices en la gráfica
#define V 9
 
//Función que nos sirve para encontrar el vértice con el valor de distancia más bajo
int minDistance(int dist[], bool sptSet[])
{
    //Inicializar los valores
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
//Simplemente imprime el array de distancias
int printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
//Función principal, donde se implementa el algoritmo del camino más corto de Dijkstra.
//Se representa con una gráfica utilizando representación de matriz de adyacencia
//graph[][] representa la gráfica y src representa el vértice inicial
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; //El array del output
 
    bool sptSet[V]; //True si el vértice i está incluído en el camino más corto,
    //o si el camino más corto de src a i es finalizado
 
    //Inicializando todos los valores a INFINITE, y stpSet[] a false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    //La distancia de un vértice hacia sí mismo siempre es 0
    dist[src] = 0;
 
    //Encontrar el camino más corto para todos los vértices
    for (int count = 0; count < V - 1; count++) {
        //Elegir el vértice de menor camino desde el set de vértices no procesados
        //u siempre es igual a src en la primera iteración
        int u = minDistance(dist, sptSet);
 
        //Marcar el primer vértice como procesado
        sptSet[u] = true;
 
        //Actualizar el valor dist de los vértices adyacentes del vértice elegido
        for (int v = 0; v < V; v++)
 
            //Actualizar dist[v] solo si no está en sptSet, si hay un borde de u a v,
            //y si el peso total del camino de src a v desde u es menor que el valor u to v,
            //actual de dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    //Imprimir la matriz de distancia construida
    printSolution(dist, V);
}
 
//Código para probar la función principal
int main()
{
    //Gráfica de ejemplo
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    return 0;
}
