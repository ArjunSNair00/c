#include <stdio.h>
#include <stdlib.h> // Included for general utility, but not strictly required for this code

// Max stack size
#define MAX_SIZE 100

// Stack implementation for operator conversion
char op_stack[MAX_SIZE];
int op_top = -1;

// Stack implementation for postfix evaluation
int eval_stack[MAX_SIZE];
int eval_top = -1;

// Function prototypes for operator stack
void op_push(char item);
char op_pop();
int op_is_empty();
int op_is_full();

// Function prototypes for evaluation stack
void eval_push(int item);
int eval_pop();
int eval_is_empty();

int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
void evaluatePostfix(char* postfix);

// --- Operator Stack Functions ---
void op_push(char item) {
    if (op_top >= MAX_SIZE - 1) {
        printf("Operator Stack Overflow\n");
    } else {
        op_top++;
        op_stack[op_top] = item;
    }
}

char op_pop() {
    if (op_top == -1) {
        return -1;
    } else {
        char item = op_stack[op_top];
        op_top--;
        return item;
    }
}

int op_is_empty() {
    return op_top == -1;
}

int op_is_full() {
    return op_top == MAX_SIZE - 1;
}

// --- Evaluation Stack Functions ---
void eval_push(int item) {
    if (eval_top >= MAX_SIZE - 1) {
        printf("Evaluation Stack Overflow\n");
    } else {
        eval_top++;
        eval_stack[eval_top] = item;
    }
}

int eval_pop() {
    if (eval_top == -1) {
        printf("Evaluation Stack Underflow\n");
        return 0; // Return 0 or handle error appropriately
    } else {
        int item = eval_stack[eval_top];
        eval_top--;
        return item;
    }
}

int eval_is_empty() {
    return eval_top == -1;
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert an infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    op_top = -1; // Reset operator stack
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current_char = infix[i];

        if (current_char >= '0' && current_char <= '9') {
            postfix[j++] = current_char;
        } else if (current_char == '(') {
            op_push(current_char);
        } else if (current_char == ')') {
            while (!op_is_empty() && op_stack[op_top] != '(') {
                postfix[j++] = op_pop();
            }
            if (!op_is_empty() && op_stack[op_top] == '(') {
                op_pop(); // Discard the '('
            }
        } else { // Operator
            while (!op_is_empty() && op_stack[op_top] != '(' && precedence(op_stack[op_top]) >= precedence(current_char)) {
                if (precedence(op_stack[op_top]) == precedence(current_char) && current_char == '^') {
                    break;
                }
                postfix[j++] = op_pop();
            }
            op_push(current_char);
        }
    }

    while (!op_is_empty()) {
        postfix[j++] = op_pop();
    }
    postfix[j] = '\0';
}

// Function to evaluate a postfix expression
void evaluatePostfix(char* postfix) {
    eval_top = -1; // Reset evaluation stack
    int a, b, result;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current_char = postfix[i];

        if (current_char >= '0' && current_char <= '9') {
            eval_push(current_char - '0'); // Convert char to int and push
        } else { // Operator
            b = eval_pop();
            a = eval_pop();

            switch (current_char) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^':
                    result = 1;
                    for(int k = 0; k < b; k++) {
                        result *= a;
                    }
                    break;
            }
            eval_push(result);
        }
    }

    if (!eval_is_empty()) {
        printf("Result of evaluation: %d\n", eval_pop());
    }
}

int main() {
    char infix_expr[MAX_SIZE];
    char postfix_expr[MAX_SIZE];

    printf("Enter an infix expression (single-digit operands only): ");
    scanf("%s", infix_expr);
    
    printf("Infix expression: %s\n", infix_expr);
    
    // Convert infix to postfix
    infixToPostfix(infix_expr, postfix_expr);
    printf("Postfix expression: %s\n", postfix_expr);

    // Evaluate the postfix expression
    evaluatePostfix(postfix_expr);
    
    return 0;
}
