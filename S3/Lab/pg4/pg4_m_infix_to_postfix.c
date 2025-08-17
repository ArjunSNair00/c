#include <stdio.h>
#define max 20

char stack[20];
int top=-1;

int is_alnum(char c) {
    return (c >= '0' && c <= '9') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= 'a' && c <= 'z');
}

void push(char x) {
    if (top == max - 1)
        printf("Stack overflow\n");
    else 
        stack[++top] = x;
}

char pop() {
    if (top==-1)
        return '\0'; // underflow safe
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1; // for safety
}

int main() {
    char exp[20];
    char postfix[20];  // array to store postfix
    int k = 0;              // index for postfix
    char *e, x;

    printf("Enter the expression: ");
    scanf("%s", exp);
    e = exp;

    while(*e != '\0') {
        if(is_alnum(*e)) {
            postfix[k++] = *e;   // store operand
        }
        else if(*e == '(') {
            push(*e);
        }
        else if(*e == ')') {
            while((x = pop()) != '(') {
                postfix[k++] = x;
            }
        }
        else { // operator
            while(priority(stack[top]) >= priority(*e)) {
                postfix[k++] = pop();
            }
            push(*e);
        }
        e++;
    }
    while(top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // null terminate string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
