#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    int top;
    int* arr;
    int size;
};

void init(struct stack* s, int size){
    s->arr = malloc(size * sizeof(int));
    s->size = size;
    s->top = -1;
    return;
}

bool isEmpty(struct stack* s){return s->top == -1 ? true : false;}

bool isFull(struct stack* s){return s->top == s->size - 1 ? true : false;}

void resize(struct stack* s){
    printf("Resizing the array....\n");
    s->size  *= 2;
    s->arr = realloc(s->arr, s->size * sizeof(int));
    return;
}

void push(struct stack* s, int value){
    if(isFull(s)){resize(s);}

    s->arr[++(s->top)] = value;
    return;
}

int pop(struct stack* s){
    if(isEmpty(s)){printf("Stack is Empty\n"); return -1;}
    return s->arr[(s->top)--];
}

int peek(struct stack* s){
    if(isEmpty(s)){printf("Stack is Empty\n"); return -1;}

    return s->arr[s->top];
}

int main(){
    struct stack s;
    init(&s, 2);

    push(&s, 1);
    printf("Inserted 1\n");
    push(&s, 2);
    printf("Inserted 2\n");
    push(&s, 3);
    printf("Inserted 3\n");

    printf("Peek Element is %d\n", peek(&s));

    printf("Popped Element is %d\n", pop(&s));
    
    printf("Peek Element is %d\n", peek(&s));

    printf("Popped Element is %d\n", pop(&s));

    printf("Peek Element is %d\n", peek(&s));

    printf("Popped Element is %d\n", pop(&s));

    printf("Peek Element is %d\n", peek(&s));
}