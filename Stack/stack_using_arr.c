#include<stdio.h>
#include<stdbool.h>

#define MAX 100

struct stack{
    int top;
    int arr[MAX];
};

bool isEmpty(struct stack* s){ return s->top == -1 ? true : false;}

bool isFull(struct stack* s){ return s->top == MAX-1 ? true : false;}

void init(struct stack* s){s->top = -1;}

void push(struct stack* s, int value){
    if(isFull(s)){ 
        printf("Stack is Overflow?"); 
        return;
    }else{
        s->arr[++(s->top)] = value;
    }
}

int pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack is Empty");
        return -1;
    }else{
        return s->arr[(s->top)--];
    }
}

int peek(struct stack s){
    if(isEmpty(&s)){
        printf("Stack is Empty");
        return -1;
    }else{
        return s.arr[s.top];
    }
}

int main(){
    struct stack s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    int b = peek(s);

    printf("Peek element is %d\n", b);

    int a = pop(&s);
    printf("Popped element is %d\n", a);

    printf("Peek element is %d\n", peek(s));
}