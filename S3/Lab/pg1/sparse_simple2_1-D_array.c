#include <stdio.h>
#define max 100 // assume maximum exponent is 100

void read_poly(int poly[],int n)
{
    for (int i = 0; i < n; i++) 
    {
    int coeff, expo;
    scanf("%d %d", &coeff, &expo);
    poly[expo] += coeff; //handling duplicates: if two terms have the same exponent, they get added automatically. eg: 3 2 4 2
    }
}
int main() {
    int n1, n2;
    printf("Enter number of non-zero terms in first and second polynomial: ");
    scanf("%d %d",&n1,&n2);
    int poly1[max+1] = {0};
    int poly2[max+1] = {0};
    int sum[max+1] = {0};
    printf("Enter coefficient and exponent of polynomial l:\n");
    read_poly(poly1,n1);
    printf("Enter coefficient and exponent of polynomial 2:\n");
    read_poly(poly2,n2);

    // Add polynomials
    for (int i = 0; i <= max; i++)
        sum[i] = poly1[i] + poly2[i];

    // Print sum
    printf("Sum of the polynomials: ");
    int first = 1; //flag for indicating first term
    for (int i = max; i >= 0; i--)
    {
        if (sum[i]==0) 
            continue;
        first && sum[i]>0 ? printf("%d",sum[i]) : printf("%+d",sum[i]);
        i == 0 ? printf(" ") :(i== 1 ? printf("x ") :printf("x^%d ", i));
        first = 0; //no longer the first term
    }  

    if (first)  // If no terms were printed, print 0 - indicating polynomials cancelled each other
        printf("0");

    printf("\n");
    return 0;
}