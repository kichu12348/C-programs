//stack using linked list

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
} Node;


Node *top = NULL;

Node* createNode(int data){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=NULL;
    return p;
};

int isEmpty(){
    if(top==NULL) return 1;
    return 0;
}



void push(int item){
    Node* p=createNode(item);
    if(isEmpty()){
        top=p;
    }else{
        p->next=top;
        top=p;
    }
}


int pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return -1;
    }
    Node* p=top;
    int item=p->data;
    top=top->next;
    free(p);
    return item;
}


int peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}


void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    Node* p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


void main(){
    int choice, item;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item=pop();
                if(item!=-1){
                    printf("Popped element is: %d\n",item);
                }
                break;
            case 3:
                item=peek();
                if(item!=-1){
                    printf("Top element is: %d\n",item);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}




