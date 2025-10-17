#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Stack {
    struct Node *arr[50];
    int top;
} Stack;

Node *createNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(Stack *s, Node *node) {
    s->arr[++s->top] = node;
}

Node *pop(Stack *s) {
    if (s->top == -1) {
        return NULL;
    }
    return s->arr[s->top--];
}

int is_operand(char ch) {
    return isalnum(ch);
}

Node *buildExpressionTree(char postfix[]) {
    Stack s;
    s.top = -1;
    int i;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (is_operand(ch)) {
            push(&s, createNode(ch));
        } else {
            Node *newNode = createNode(ch);
            Node *right = pop(&s);
            Node *left = pop(&s);
            newNode->left = left;
            newNode->right = right;
            push(&s, newNode);
        }
    }
    return pop(&s);
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    char postfix[50];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    Node *root = buildExpressionTree(postfix);
    printf("Equivalent prefix expression: ");
    preorder(root);
    printf("\n");

    return 0;
}
