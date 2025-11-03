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
    printf("\nInserting %d at the beginning...\n", data);
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}




void searchByValue(struct node* head, int val){
    if(head == NULL){
        printf("Error: List is Empty.\n");
        return;
    }

    struct node* tempNode = head;

    if((head)->data == val){
        printf("\nNode with value %d is found at index 0\n", tempNode->data);
        return;
    }
    int i = 1;
    while(tempNode->next != NULL){
        if(tempNode->next->data == val){
            printf("\nNode with value %d is found at index %d\n", tempNode->next->data, i);
            return;
        }else{
            tempNode = tempNode->next;
            i++;
        }
    }
    printf("\nError: Node with value %d is not found.\n", val);
}



void searchByIdx(struct node* head, int idx){
    if(head == NULL){
        printf("Error: List is Empty.\n");
        return;
    }

    if(idx == 0){
        printf("\nNode with value %d is found at index 0\n", head->data);
        return;
    }
    
    struct node* tempNode = head;
    int i = 0;
    while(tempNode != NULL && i<idx){
        tempNode = tempNode->next;
        i++;
    }
    if(tempNode == NULL){
        printf("\nError: Index is %d out of bound\n", idx);
        return;
    }
    printf("\nNode with value %d is found at index %d\n", tempNode->data, idx);
}

int main(){
    struct node* head = NULL;
    printf("Creating first node with data = 1\n");
    head = createNode(1);
    printList(head);

    insertAtBeginning(&head, 2);

    insertAtBeginning(&head, 3);

    insertAtBeginning(&head, 4);

    printf("\nFinal linked list after all insertions:\n");
    printList(head);

    searchByValue(head,3);
    printList(head);
    searchByIdx(head,4);
    printList(head);

    return 0;
}   