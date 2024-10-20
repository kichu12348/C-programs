//double ended queue

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull(){
    if(front == (rear+1)%MAX) return 1;
    return 0;
}

int isEmpty(){
    if(front == -1) return 1;
    return 0;
}


void insertFront(int item) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }
    queue[front] = item;
}


void insertRear(int item) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = item;
}




void deleteFront() {
    int item;
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        if (front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
    printf("Deleted element is: %d\n", item);
}





void deleteRear() {
    int item;
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    item = queue[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear = rear - 1;
        }
    }
    printf("Deleted element is: %d\n", item);
}


void display(){
    int i;
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    if(front <= rear){
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }else{
        for(i = front; i < MAX; i++){
            printf("%d ", queue[i]);
        }
        for(i = 0; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

void main() {
    while(1){
        int choice, item;
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}



