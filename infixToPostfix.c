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


int isOperand(char s){ // Check if the character is an operand
    return ((s>= 'a' && s<= 'z') || (s>= 'A' && s<= 'Z')||(s>= '0' && s<= '9'));
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
       
        if(isOperand(token)) postfix[j++]=token; // If the token is an operand, add it to the postfix expression
        
        else if(token=='(')push(token); // If the token is an opening bracket, push it to the stack
        
        else if(token==')'){ // If the token is a closing bracket, pop all the operators from the stack and add them to the postfix expression until an opening bracket is encountered
            while(top!=-1 && peek()!='(') postfix[j++]=pop(); // Pop all the operators from the stack and add them to the postfix expression until an opening bracket is encountered
            pop(); // Pop the opening bracket from the stack "("
        }
        
        else if(isOperator(token)){ // If the token is an operator
            while(top!=-1 && precedence(peek())>=precedence(token)) postfix[j++]=pop(); // Pop all the operators from the stack and add them to the postfix expression until an operator with lower precedence is encountered
            
            push(token);// Push the token to the stack
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

