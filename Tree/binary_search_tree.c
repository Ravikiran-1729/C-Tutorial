#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left, *right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(root->data > data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct Node* search(struct Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(root->data < key){
        return search(root->right, key);
    }else{
        return search(root->left, key);
    }
}

int minValue(struct Node* root){
    if(root->left == NULL){
        return root->data;
    }
    return minValue(root->left);
}

struct Node* minValue1(struct Node* root){
    struct Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

struct Node* deleteNode(struct Node* root, int key){
    if(root == NULL){return root;}

    if(root->data > key){
        root->left = deleteNode(root->left, key);
    }else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }else{
            struct Node* temp = minValue1(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){

    struct Node* root = NULL;
    root = insert(root, 4);

    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);

    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 5);

    printf("\nInorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    struct Node* temp = search(root, 4);
    printf("\nLeft %d\n", temp->left->data);
    printf("Right %d\n", temp->right->data);

    struct Node* temp1 = search(root, 2);
    printf("Left %d\n", temp1->left->data);
    printf("Right %d\n", temp1->right->data);

    struct Node* temp2 = search(root, 6);
    printf("Left %d\n", temp2->left->data);
    printf("Right %d\n", temp2->right->data);


    int min = minValue(root);
    printf("Minimum value is %d\n", min);

    root = deleteNode(root, 6);
    printf("\nAfter deleting 6 (Inorder): ");
    inorder(root);
}

