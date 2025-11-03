#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node* createNode(int data){
    struct node* tempNode = (struct node*)malloc(sizeof(struct node));
    if(!tempNode){
        printf("Error: Memory allocation failed");
        exit(1);
    }
    tempNode->data = data;
    tempNode->next = NULL;
    return tempNode;
}

void reverseList(struct node** head){
    struct node* prev = NULL;
    struct node* curr = *head;
    
    while (curr != NULL)
    {
        struct node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct node* reverseListRecursion(struct node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct node* newHead = reverseListRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int insertAtBeginning(struct node** head, int data){
    struct node* tempNode = createNode(data);
    tempNode->next = *head;
    *head = tempNode;
    return 0;
}

void printList(struct node* head){
    struct node* tempNode = head;
    while(tempNode != NULL){
        printf("%d -> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
}

int main(){

    struct node* head = NULL;
    head = createNode(4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 0);
    printList(head);
    reverseList(&head);
    printList(head);
    head = reverseListRecursion(head);
    printList(head);
}