#include <iostream>
#include "printHamiltonPath.hpp"

using namespace std;
#define V 5

void nextVertex(bool adjacency[V][V], int path[], int k){
    while(true){
        bool duplicate = false; 
        if ((path[k] + 1) > (V - 1)){
            path[k] = -1;
        } else {
            path[k] = path[k] + 1; 
        }
        if (path[k] == (-1)){
            return; 
        }
        if (adjacency[path[k-1]][path[k]]){
            for (int i = 0; i < k; i++){
                if (path[i] == path[k]){
                    duplicate = true; 
                    break;
                }
            }
            if (duplicate == false){
                if ((k < (V-1)) || ((k == (V-1)) && (adjacency[path[0]][path[k]]))){    
                    return; 
                }
            }
        }   
    }  
}

void hamiltonianPath(bool adjacency[V][V], int path[], int k){
    while(true){
        nextVertex(adjacency, path, k); 
        if (path[k] == (-1)){
            return;
        }
        if (k == (V- 1)){
            printHamiltonPath(path, V); 
        } else {
            hamiltonianPath(adjacency, path, (k+1));
        }
    }    
}

int main(int argc, char** argv) {
    /* reprezentaciu grafov graph1 a graph3 som zobral zo stranky 
       https://www.geeksforgeeks.org/hamiltonian-cycle-backtracking-6/
       vysledky su korektne */
    
    bool graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};
    bool graph2[V][V] = {{0, 1, 1, 0, 1},  
                         {1, 0, 1, 1, 0},  
                         {1, 1, 0, 1, 1},  
                         {0, 1, 1, 0, 1},  
                         {1, 0, 1, 1, 0}}; 
    bool graph3[V][V] = {{0, 1, 0, 1, 0},  
                         {1, 0, 1, 1, 1},  
                         {0, 1, 0, 0, 1},  
                         {1, 1, 0, 0, 0},  
                         {0, 1, 1, 0, 0}};  

    
    int *path = new int[V]; 
    path[0] = 0; 
    for (int i = 1; i < V; i++){
        path[i] = (-1);
    }
    hamiltonianPath(graph1, path, 1);

    cout << endl;
    
    path[0] = 0; 
    for (int i = 1; i < V; i++){
        path[i] = (-1);
    }
    hamiltonianPath(graph2, path, 1);
    
    cout << endl; 
    
    path[0] = 0; 
    for (int i = 1; i < V; i++){
        path[i] = (-1);
    }
    hamiltonianPath(graph2, path, 1);
    
    return 0;
}

