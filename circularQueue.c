// circularQueue.c

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull(){
    return front == (rear+1)%MAX;
}

int isEmpty(){
    if(front == -1) return 1;
    return 0;
}

void insert(int item) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
    }
    queue[rear] = item;
}


void delete() {
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


void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    if(front <= rear){
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }else{
        for (i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}


void main() {
    int choice, item;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
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
