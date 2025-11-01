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


void delete(struct node** head, int idx){
    if(idx<0){
        printf("\nError: Negative index (%d) is invalid.\n", idx);
        return;
    }

    if(*head == NULL){
        printf("\nError: List is Empty.\n");
        return;
    }
    
    struct node* tempNode = *head;

    if(idx == 0){
        *head = tempNode->next;
        printf("\nDeleting node at index 0 with value %d\n", tempNode->data);
        free(tempNode);
        return;
    }

    int i = 0;
    while(tempNode->next != NULL && i<idx-1){
        tempNode = tempNode->next;
        i++;
    }

    if(tempNode == NULL || tempNode->next == NULL){
        printf("\nError: Index %d is out of Range.\n", idx);
        return;
    }

    struct node* targetNode = tempNode->next;
    tempNode->next = targetNode->next;
    printf("\nDeleting node at index %d with value %d\n", idx, targetNode->data);
    free(targetNode);
}


void deleteByValue(struct node** head, int val){
    if(*head == NULL){
        printf("Error: List is Empty.\n");
        return;
    }

    struct node* tempNode = *head;

    if((*head)->data == val){
        (*head) = tempNode->next;
        printf("\nDeleting node at index 0 with value %d\n", tempNode->data);
        free(tempNode);
        return;
    }
    
    while(tempNode->next != NULL){
        if(tempNode->next->data == val){
            struct node* targetNode = tempNode->next;
            tempNode->next = targetNode->next;
            printf("\nDeleting node  with value %d\n", targetNode->data);
            free(targetNode);
            return;
        }else{
            tempNode = tempNode->next;
        }
    }
    printf("\nError: Node value %d is not found.\n", val);
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

    delete(&head, 2);
    printList(head);

    deleteByValue(&head, 5);
    printList(head);

    printf("\nFinal linked list after deletions:\n");
    printList(head);

    return 0;
}   