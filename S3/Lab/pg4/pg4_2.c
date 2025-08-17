#include <stdio.h>
#define MAX 1000

char ops[MAX];
int opTop = -1;

int vals[MAX];
int valTop = -1;

void pushOp(char c) { ops[++opTop] = c; }
char popOp() { return opTop == -1 ? '\0' : ops[opTop--]; }
int emptyOp() { return opTop == -1; }

void pushVal(int v) { vals[++valTop] = v; }
int popVal() { return valTop == -1 ? 0 : vals[valTop--]; }
int emptyVal() { return valTop == -1; }

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int strLength(char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void removeNewline(char *s) {
    int len = strLength(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
}

void toPostfix(char *in, char *out) {
    opTop = -1;
    int j = 0;

    for (int i = 0; in[i] != '\0'; i++) {
        char c = in[i];

        if (c == ' ') continue; // skip spaces

        if (isDigit(c)) {
            // collect full number
            while (isDigit(in[i])) {
                out[j++] = in[i++];
            }
            out[j++] = ' '; // delimiter
            i--;            // step back
        }
        else if (c == '(') {
            pushOp(c);
        }
        else if (c == ')') {
            while (!emptyOp() && ops[opTop] != '(') {
                out[j++] = popOp();
                out[j++] = ' ';
            }
            if (!emptyOp()) popOp(); // remove '('
        }
        else { // operator
            while (!emptyOp() && ops[opTop] != '(' &&
                   precedence(ops[opTop]) >= precedence(c)) {
                if (precedence(ops[opTop]) == precedence(c) && c == '^') break;
                out[j++] = popOp();
                out[j++] = ' ';
            }
            pushOp(c);
        }
    }
    while (!emptyOp()) {
        out[j++] = popOp();
        out[j++] = ' ';
    }
    out[j] = '\0';
}

void evalPostfix(char *post) {
    valTop = -1;
    for (int i = 0; post[i] != '\0'; i++) {
        char c = post[i];

        if (c == ' ') continue;

        if (isDigit(c)) {
            int num = 0;
            while (isDigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            pushVal(num);
            i--; // step back
        }
        else { // operator
            int b = popVal();
            int a = popVal();
            int r = 0;
            switch (c) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        return;
                    }
                    r = a / b;
                    break;
                case '^':
                    r = 1;
                    for (int k = 0; k < b; k++) r *= a;
                    break;
            }
            pushVal(r);
        }
    }
    if (!emptyVal()) printf("Result: %d\n", popVal());
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin); // safer input
    removeNewline(infix);

    toPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    evalPostfix(postfix);

    return 0;
}
