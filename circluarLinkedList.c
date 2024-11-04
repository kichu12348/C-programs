#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Initialize next to itself for a single node circular list
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {  // If list is empty
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode; // Move head to the new node
    }
}

// Function to insert a node after a given node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node before a given node
void insertBeforeNode(struct Node** head, struct Node* nextNode, int data) {
    if (*head == NULL || nextNode == NULL) {
        printf("The given node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    // If nextNode is the head node, insert at beginning
    if (*head == nextNode) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    } else {
        // Find the node before the nextNode
        struct Node* temp = *head;
        while (temp->next != nextNode && temp->next != *head) {
            temp = temp->next;
        }

        if (temp->next == nextNode) { // Insert before nextNode
            temp->next = newNode;
            newNode->next = nextNode;
        } else {
            printf("Node not found in the list.\n");
        }
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("Circular Linked List after inserting nodes at the beginning:\n");
    displayList(head);

    // Insert after a given node
    printf("Inserting 25 after 20:\n");
    insertAfterNode(head->next, 25); // Insert 25 after the node with value 20
    displayList(head);

    // Insert before a given node
    printf("Inserting 15 before 10:\n");
    insertBeforeNode(&head, head->next->next->next, 15); // Insert 15 before the node with value 10
    displayList(head);

    return 0;
}
