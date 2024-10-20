//stack using arrays
#include <stdio.h>

#define MAX 5
int stack[MAX];
int top = -1;


int isFull(){
    if(top==MAX-1) return 1;
    return 0;
}

int isEmpty(){
    if(top==-1) return 1;
    return 0;
}

void push(int item){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=item;
}


int pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}


int peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}



void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
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
                if(item!=-1) printf("Popped element is: %d\n",item);
                break;
            case 3:
                item=peek();
                if(item!=-1) printf("Top element is: %d\n",item);
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
