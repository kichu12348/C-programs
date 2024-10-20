#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;


Node *head = NULL;         

Node* createNode(int data){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data=data;
    p->next=NULL;
    return p;
};

void insertFront(int data){
    Node* p=createNode(data);
    if(head==NULL){
        head=p;
    }else{
        p->next=head;
        head=p;
    }
}


void insertRear(int data){
    Node* p=createNode(data);
    if(head==NULL){
        head=p;
    }else{
        Node* q=head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
}

void deleteFront(){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        Node* p=head;
        head=head->next;
        free(p);
    }
}

void deleteRear(){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        Node* p=head;
        Node* q=NULL;
        while(p->next!=NULL){
            q=p;
            p=p->next;
        }
        if(q==NULL){
            head=NULL;
        }else{
            q->next=NULL;
        }
        free(p);
    }
}


void display(){
    Node* p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void insertAfter(int data, int key){
    Node* p=createNode(data);
    Node* q=head;
    while(q!=NULL && q->data!=key){
        q=q->next;
    }
    if(q==NULL){
        printf("Key not found\n");
    }else{
        p->next=q->next;
        q->next=p;
    }
}

void deleteKey(int key){
    if(head==NULL){
        printf("List is empty\n");
    }else{
        Node* p=head;
        Node* q=NULL;
        while(p!=NULL && p->data!=key){
            q=p;
            p=p->next;
        }
        if(p==NULL){
            printf("Key not found\n");
        }else{
            if(q==NULL){
                head=p->next;
            }else{
                q->next=p->next;
            }
            free(p);
        }
    }
}

void insertBefore(int data, int key){
    Node* p=createNode(data);
    Node* q=head;
    Node* r=NULL;
    while(q!=NULL && q->data!=key){
        r=q;
        q=q->next;
    }
    if(q==NULL){
        printf("Key not found\n");
    }else{
        if(r==NULL){
            p->next=head;
            head=p;
        }else{
            p->next=q;
            r->next=p;
        }
    }
}

void main(){
    int choice, item, key;
    while(1){
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Insert After\n");
        printf("7. Delete Key\n");
        printf("8. Insert Before\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d",&item);
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
                printf("Enter the element to insert: ");
                scanf("%d",&item);
                printf("Enter the key: ");
                scanf("%d",&key);
                insertAfter(item,key);
                break;
            case 7:
                printf("Enter the key: ");
                scanf("%d",&key);
                deleteKey(key);
                break;
            case 8:
                printf("Enter the element to insert: ");
                scanf("%d",&item);
                printf("Enter the key: ");
                scanf("%d",&key);
                insertBefore(item,key);
                break;
            case 9:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}



