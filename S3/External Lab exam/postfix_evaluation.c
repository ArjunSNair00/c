#include <stdio.h>
#include <ctype.h>
#include <math.h>   // for pow()
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}

int evaluate(char exp[]) {
    char *e = exp;
    int a, b, c;

    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0');  // Convert '3' → 3
        } else {
            b = pop(); // right operand
            a = pop(); // left operand
            switch (*e) {
                case '+': c = a + b; break;
                case '-': c = a - b; break;
                case '*': c = a * b; break;
                case '/': c = a / b; break;
                case '^': c = pow(a, b); break; // a^b
                default:
                    printf("Invalid operator: %c\n", *e);
                    return 0;
            }
            push(c);
        }
        e++;
    }
    return pop();
}


int main() {
    char postfix[] = "23*456-*+";
    int result = evaluate(postfix);
    printf("Result = %d\n", result);

    // Example with power operator
    char exp2[] = "23^"; // means 2^3
    printf("Result of 2^3 = %d\n", evaluate(exp2));

    return 0;
}
