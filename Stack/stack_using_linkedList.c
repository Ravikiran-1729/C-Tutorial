#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data; 
    struct stack* next;
};

struct stack* createStack(int data){
    struct stack* newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct stack** top, int data){
    struct stack* newNode = createStack(data);
    if(*top == NULL){
        *top = newNode;
        return;
    }

    newNode->next = *top;
    *top = newNode;
}

int pop(struct stack** top){
    if(*top == NULL){
        printf("Stack is Empty");
        return -1;
    }
    struct stack* temp = *top;
    
    *top = temp->next;

    int poppedValue = temp->data;
    
    free(temp);
    return poppedValue;
}

int peek(struct stack* top){
    if(top == NULL){
        printf("Stack is Empty\n");
        return -1;
    }else{
        return top->data;
    }
}

int main(){
    struct stack* top = NULL;

    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    printf("TOP element is %d\n", peek(top));
    
    printf("Popped Value is %d\n", pop(&top));
    
    printf("TOP element is %d\n", peek(top));

    printf("Popped Value is %d\n", pop(&top));
    
    printf("TOP element is %d\n", peek(top));

    printf("Popped Value is %d\n", pop(&top));

    printf("TOP element is %d\n", peek(top));
}