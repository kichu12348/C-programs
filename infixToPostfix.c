#include<stdio.h>
//im betmen 🦇
//hehehehehehehehe 😼
#define MAX 100
char stack[MAX];
int top=-1;

void push(char ch){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }else{
        stack[++top]=ch;
    }
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }else{
        return stack[top--];
    }
}

char peek(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }else{
        return stack[top];
    }
}



int isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

int isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

int precedence(char ch){
    if(ch=='^') return 3;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}

void infixToPostfix(char infix[]){
    char postfix[100];
    int i=0,j=0;
    while(infix[i]!='\0'){
        char token=infix[i];
        if(isOperand(token)) postfix[j++]=token;
        else if (token=='(') push(token);
        else if (token==')'){
            while(peek()!='('){
                postfix[j++]=pop();
            }
            pop();
        }else if(isOperator(token)){
            while(precedence(token)<=precedence(peek())){
                postfix[j++]=pop();
            }
            push(token);
        }
        i++;
    }

    while(top!=-1){
        postfix[j++]=pop();
    }

    postfix[j]='\0';

    printf("Postfix expression: %s\n",postfix);
}

void main(){
    char infix[]="a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix);
}

// Output: 
// Postfix expression: abcd^e-fgh*+^*+i-
//