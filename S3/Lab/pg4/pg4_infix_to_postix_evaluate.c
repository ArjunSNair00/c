#include <stdio.h>
#include <math.h>
#define max 100

// ---------------- Infix → Postfix ----------------
char opStack[max];   // operator stack
int topOp = -1;

void pushOp(char x) {
    opStack[++topOp] = x;
}

char popOp() {
    return opStack[topOp--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

int is_num(char c) {
    return (c >= '0' && c <= '9');  // only digits
}

void infixToPostfix(char infix[], char postfix[]) {
    char *e = infix, x;
    int k = 0;

    while (*e != '\0') {
        if (is_num(*e)) {
            postfix[k++] = *e;
        } 
        else if (*e == '(') {
            pushOp(*e);
        } 
        else if (*e == ')') {
            while ((x = popOp()) != '(') {
                postfix[k++] = x;
            }
        } 
        else { // operator
            while (topOp != -1 && priority(opStack[topOp]) >= priority(*e)) {
                postfix[k++] = popOp();
            }
            pushOp(*e);
        }
        e++;
    }
    while (topOp != -1) {
        postfix[k++] = popOp();
    }
    postfix[k] = '\0';
}

// ---------------- Evaluate Postfix ----------------
int valStack[max];
int topVal = -1;

void pushVal(int x) {
    valStack[++topVal] = x;
}

int popVal() {
    return valStack[topVal--];
}

int evaluatePostfix(char postfix[]) {
    char *p = postfix;
    int a, b;
    while (*p != '\0') {
        if (is_num(*p)) {
            pushVal(*p - '0');  // convert char → int
        } else {
            b = popVal();
            a = popVal();
            switch (*p) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
                case '^': pushVal((int)pow(a, b)); break;
            }
        }
        p++;
    }
    return popVal();
}

// ---------------- Main ----------------
int main() {
    char infix[20], postfix[20];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
