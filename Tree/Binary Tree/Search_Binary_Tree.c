#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* left, *right;
} Node;


Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        perror("Malloc Failed");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int data){
    Node* newNode = createNode(data);
    if(root == NULL){
        return newNode;
    }

    Node* queue[100];
    int front = 0, rare = 0;

    queue[rare++] = root;

    while (front < rare)
    {
        Node* current = queue[front++];

        if(current->left == NULL){
            current->left = newNode;
            return root;
        }else{
            queue[rare++] = current->left;
        }

        if (current->right == NULL)
        {
            current->right = newNode;
            return root;
        }else{
            queue[rare++] = current->right;
        }
    }
    
    return root;
}


void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}


void preOrder(Node* root){
    if (root == NULL)
    {
        return; 
    }
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(Node* root){
    if (root == NULL)
    {
        return; 
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}


void levelOrder(Node* root){
    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Node* current = queue[front++];

        printf("%d ", current->value);

        if(current->left != NULL){
            queue[rear++] = current->left;
        }

        
        if(current->right != NULL){
            queue[rear++] = current->right;
        }
    }
    
}

int main(){
    Node* root = NULL;
    int x = -1;
    do
    {
        printf("Enter node value (-1 to end) :- ");
        scanf("%d", &x);

        if(x != -1){
            root = insert(root, x);
        }
        
    } while (x != -1);
    
    
    inorder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    levelOrder(root);
    printf("\n");
}







