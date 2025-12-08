#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

#define MAX 100

typedef struct Queue{
    int arr[MAX];
    int front, rear;
} Queue;

void init(Queue* q){
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q){return q->front == -1;}
bool isFull(Queue* q){return q->rear == MAX - 1;}

void enqueue(Queue* q, int value){
    if(isFull(q)){
        printf("\nQueue is Overflowed...");
        return;
    }

    if(q->front == -1){
        q->front = 0;
    }

    q->arr[++(q->rear)] = value;
    // printf("Enqueued value is %d\n", q.arr[q.rear]);
    return;
}

int peek(Queue* q){
    if(isEmpty(q)){return -1;}
    return q->arr[q->front];
    
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return -1;
    }

    int a =  q->arr[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front++;
    }
    return a;
}

void displayQueue(Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return;
    }
    printf("\nQueue is : ");
    for(int i = q->front; i<=q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    return;
}


void BFS(Graph* graph, int start){
    Queue q;
    init(&q);

    int *visited = (int*)calloc(graph->numVertices, sizeof(int));

    enqueue(&q, start);
    
    while (!isEmpty(&q))
    {
        int a = dequeue(&q);
        if(!visited[a]){
            visited[a] = 1;
            printf("%d ", a);
        }else{
            continue;
        }

        Node* temp = graph->adjList[a];
        while (temp != NULL)
        {
            if(!visited[temp->vertex]){
                enqueue(&q, temp->vertex);
            }
            temp = temp->next;
        }
    }

    free(visited);
}

typedef struct Stack{
    int data;
    struct Stack* next;
} Stack;

bool isEmptyStack(Stack* top){return top == NULL;}

Stack* createStack(int value){
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack* push(Stack* top, int value){
    Stack* newNode = createStack(value);
    newNode->next = top;
    top = newNode;
    return top;
}

int pop(Stack** top){
    if(isEmptyStack(*top)){printf("Stack is Empty."); return -1;}

    Stack* temp = *top;
    int a = temp->data;
    *top = temp->next;
    free(temp);
    return a;
}

int peekOfStack(Stack* top){
    if(isEmptyStack(top)){printf("Stack is Empty."); return -1;}
    return top->data;
}

void DFS(Graph* graph, int start){
    Stack* s = NULL;

    int *visited = (int*)calloc(graph->numVertices, sizeof(int));

    s = push(s, start);

    while (!isEmptyStack(s))
    {
        int a = pop(&s);
        if(!visited[a]){
            visited[a] =1;
            printf("%d ", a);
        }else{
            continue;
        }

        Node* temp = graph->adjList[a];
        while (temp != NULL)
        {
            if(!visited[temp->vertex]){
                s = push(s, temp->vertex);
            }
            temp = temp->next;
        }
        
    }
    free(visited);
    
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
    int start;
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
        printf("| 6. BFS                            |\n");
        printf("| 7. DFS                            |\n");
        printf("| 8. Exit                           |\n");
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

            if(vertex < 0 && vertex >= V){
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
            printf("Enter the Starting Vertex :- ");
            scanf("%d", &start);

            if(start < 0 || start >= V){
                printf("Invalid Starting Vertex! Vertex must be between 0 to %d", V-1);
                break;
            }

            BFS(graph, start);
            break;

        case 7:
            
            printf("Enter the Starting Vertex :- ");
            scanf("%d", &start);

            if(start < 0 || start >= V){
                printf("Invalid Starting Vertex! Vertex must be between 0 to %d", V-1);
                break;
            }

            DFS(graph, start);
            break;

        case 8:
            printf("\nExitting....");
            return 0;
        default:
            break;
        }
    } while (choice != 8);
    


}