#include <stdio.h>
int main() {
    int m, n, i, j;
    printf("enter the size of the first polynomial array(degree):\n");
    scanf("%d", &n);
    printf("enter the size of the second polynomial array(degree):\n");
    scanf("%d", &m);
    int a[n + 1], b[m + 1], index;
    if (n > m) {
        index = n;
    } else {
        index = m;
    }
    int sum[index + 1];
    printf("enter the coefficients of first polynomial\n");
    for (i = 0; i <= n; i++) {
        printf("enter the coefficient of power of first polynomial:\n");
        scanf("%d", &a[i]);
    }
    printf("enter the coefficient of second polynomial\n");
    for (i = 0; i <= m; i++) {
        printf("enter the coefficient of power of second polynomial:\n");
        scanf("%d", &b[i]);
    }
    for (i = 0; i <= index; i++) {
        sum[i] = a[i] + b[i];
    }
    printf("sum of the polynomials are ;\n");
    for (i = 0; i <= index; i++) {
        printf("%dx^%d + ", sum[i], i);
    }
    return 0;
}