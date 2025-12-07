#include<stdio.h>
#include<time.h>
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
int countNode(struct node* head){
    int i = 1;
    struct node* tempNode = head;
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
        i++;
    }
    return i;
}

// void sort(struct node** head){
//     for(int i = 0; i<countSize(*head); i++){
//         struct node* prev = NULL;
//         struct node* curr = *head;
//         struct node* next = curr->next;
//         if(curr->data>next->data){
//             if(prev!=NULL){
//                 prev->next = next; 
//             }
//             curr->next = next->next;
//             next->next = curr;
            
//             prev = next;
//             next = curr;
//         }else{

//         }
//     }
// }


void sort(struct node* head) {
    if (head == NULL || head->next == NULL)
        return;

    struct node* minNode = head;
    struct node* curr = head->next;

    while (curr != NULL) {
        if (curr->data < minNode->data)
            minNode = curr;
        curr = curr->next;
    }

    if (minNode != head) {
        int temp = head->data;
        head->data = minNode->data;
        minNode->data = temp;
    }

    sort(head->next);
}

int main(){
    struct node* head = NULL;
    printf("Creating first node with data = 1\n");
    head = createNode(1);
    printList(head);

    insertAtBeginning(&head, 2);

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 9);

    insertAtBeginning(&head, 4);

    printf("\nFinal linked list after all insertions:\n");
    printList(head);
    

    clock_t start = clock();
    sort(head);
    clock_t end = clock();
    
    printf("\n %llf", end-start);
    printf("\nFinal linked list after Sorting:\n");
    printList(head);
    return 0;
}   