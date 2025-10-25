#include <stdio.h>

int main() {
    int m1, m2;

    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &m1);

    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &m2);

    int p1[2 * m1], p2[2 * m2], p3[2 * (m1 + m2)];
    int k = 0;

    // --- Input first polynomial ---
    printf("Enter coefficient and exponent of first polynomial (in decreasing order of exponent):\n");
    for (int i = 0; i < 2 * m1; i += 2) {
        scanf("%d %d", &p1[i], &p1[i + 1]);
    }

    // --- Input second polynomial ---
    printf("Enter coefficient and exponent of second polynomial (in decreasing order of exponent):\n");
    for (int i = 0; i < 2 * m2; i += 2) {
        scanf("%d %d", &p2[i], &p2[i + 1]);
    }

    // --- Add both polynomials ---
    int i = 0, j = 0;
    while (i < 2 * m1 && j < 2 * m2) {
        // Compare exponents
        if (p1[i + 1] == p2[j + 1]) {
            // same exponent → add coefficients
            p3[k] = p1[i] + p2[j];
            p3[k + 1] = p1[i + 1];
            i += 2; j += 2; k += 2;
        } else if (p1[i + 1] > p2[j + 1]) {
            // copy from p1
            p3[k] = p1[i];
            p3[k + 1] = p1[i + 1];
            i += 2; k += 2;
        } else {
            // copy from p2
            p3[k] = p2[j];
            p3[k + 1] = p2[j + 1];
            j += 2; k += 2;
        }
    }

    // --- Copy remaining terms (if any) ---
    while (i < 2 * m1) {
        p3[k] = p1[i];
        p3[k + 1] = p1[i + 1];
        i += 2; k += 2;
    }
    while (j < 2 * m2) {
        p3[k] = p2[j];
        p3[k + 1] = p2[j + 1];
        j += 2; k += 2;
    }

    // --- Display result ---
    printf("\nResultant Polynomial after addition:\n");
    for (int x = 0; x < k; x += 2) {
        printf("(%dx^%d)", p3[x], p3[x + 1]);
        if (x + 2 < k)
            printf(" + ");
    }

    printf("\n");
    return 0;
}
