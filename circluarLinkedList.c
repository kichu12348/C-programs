#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void insertAtStart(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }
}

void insertAtRear(int data) {
    insertEnd(data);
}

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
                head = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node with data %d not found.\n", beforeData);
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;
    do {
        if (current->data == data) {
            if (current->next == current && current->prev == current) {
                free(current);
                head = NULL;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head) {
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

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* toDelete = head;
    if (head->next == head) {
        head = NULL;
    } else {
        Node* last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    free(toDelete);
    printf("First node deleted.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* last = head->prev;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }

    printf("Last node deleted.\n");
}

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
        printf("\n1. Insert at start\n2. Insert at rear\n3. Insert after node\n4. Insert before node\n");
        printf("5. Delete first\n6. Delete end\n7. Delete node by value\n8. Display list\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at start: ");
                scanf("%d", &data);
                insertAtStart(data);
                break;

            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertAtRear(data);
                break;

            case 3:
                printf("Enter reference data to insert after: ");
                scanf("%d", &refData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterNode(refData, data);
                break;

            case 4:
                printf("Enter reference data to insert before: ");
                scanf("%d", &refData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeNode(refData, data);
                break;

            case 5:
                deleteFirst();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 8:
                displayList();
                break;

            case 9:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


//algorithm

/*
createNode(data):
    newNode = new Node
    newNode.data = data
    newNode.next = newNode.prev = newNode
    return newNode

insertAtStart(data):
    newNode = createNode(data)
    if head == NULL
        head = newNode
    else
        last = head.prev
        newNode.next = head
        newNode.prev = last
        head.prev = newNode
        last.next = newNode
        head = newNode


insertEnd(data):
    newNode = createNode(data)
    if head == NULL
        head = newNode
    else
        last = head.prev
        newNode.next = head
        head.prev = newNode
        newNode.prev = last
        last.next = newNode

insertAfterNode(afterData, data):
    current = head
    if head == NULL
        return

    do
        if current.data == afterData
            newNode = createNode(data)
            newNode.next = current.next
            newNode.prev = current
            current.next.prev = newNode
            current.next = newNode
            return
        current = current.next
    while current != head

    print "Node with data afterData not found."

insertBeforeNode(beforeData, data):
    current = head
    if head == NULL
        return

    do
        if current.data == beforeData
            newNode = createNode(data)
            newNode.next = current
            newNode.prev = current.prev
            current.prev.next = newNode
            current.prev = newNode

            if current == head
                head = newNode
            return
        current = current.next
    while current != head

    print "Node with data beforeData not found."

deleteNode(data):
    if head == NULL
        print "List is empty."
        return

    current = head
    do
        if current.data == data
            if current.next == current and current.prev == current
                free current
                head = NULL
                return

            current.prev.next = current.next
            current.next.prev = current.prev

            if current == head
                head = current.next

            free current
            print "Node with data data deleted."
            return
        current = current.next
    while current != head

    print "Node with data data not found."

deleteFirst():
    if head == NULL
        print "List is empty."
        return

    toDelete = head
    if head.next == head
        head = NULL
    else
        last = head.prev
        head = head.next
        head.prev = last
        last.next = head

    free toDelete
    print "First node deleted."

deleteEnd():
    if head == NULL
        print "List is empty."
        return

    last = head.prev
    if head.next == head
        free head
        head = NULL
    else
        last.prev.next = head
        head.prev = last.prev
        free last

    print "Last node deleted."

displayList():
    if head == NULL
        print "List is empty."
        return
    current = head
    do
        print current.data
        current = current.next
    while current != head
    print
*/