#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty(){return front == -1 || front > rear;}
bool isFull(){return rear == MAX_SIZE-1;}

void enqueue(int data){
    if (isFull())
    {
        printf("Queue is Overflowed");
        return;
    }
    if(front == -1){
        front = 0;
    }

    queue[++rear] = data;
    printf("Enqueued value is %d\n", data);
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty");
        return;
    }
    printf("Dequeued value is %d\n", queue[front++]);
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty");
        return;
    }

    for(int i = front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    return;
}

int peek(){
    if(isEmpty()){
        printf("Queue is Empty");
        return -1;
    }
    return queue[front];
}

int main(){

    int choice, value;

    do
    {
        printf("\n=============== Menu ===============\n"); 
        printf("Enter 1 - Enqueue an element\n"); 
        printf("Enter 2 - Dequeue an element\n"); 
        printf("Enter 3 - Peek the front element\n"); 
        printf("Enter 4 - Display all elements\n"); 
        printf("Enter 5 - Exit\n"); 
        printf("======================================\n");

        printf("Enter your choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element :- ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
             
        case 3:
            printf("Peek element is %d\n", peek());
            break;

        case 4:
            display();
            break;
        case 5:
            printf("Exitting....");
            return 0;

        default:
            break;
        }
    } while (choice != 5);
    
}