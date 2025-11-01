#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct node* head){
    struct node* tempNode = head;
    while(tempNode!=NULL){
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
}
void insertAtBeginning(struct node** head, int data){
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnding(struct node* head, int data){
    struct node* newNode = createNode(data);
    struct node* tempNode = head;

    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void insert(struct node** head, int data, int idx){
    if(idx==0){
        insertAtBeginning(head, data);
        return;
    }

    if(*head == NULL){
        *head = createNode(data);
        return;
    }

    struct node* newNode = createNode(data);
    struct node* tempNode = *head;
    int i = 0;
    while(tempNode->next != NULL && i<idx-1){
        tempNode = tempNode->next;
        i++;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
}
int main(){
    struct node* head = NULL;
    
    printf("Creating first node with data = 1\n");
    head = createNode(1);
    printList(head);

    printf("\nInserting 2 at the beginning...\n");
    insertAtBeginning(&head, 2);
    printList(head);

    printf("\nInserting 3 at the end...\n");
    insertAtEnding(head, 3);
    printList(head);

    printf("\nInserting 4 at index 1...\n");
    insert(&head, 4, 1);
    printList(head);

    printf("\nFinal linked list after all insertions:\n");
    printList(head);

    return 0;
}   