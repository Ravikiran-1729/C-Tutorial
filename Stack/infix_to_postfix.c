#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct stack {
    int top;
    char arr[MAX];
};

void init(struct stack *s){
    s->top = -1;
}

bool isEmpty(struct stack *s){
    return s->top == -1;
}

void push(struct stack *s, char val){
    s->arr[++(s->top)] = val;
}

char pop(struct stack *s){
    return s->arr[(s->top)--];
}

char peek(struct stack *s){
    return s->arr[s->top];
}

int precedence(char c){
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void infix_to_postfix(char infix[], int size){
    struct stack s;
    init(&s);

    char result[MAX];
    int k = 0;

    for(int i = 0; i < size; i++){
        char ch = infix[i];

        // 1. If operand → add to output
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            result[k++] = ch;
        }

        // 2. '(' → push
        else if(ch == '('){
            push(&s, ch);
        }

        // 3. ')' → pop until '('
        else if(ch == ')'){
            while(!isEmpty(&s) && peek(&s) != '('){
                result[k++] = pop(&s);
            }
            pop(&s); // remove '('
        }

        // 4. Operator → pop higher precedence operators
        else {
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)){
                result[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // 5. Pop remaining operators
    while(!isEmpty(&s)){
        result[k++] = pop(&s);
    }

    result[k] = '\0';

    printf("Postfix: %s\n", result);
}


int main(){
    char infix[] = "(A+B)*C-D";
    infix_to_postfix(infix, sizeof(infix)-1);

    return 0;
}
