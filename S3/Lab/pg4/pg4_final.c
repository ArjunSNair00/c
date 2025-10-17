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
        // ---- If digit, read full number ----
        if (is_num(*e)) {
            while (is_num(*e)) {     // collect full number
                postfix[k++] = *e;
                e++;
            }
            postfix[k++] = ' ';      // add space separator
            continue;                // skip extra e++ at bottom
        }
        // ---- If '(' push to stack ----
        else if (*e == '(') {
            pushOp(*e);
        }
        // ---- If ')' pop until '(' ----
        else if (*e == ')') {
            while ((x = popOp()) != '(') {
                postfix[k++] = x;
                postfix[k++] = ' ';  // space after operator
            }
        }
        // ---- If operator ----
        else {
            while (topOp != -1 && priority(opStack[topOp]) >= priority(*e)) {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            pushOp(*e);
        }
        e++;
    }

    // ---- Pop remaining operators ----
    while (topOp != -1) {
        postfix[k++] = popOp();
        postfix[k++] = ' ';
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
            int num = 0;
            // read full multi-digit number
            while (is_num(*p)) {
                num = num * 10 + (*p - '0');
                p++;
            }
            pushVal(num);
        } 
        else if (*p == ' ') {
            // skip spaces
            p++;
            continue;
        }
        else {
            b = popVal();
            a = popVal();
            switch (*p) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
                case '^': pushVal((int)pow(a, b)); break;
            }
            p++;
        }
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
