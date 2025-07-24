#include <stdio.h>

#define MAX_TERMS 100

// Structure to store a term (coefficient and exponent)
struct Term {
    int coeff;
    int exp;
};

int main() {
    struct Term poly[MAX_TERMS];
    int n;

    printf("Enter the number of non-zero terms in the polynomial: ");
    scanf("%d", &n);

    // Input terms
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }

    // Display the polynomial
    printf("\nThe sparse polynomial is:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%+dx^%d ", poly[i].coeff, poly[i].exp);
    }
    printf("\n");

    return 0;
}
