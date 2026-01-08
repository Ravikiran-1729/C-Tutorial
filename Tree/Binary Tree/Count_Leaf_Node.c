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

int countLeafNode(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int left = countLeafNode(root->left);
    int right = countLeafNode(root->right);

    return left + right;
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
    
    
    int count = countLeafNode(root);
    printf("\nLeaf Nodes are %d\n", count);
}







