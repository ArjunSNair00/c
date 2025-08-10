#include <stdio.h>

#define MAX 100

// Operator stack
char opStk[MAX];
int opTop = -1;

// Evaluation stack
int valStk[MAX];
int valTop = -1;

// --- Operator stack functions ---
void opPush(char ch) { if (opTop < MAX - 1) opStk[++opTop] = ch; }
char opPop() { return (opTop == -1) ? -1 : opStk[opTop--]; }
int opEmpty() { return opTop == -1; }

// --- Value stack functions ---
void valPush(int n) { if (valTop < MAX - 1) valStk[++valTop] = n; }
int valPop() { return (valTop == -1) ? 0 : valStk[valTop--]; }
int valEmpty() { return valTop == -1; }

// Operator precedence
int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Infix → Postfix
void infixToPostfix(char* in, char* out) {
    opTop = -1;
    int j = 0;

    for (int i = 0; in[i] != '\0'; i++) {
        char ch = in[i];

        if (ch >= '0' && ch <= '9') {
            out[j++] = ch;
        }
        else if (ch == '(') {
            opPush(ch);
        }
        else if (ch == ')') {
            while (!opEmpty() && opStk[opTop] != '(') {
                out[j++] = opPop();
            }
            if (!opEmpty() && opStk[opTop] == '(') opPop();
        }
        else { // Operator
            while (!opEmpty() && opStk[opTop] != '(' &&
                   prec(opStk[opTop]) >= prec(ch)) {
                if (prec(opStk[opTop]) == prec(ch) && ch == '^') break;
                out[j++] = opPop();
            }
            opPush(ch);
        }
    }

    while (!opEmpty()) out[j++] = opPop();
    out[j] = '\0';
}

// Evaluate postfix
void evalPostfix(char* post) {
    valTop = -1;
    for (int i = 0; post[i] != '\0'; i++) {
        char ch = post[i];

        if (ch >= '0' && ch <= '9') {
            valPush(ch - '0');
        }
        else {
            int b = valPop();
            int a = valPop();
            int res = 0;

            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^':
                    res = 1;
                    for (int k = 0; k < b; k++) res *= a;
                    break;
            }
            valPush(res);
        }
    }
    if (!valEmpty()) printf("Result: %d\n", valPop());
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix (single-digit numbers): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    evalPostfix(postfix);

    return 0;
}
