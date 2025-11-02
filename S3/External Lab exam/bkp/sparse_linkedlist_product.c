#include <stdio.h>
#include <stdlib.h>

// Define polynomial node
struct node {
    int coef;            // coefficient
    int exp;             // exponent
    struct node* link;   // next term
};

// Create a new node
struct node* createNode(int coef, int exp) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->link = NULL;
    return newNode;
}

// Insert term in descending order of exponent
// If same exponent exists, combine coefficients
//insertion sort
void insertTerm(struct node** head, int coef, int exp) {
    if (coef == 0) return;  // skip zero terms

    struct node* newNode = createNode(coef, exp);

    // Case 1: Empty list or new node has higher exponent
    if (*head == NULL || exp > (*head)->exp) {
        newNode->link = *head;
        *head = newNode;
        return;
    }

    struct node* curr = *head;
    struct node* prev = NULL;

    // Traverse to find correct position or same exponent
    while (curr != NULL && curr->exp > exp) {
        prev = curr;
        curr = curr->link;
    }

    // Case 2: Same exponent found → combine coefficients
    if (curr != NULL && curr->exp == exp) {
        curr->coef += coef;
        free(newNode);  // redundant new node not needed
        if (curr->coef == 0) {
            // remove node if coefficient became 0
            if (prev == NULL)
                *head = curr->link;
            else
                prev->link = curr->link;
            free(curr);
        }
    } else {
        // Case 3: Insert between prev and curr
        newNode->link = curr;
        if (prev != NULL)
            prev->link = newNode;
        else
            *head = newNode;
    }
}

// Display the polynomial neatly
void displayPoly(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coef);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        if (temp->link != NULL && temp->link->coef > 0)
            printf(" + ");
        else if (temp->link != NULL)
            printf(" ");
        temp = temp->link;
    }
    printf("\n");
}

// Multiply two polynomials
struct node* multiPoly(struct node* poly1, struct node* poly2) {
    struct node* product = NULL;
    for (struct node* i = poly1; i != NULL; i = i->link) {
        for (struct node* j = poly2; j != NULL; j = j->link) {
            insertTerm(&product, i->coef * j->coef, i->exp + j->exp);
        }
    }
    return product;
}

// Free a linked list
void freeList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

// Example usage
int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *product = NULL;

    // Example: 3x^2 + 2x + 1
    insertTerm(&poly1, 8, 16);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 1, 0);

    // Example: 2x + 4

    insertTerm(&poly2,10,16);
    insertTerm(&poly2,5,5);
    insertTerm(&poly2,2,2);
    insertTerm(&poly2,3,0);

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    product = multiPoly(poly1, poly2);

    printf("\nProduct: ");
    displayPoly(product);

    // Free all
    freeList(poly1);
    freeList(poly2);
    freeList(product);

    return 0;
}
