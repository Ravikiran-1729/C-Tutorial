#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct stack{
    int top;
    char arr[MAX];
};

void init(struct stack* s){s->top = -1;}

bool isEmpty(struct stack* s){return s->top == -1;}

bool isFull(struct stack* s){return s->top == MAX - 1;}

void push(struct stack* s, char data){
    s->arr[++(s->top)] = data;
}

char pop(struct stack* s){
    return s->arr[(s->top)--];
}

char peek(struct stack* s){
    return s->arr[s->top];
}



struct stackInt{
    int top;
    int arr[MAX];
};

void initInt(struct stackInt* s){s->top = -1;}

bool isEmptyInt(struct stackInt* s){return s->top == -1;}

bool isFullInt(struct stackInt* s){return s->top == MAX - 1;}

void pushInt(struct stackInt* s, int data){
    s->arr[++(s->top)] = data;
}

int popInt(struct stackInt* s){
    return s->arr[(s->top)--];
}

int peekInt(struct stackInt* s){
    return s->arr[s->top];
}

void postfixResult(char str[], int size){
    struct stackInt s;
    initInt(&s);

    for(int i = 0; i<size; i++){
        char ch = str[i];

        if(isdigit(ch)){
            pushInt(&s, ch - '0');
        }else{
            int op1 = popInt(&s);
            int op2 = popInt(&s);
            int result = 0;

            switch (ch)
            {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                result = op2 / op1;
                break;
            default:
                break;
            }

            pushInt(&s, result);
        }
    }

    printf("Result is :- %d", popInt(&s));
}


int precedance(char a){
    if(a == '+' || a == '-') return 1;
    if(a == '*' || a == '/') return 2;
    return 0;
}

void infix_to_postfix(char str[], int size){
    struct stack s;
    init(&s);

    char result[MAX];
    int k = 0;

    for(int i = 0; i<size; i++){
        char ch = str[i];

        if (isdigit(ch))
        {
            result[k++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if(ch == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                result[k++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (!isEmpty(&s) && precedance(peek(&s)) >= precedance(ch))
            {
                result[k++] = pop(&s);
            }
            push(&s, ch);
        }
        
    }

    while (!isEmpty(&s))
    {
        result[k++] = pop(&s);
    }
    result[k] = '\0';

    printf("Postfix operation is :- %s\n", result);
    postfixResult(result, strlen(result));
}




int main(){
    char str[] = "(9+5)*1-5";
    infix_to_postfix(str, strlen(str));
}