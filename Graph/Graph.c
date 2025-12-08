#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph{
    int numVertices;
    Node** adjList;
} Graph;

Node* createNode(int v){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    graph->numVertices = numVertices;

    for(int i = 0; i<numVertices; i++){
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest){
    Node* newNode = createNode(dest);

    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);

    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void deleteEdge(Graph* graph, int src, int dest){
    Node* temp = graph->adjList[src];
    Node* prev = NULL;
    while (temp != NULL && temp->vertex != dest)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\nEdge Not Found");
        return;
    }

    if(prev == NULL){
        graph->adjList[src] = temp->next;
    }else{
        prev->next = temp->next;
    }

    temp = graph->adjList[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\nEdge Not Found");
        return;
    }

    if(prev == NULL){
        graph->adjList[dest] = temp->next;
    }else{
        prev->next = temp->next;
    }
    printf("\n----------------------------");
    printf("\n| Edge from %d to %d deleted |\n", src, dest);
    printf("----------------------------\n");
    free(temp);
}

void addVertex(Graph* graph){
    int newSize = graph->numVertices + 1;
    graph->adjList = (Node**)realloc(graph->adjList, newSize * sizeof(Node*));
    graph->adjList[newSize-1] = NULL;
    graph->numVertices = newSize;

    printf("\n-------------------------");
    printf("\n| Vertex %d is inserted. |\n", newSize-1);
    printf("-------------------------\n");
}


void deleteVertex(Graph* graph, int v){
    if(v >= graph->numVertices){
        printf("\n--------------------");
        printf("\n| Vertex Not Found |\n");
        printf("----------------------\n");
        return;
    }

    for(int i = 0; i<graph->numVertices; i++){
        if(i != v){
            deleteEdge(graph, v, i);
        }
    }

    graph->adjList[v] = NULL;
    printf("\n----------------------------------");
    printf("\n| Vertex %d Deleted Successfully! |\n", v);
    printf("----------------------------------\n");
}

void display(Graph* graph){
    for(int i = 0; i<graph->numVertices; i++){
        Node* temp = graph->adjList[i];
        if(temp != NULL){
            printf("\nAdjacency List of vertex %d :- ", i);
            while (temp)
            {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
    printf("\n");
}


int main(){
    int V, E;
    printf("Enter No of vertices :-");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter no of Edges :- ");
    scanf("%d", &E);

    printf("\nEnter each edge in the format: src dest\n");
    
    for(int i = 0; i<E; i++){
        int src, dest;

        printf("Edge %d: ", i+1);
        scanf("%d %d", &src, &dest);

        if(src < 0 || src >= V || dest < 0 || dest >= V){
            printf("\nInvalid edge! Vertices must be between 0 and %d", V-1);
            i--;
            continue;
        }

        addEdge(graph, src, dest);
    }

    printf("\nGraph created successfully!\n");

    int choice;
    int src, dest;
    int vertex; 

    do
    {
        printf("\n");
        printf("+-----------------------------------+\n");
        printf("|              MENU                 |\n");
        printf("+-----------------------------------+\n");
        printf("| 1. Add Edge                       |\n");
        printf("| 2. Add Vertex                     |\n");
        printf("| 3. Delete Edge                    |\n");
        printf("| 4. Delete Vertex                  |\n");
        printf("| 5. Display Graph                  |\n");
        printf("| 6. Exit                           |\n");
        printf("+-----------------------------------+\n");

        printf("Enter your choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\nEnter each edge in the format: src dest\n");
            printf("Edge : ");
            scanf("%d %d", &src, &dest);

            if(src < 0 || src >= V || dest < 0 || dest >= V){
                printf("\nInvalid edge! Vertices must be between 0 and %d", V-1);
                break;
            }

            addEdge(graph, src, dest);
            break;
        
        case 2:
            addVertex(graph);
            V++;
            break;
        
        case 3:
            

            printf("\nEnter edge in the format: src dest\n");
            printf("Edge : ");
            scanf("%d %d", &src, &dest);

            if(src < 0 || src >= V || dest < 0 || dest >= V){
                printf("\nInvalid edge! Vertices must be between 0 and %d", V-1);
                break;
            }

            deleteEdge(graph, src, dest);
            break;

        case 4:
            

            printf("\nEnter valid vertex in the format: vertex\n");
            printf("Vertex : ");
            scanf("%d", &vertex);

            if(vertex >= V){
                printf("\nInvalid Vertex! Vertex must be between 0 and %d", V-1);
                break;
            }

            deleteVertex(graph, vertex);
            break;

        case 5:
            printf("\n");
            display(graph);
            break;

        case 6:
            printf("\nExitting....");
            return 0;
        default:
            break;
        }
    } while (choice != 6);
    


}