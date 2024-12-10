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

// Time complexity
// insertFront: O(1)
// insertRear: O(1)

// deleteFront: O(1)

// deleteRear: O(1)

//pseudo code

/*
MAX=5
front=-1
rear=-1
queue[MAX]


isFull():
    1. if front == (rear+1)%MAX then return 1
    2. return 0

isEmpty():
    1. if front == -1 then return 1
    2. return 0

insertFront(item):
    1. if isFull() then print "Queue Overflow" and return
    2. if front == -1 then front = rear = 0
    3. else if front == 0 then front = MAX - 1
    4. else front = front - 1
    5. queue[front] = item

insertRear(item):
    1. if isFull() then print "Queue Overflow" and return
    2. if front == -1 then front = rear = 0
    3. else if rear == MAX - 1 then rear = 0
    4. else rear = rear + 1
    5. queue[rear] = item

deleteFront():
    1. if isEmpty() then print "Queue Underflow" and return
    2. item = queue[front]
    3. if front == rear then front = rear = -1
    4. else if front == MAX - 1 then front = 0
    5. else front = front + 1
    6. print "Deleted element is: " + item

deleteRear():
    1. if isEmpty() then print "Queue Underflow" and return
    2. item = queue[rear]
    3. if front == rear then front = rear = -1
    4. else if rear == 0 then rear = MAX - 1
    5. else rear = rear - 1
    6. print "Deleted element is: " + item

display():
    1. if isEmpty() then print "Queue is empty" and return
    2. if front <= rear then:
        2.1 for i=front and i<=rear then i++:
            2.1.1 print queue[i]
    3. else:
        3.1 for i=front and i<MAX then i++:
            3.1.1 print queue[i]
        3.2 for i=0 and i<=rear then i++:
            3.2.1 print queue[i]
    4. print "\n"

*/

