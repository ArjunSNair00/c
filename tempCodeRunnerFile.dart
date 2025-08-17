#include <stdio.h>

#define MAX 100

// Stacks
char opStack[MAX];
int evalStack[MAX];
int topOp = -1, topEval = -1;

// ----- Operator Stack -----
void pushOp(char c) { opStack[++topOp] = c; }
char popOp() { return opStack[topOp--]; }
char peekOp() { return (topOp != -1) ? opStack[topOp] : '\0'; }
int isEmptyOp() { return topOp == -1; }

// ----- Evaluation Stack -----
void pushEval(int val) { evalStack[++topEval] = val; }
int popEval() { return evalStack[topEval--]; }

// ----- Precedence -----
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// ----- Power Function (integer exponentiation) -----
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// ----- Infix → Postfix -----
void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char symbol = infix[i];

        // If operand (digit), add to postfix
        if (symbol >= '0' && symbol <= '9') {
            postfix[k++] = symbol;
        }
        // If '(', push
        else if (symbol == '(') {
            pushOp(symbol);
        }
        // If ')', pop until '('
        else if (symbol == ')') {
            while (!isEmptyOp() && peekOp() != '(') {
                postfix[k++] = popOp();
            }
            popOp(); // discard '('
        }
        // If operator
        else {
            while (!isEmptyOp() && precedence(peekOp()) >= precedence(symbol)) {
                postfix[k++] = popOp();
            }
            pushOp(symbol);
        }
    }

    // Pop remaining operators
    while (!isEmptyOp()) {
        postfix[k++] = popOp();
    }

    postfix[k] = '\0'; // terminate string
}

// ----- Postfix Evaluation -----
int evaluatePostfix(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        if (symbol >= '0' && symbol <= '9') {
            pushEval(symbol - '0');  // convert char to int
        } else {
            int val2 = popEval();
            int val1 = popEval();
            int result;

            switch (symbol) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = power(val1, val2); break;
                default: result = 0;
            }
            pushEval(result);
        }
    }
    return popEval();
}

// ----- Main -----
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (digits only, no spaces): ");
    scanf("%s", infix);

    // Convert and print postfix
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Evaluate postfix
    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);

    return 0;
}
