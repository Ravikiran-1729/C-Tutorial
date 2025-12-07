#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

struct stack
{
    int top;
    char arr[MAX];
};

bool isEmpty(struct stack *s) { return s->top == -1; }
bool isFull(struct stack *s) { return s->top == MAX - 1; }
void init(struct stack *s) { s->top = -1; }

void push(struct stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack is Overflowwed");
        return;
    }

    s->arr[++(s->top)] = value;
    return;
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty");
        return '\0';
    }

    return s->arr[(s->top)--];
}

void Convert(int num, int base)
{
    struct stack s;
    init(&s);

    int size = 0;

    char digits[] = "0123456789ABCDEF";

    if (num == 0)
    {
        printf("0");
        return;
    }

    while (num != 0)
    {
        /* code */
        push(&s, digits[num % base]);
        num /= base;
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        /* code */
        printf("%c", pop(&s));
    }
    printf("\n");
}

int main()
{
    int decimal;

    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal);

    printf("Binary      : ");
    Convert(decimal, 2);
    printf("\n");

    printf("Octal       : ");
    Convert(decimal, 8);
    printf("\n");

    printf("Hexadecimal : ");
    Convert(decimal, 16);
    printf("\n");

    return 0;
}