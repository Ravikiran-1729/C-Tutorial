#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtTop(struct node** head, int data){
    struct node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
    return;
}

int main(){
    struct node* head = NULL;
}