#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// -------------------- STACKS --------------------
char opStack[MAX];    // operator stack (for infix to postfix)
int opTop = -1;

int valStack[MAX];    // operand stack (for postfix evaluation)
int valTop = -1;

// -------------------- STACK FUNCTIONS --------------------
void pushOp(char x) {
    if (opTop == MAX - 1) return;
    opStack[++opTop] = x;
}

char popOp() {
    if (opTop == -1) return '\0';
    return opStack[opTop--];
}

void pushVal(int x) {
    if (valTop == MAX - 1) return;
    valStack[++valTop] = x;
}

int popVal() {
    if (valTop == -1) { return 0;
    }
    return valStack[valTop--];
}

// -------------------- PRIORITY --------------------
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return -1;
}

// -------------------- INFIX TO POSTFIX --------------------
void infixToPostfix(char infix[], char postfix[]) {
    char *e = infix, x;
    int k = 0;

    while (*e != '\0') {
        if (isalnum(*e)) {
            postfix[k++] = *e;
        } else if (*e == '(') {
            pushOp(*e);
        } else if (*e == ')') {
            while ((x = popOp()) != '(')
                postfix[k++] = x;
        } else {
            while (opTop != -1 && priority(opStack[opTop]) >= priority(*e))
                postfix[k++] = popOp();
            pushOp(*e);
        }
        e++;
    }
    while (opTop != -1)
        postfix[k++] = popOp();

    postfix[k] = '\0';
}

// -------------------- EVALUATE POSTFIX --------------------
int evaluatePostfix(char exp[]) {
    char *e = exp;
    int a, b, c;

    while (*e != '\0') {
        if (isdigit(*e))
          pushVal(*e - '0'); // convert char → int
        else{
          b = popVal(); // right operand
          a = popVal(); // left operand
          switch (*e) {
            case '+': c = a + b; break;
            case '-': c = a - b; break;
            case '*': c = a * b; break;
            case '/': c = a / b; break;
            case '^': c = pow(a, b); break;
            default:
              printf("Invalid operator: %c\n", *e);
              return 0;
          }
          pushVal(c);
        }
        e++;
    }
    return popVal();
}

// -------------------- MAIN --------------------
int main() {
    char infix[MAX], postfix[MAX];

    // Example
    strcpy(infix, "2*3+4*(5-6)");

    printf("Infix: %s\n", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
