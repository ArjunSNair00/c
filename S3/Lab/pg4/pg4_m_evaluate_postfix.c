#include <stdio.h>
#include <math.h>
#define max 20

int stack[max];   // int stack for evaluation
int top = -1;

void push(int x) {
    if (top == max - 1)
        printf("Stack overflow\n");
    else 
        stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return 0;
    }
    return stack[top--];
}

int is_alnum(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    int a, b;
    char postfix[20] = "12+32*-";  // postfix expression
    char *p = postfix;

    printf("Postfix expression: %s\n", postfix);

    while (*p != '\0') {
        if (is_alnum(*p)) {
            push(*p - '0');   // convert char → int
        } else {
            b = pop();
            a = pop();
            switch (*p) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
                case '^':
                    push((int)pow(a, b));
                    break;
            }
        }
        p++;
    }

    printf("Result: %d\n", pop());

    return 0;
}