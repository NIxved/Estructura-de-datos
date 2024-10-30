/****************************************
Autor: David Leon
Fecha: 30 de octubre 2024
Materia: Estructura de Datos
Tema:Laboratorio Grafos
****************************************/
#include <iostream>
#include <limits.h> 
using namespace std;

int miniDist(int distance[], bool Tset[], int size) {
    int minimum = INT_MAX, ind;

    for (int k = 0; k < size; k++) {
        if (!Tset[k] && distance[k] <= minimum) {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[7][7], int src, int size) {
    int distance[7]; 
    bool Tset[7];  

    
    for (int k = 0; k < size; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0;


    for (int k = 0; k < size; k++) {
        int m = miniDist(distance, Tset, size);
        Tset[m] = true;

        for (int k = 0; k < size; k++) {
            
            if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX &&
                distance[m] + graph[m][k] < distance[k]) {
                distance[k] = distance[m] + graph[m][k];
            }
        }
    }


    cout << "Vértice\t\tDistancia desde la fuente" << endl;
    for (int k = 0; k < size; k++) {
        char str = 65 + k; 
        cout << str << "\t\t" << distance[k] << endl;
    }
}

int main() {
    //matriz del grafo de la clase//
    int graph[7][7] = {
        {0, 2, 4, 0, 0, 0, 0}, 
        {2, 0, 0, 5, 0, 0, 0}, 
        {4, 0, 0, 8, 0, 0, 0}, 
        {0, 5, 8, 0, 10, 15, 0}, 
        {0, 0, 0, 10, 0, 6, 2}, 
        {0, 0, 0, 15, 6, 0, 6}, 
        {0, 0, 0, 0, 2, 2, 0}   
    };
/******************************
matriz original:
 
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };


    DijkstraAlgo(graph, 0, 6);
*******************************/
    DijkstraAlgo(graph, 0, 7);
    return 0;
}
