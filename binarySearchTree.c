#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* p=(Node *)malloc(sizeof(Node));
    p->data=val;
    p->left=p->right=NULL;
    return p;
}

Node *insert(Node *root,int val){
    if(!root) return createNode(val);
    if(val<root->data) root->left=insert(root->left,val);
    if(val>root->data) root->right=insert(root->right,val);
    return root;
}


Node *search(Node* root,int key){
    if(!root) return NULL;
    if(root->data<key) return search(root->right,key);
    if(root->data>key) return search(root->left,key);
    return root;
}

void inorderTraversal(Node* root){
    if(!root) return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}


Node* delete(Node* root,int key){
    if(!root) return NULL;
    if(root->data<key) root->right=delete(root->right,key);
    else if(root->data>key) root->left=delete(root->left,key);
    else{
        if(!root->left){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(!root->right){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal
    printf("In-order traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    // Search for a value
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Node with value %d found in the BST.\n", key);
    } else {
        printf("Node with value %d not found in the BST.\n", key);
    }

    return 0;
}
 