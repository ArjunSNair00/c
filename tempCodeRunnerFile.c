#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, exp;
    struct node *link;
};

struct node *createtempnode(int co, int ex) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = co;
    newnode->exp = ex;
    newnode->link = NULL;
    return newnode;
}

struct node *createpoly() {
    struct node *head = NULL, *temp = NULL, *last = NULL;
    int n, coeff, exp, i;

    printf("\nEnter number of terms: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent (in decreasing order):\n");

    for (i = 0; i < n; i++) {
        scanf("%d%d", &coeff, &exp);
        temp = createtempnode(coeff, exp);

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->link = temp;
            last = temp;
        }
    }
    return head;
}

void displaypoly(struct node *temp) {
    if (temp == NULL) {
        printf("0\n");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->link;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct node *polyadd(struct node *head1, struct node *head2) {
    struct node *result = NULL, *last = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct node *temp;
        if (head1->exp > head2->exp) {
            temp = createtempnode(head1->coeff, head1->exp);
            head1 = head1->link;
        } else if (head2->exp > head1->exp) {
            temp = createtempnode(head2->coeff, head2->exp);
            head2 = head2->link;
        } else { // same exponent
            temp = createtempnode(head1->coeff + head2->coeff, head1->exp);
            head1 = head1->link;
            head2 = head2->link;
        }

        if (result == NULL)
            result = last = temp;
        else {
            last->link = temp;
            last = temp;
        }
    }

    while (head1 != NULL) {
        struct node *temp = createtempnode(head1->coeff, head1->exp);
        if (result == NULL)
            result = temp;
        else
            last->link = temp;
        last = temp;
        head1 = head1->link;
    }

    while (head2 != NULL) {
        struct node *temp = createtempnode(head2->coeff, head2->exp);
        if (result == NULL)
            result = temp;
        else
            last->link = temp;
        last = temp;
        head2 = head2->link;
    }

    return result;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL, *sum = NULL;

    printf("Enter Polynomial 1\n");
    head1 = createpoly();

    printf("\nEnter Polynomial 2\n");
    head2 = createpoly();

    printf("\nPolynomial 1: ");
    displaypoly(head1);

    printf("Polynomial 2: ");
    displaypoly(head2);

    sum = polyadd(head1, head2);

    printf("\nSum = ");
    displaypoly(sum);

    return 0;
}
