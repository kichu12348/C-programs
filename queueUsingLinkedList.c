// queue using linked list

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
} Node;

Node* front = NULL, *rear = NULL;

Node* createNode(int data){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=NULL;
    return p;
};

int isEmpty(){
    if(front==NULL) return 1;
    return 0;
}


void insert(int item){
    Node* p=createNode(item);
    if(isEmpty()){
        front=rear=p;
    }else{
        rear->next=p;
        rear=p;
    }
}

int delete(){
    if(isEmpty()){
        printf("Queue Underflow\n");
        return -1;
    }
    Node* p=front;
    int item=p->data;
    front=front->next;
    free(p);
    return item;
}


void display(){
    Node* p=front;
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void main(){
    int choice, item;
    while(1){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                item=delete();
                if(item!=-1){
                    printf("Deleted element is: %d\n",item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}


