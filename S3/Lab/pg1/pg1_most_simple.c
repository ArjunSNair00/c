#include <stdio.h>

int main() {
    int n, m, i, index;
    
    printf("Enter the degree of first polynomial: ");
    scanf("%d", &n);
    printf("Enter the degree of second polynomial: ");
    scanf("%d", &m);
    int a[n+1],b[m+1];
    if (n > m)
        index=n;
    else
        index=m;
    int sum[index+1];
    //a array read cheyyan
    for(i = 0; i <= n; i++) {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }
    //b array read cheyyan
    for(i = 0; i <= m; i++) {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &b[i]);
    }
    //sum array initialize cheyyan
    for(i = 0; i <= index; i++) {
        sum[i] = 0;
    }
    //sum arraylekku a arraylolla elements copy cheyyan
    for(i = 0; i <= n; i++) {
        sum[i] += a[i];
    }
    //sum arraylekku b arraylolla elements add cheyyan
    for(i = 0; i <= m; i++) {
        sum[i] += b[i];
    }

    // display cheyyan
    printf("Sum of polynomials: ");
    for(i = index; i >= 0; i--) {
        if(sum[i] != 0) {
            printf("%dx^%d", sum[i], i);
            if(i != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");

    return 0;
}
