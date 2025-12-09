#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define v 5

int minDistance(int dist[], int visited[]){
    int min = INT_MAX, index = -1;
    for(int i = 0; i< v; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra_algo(int graph[v][v], int src){
    int dist[v], visited[v];

    for(int i = 0; i<v; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int i = 0; i< v-1; i++){
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for(int j = 0; j<v; j++){
            if(!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]){
                dist[j] = dist[u] + graph[u][j];

            }
        }
        
    }

    for(int i = 0; i< v; i++){
        printf("%d ", dist[i]);
    }
}


int main(){
    int graph[v][v] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };
    printf("HI");
    Dijkstra_algo(graph, 0);
    dis(graph, 0);
}