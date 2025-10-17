#include <stdio.h>
#define MAX 100

int main() {
    int n, m, i;
    printf("Enter the degree of first polynomial: ");
    scanf("%d", &n);
    printf("Enter the degree of second polynomial: ");
    scanf("%d", &m);

    int max_deg = (n > m) ? n : m;
    int a[MAX + 1] = {0}, b[MAX + 1] = {0}, sum[MAX + 1] = {0};

    printf("Enter the coefficients of first polynomial (descending order of exponents):\n");
    for (i = n; i >= 0; i--) {
        scanf("%d", &a[i]);
    }

    printf("Enter the coefficients of second polynomial (descending order of exponents):\n");
    for (i = m; i >= 0; i--) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i <= max_deg; i++) {
        sum[i] = a[i] + b[i];
    }

    printf("Sum of the polynomials: ");

    int first = 1;
    for (i = max_deg; i >= 0; i--) {
        if (sum[i] == 0) continue;
        printf("%+d^%d", sum[i], i);
        first = 0;
    }

    if (first) {
        printf("0"); 
    }

    printf("\n");
    return 0;
}
