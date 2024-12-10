#include<stdio.h>  

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char item){
    top++;
    stack[top] = item;
}

char pop(){
    char item = stack[top];
    top--;
    return item;
}

char peek(){
    return stack[top];
}

int isOperator(char symbol){ // Check if the character is an operator
    return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

int precedence(char symbol){ // Return the priority of the operator
    if(symbol == '^') return 3;
    if(symbol == '*' || symbol == '/') return 2;
    if(symbol == '+' || symbol == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]){
    int i=0, j=0;
    char postfix[SIZE];
    while(infix[i]!='\0'){
        char token = infix[i];
       
        if(token=='(') push(token); // If the token is an opening bracket, push it to the stack
        
        else if(token==')'){ // If the token is a closing bracket, pop all the operators from the stack and add them to the postfix expression until an opening bracket is encountered
            while(top!=-1 && peek()!='(') postfix[j++]=pop(); // Pop all the operators from the stack and add them to the postfix expression until an opening bracket is encountered
            pop(); // Pop the opening bracket from the stack "("
        }
        
        else if(isOperator(token)){ // If the token is an operator
            while(top!=-1 && precedence(peek())>=precedence(token)) postfix[j++]=pop(); // Pop all the operators from the stack and add them to the postfix expression until an operator with lower precedence is encountered
            
            push(token); // Push the token to the stack
        }
        
        else { // If the token is an operand, add it to the postfix expression
            postfix[j++]=token;
        }
        
        i++; // Move to the next token
    }

    while(top!=-1) postfix[j++]=pop(); // Pop all the operators from the stack and add them to the postfix expression
    
    postfix[j]='\0';
    
    printf("Postfix expression is: %s\n", postfix);
}

void main(){
    char infix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
}



/*
pseudo code

Max=50
stack[Max]
top=-1

push(item):
    1. top = top + 1
    2. stack[top] = item

pop():
    1. item = stack[top]
    2. top = top - 1
    3. return item

peek():
    1. return stack[top]

isOperator(symbol):
    1. return symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'

precedence(symbol):
    1. if symbol == '^':
        1.1 return 3
    2. if symbol == '*' || symbol == '/':
        2.1 return 2
    3. if symbol == '+' || symbol == '-':
        3.1 return 1
    4. return 0

infixToPostfix(infix):
    1. i = 0, j = 0
    2. postfix[Max]
    3. while infix[i] != '\0':
        3.1 token = infix[i]
        3.2 if isOperator(token):
            3.2.1 while top != -1 && precedence(peek()) >= precedence(token):
                3.2.1.1 postfix[j++] = pop()
            3.2.2 push(token)
        3.3 else if token == '(':
            3.3.1 push(token)
        3.4 else if token == ')':
            3.4.1 while top != -1 && peek() != '(':
                3.4.1.1 postfix[j++] = pop()
            3.4.2 pop()
        3.5 else:
            3.5.1 postfix[j++] = token
        3.6 i++
    4. while top != -1:
        4.1 postfix[j++] = pop()
    5. postfix[j] = '\0'
    6. print postfix

*/