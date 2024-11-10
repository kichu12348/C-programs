#include<stdio.h>
#include<stdlib.h>


// Define the structure of a node
typedef struct Node{
    int data;
    struct Node *link;
}Node;


Node* newNode(int val){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=val;
    p->link=NULL;
    return p;
}

Node* head;

void insertNode(){
    int n;
    printf("enter value of n");
    scanf("%d",&n);
    Node* p=newNode(n);
    if(!head)head=p;
    else{
        p->link=head;
        head=p;
    }
}


void deleteNode(){
    int item;
    printf("enter value of item to be deleted: ");
    scanf("%d",&item);

    Node* curr = head;
    Node *prev;
    while(curr&&curr->data!=item) {
        prev=curr;
        curr=curr->link;
        }

    if(!curr){
        printf("item not found\n");
        return;
    }

    if(curr==head){
        head=head->link;
        free(curr);
        return;
    }

    prev->link=curr->link;
    free(curr);
}


void display(){
    Node* curr=head;

    while(curr){
        printf("%d->",curr->data);
        curr=curr->link;
    }
    printf("NULL\n");
}

void main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertNode();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}