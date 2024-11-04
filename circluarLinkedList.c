#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Insert at the end
void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

// Insert after a given node
void insertAfterNode(int afterData, int data) {
    Node* current = head;
    if (head == NULL) return;

    do {
        if (current->data == afterData) {
            Node* newNode = createNode(data);
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node with data %d not found.\n", afterData);
}

// Insert before a given node
void insertBeforeNode(int beforeData, int data) {
    Node* current = head;
    if (head == NULL) return;

    do {
        if (current->data == beforeData) {
            Node* newNode = createNode(data);
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;

            if (current == head) {
                head = newNode;  // Update head if we insert before the first node
            }
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node with data %d not found.\n", beforeData);
}

// Delete a node with given data
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    do {
        if (current->data == data) {
            if (current->next == current && current->prev == current) { // Single node case
                free(current);
                head = NULL;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head) { // If head is to be deleted
                head = current->next;
            }

            free(current);
            printf("Node with data %d deleted.\n", data);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node with data %d not found.\n", data);
}

// Display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    int choice, data, refData;

    while (1) {
        printf("\n1. Insert at end\n2. Insert after node\n3. Insert before node\n4. Delete node\n5. Display list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 2:
                printf("Enter reference data to insert after: ");
                scanf("%d", &refData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterNode(refData, data);
                break;

            case 3:
                printf("Enter reference data to insert before: ");
                scanf("%d", &refData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeNode(refData, data);
                break;

            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}