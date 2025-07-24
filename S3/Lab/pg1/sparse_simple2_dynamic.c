#include <stdio.h>
#include <stdlib.h>
//#define max_expo 100
void read_poly(int poly[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        int coeff, expo;
        scanf("%d %d", &coeff, &expo);
        poly[expo] += coeff; //handling duplicates
    }
}

int main() {
    int n1, n2, max_expo;
    
    printf("Enter maximum exponent: ");
    scanf("%d", &max_expo);
    
    printf("Enter number of non-zero terms in first and second polynomial: ");
    scanf("%d %d", &n1, &n2);
    
    // Allocate arrays based on user input
    int *poly1 = calloc(max_expo + 1, sizeof(int)); //+ 1 because exponent starts from 0 to maximum exponent
    int *poly2 = calloc(max_expo + 1, sizeof(int));
    int *sum = calloc(max_expo + 1, sizeof(int));
    
    printf("Enter coefficient and exponent of polynomial 1:\n");
    read_poly(poly1, n1);
    printf("Enter coefficient and exponent of polynomial 2:\n");
    read_poly(poly2, n2);

    // Add polynomials
    for (int i = 0; i <= max_expo; i++)
        sum[i] = poly1[i] + poly2[i];

    // Print sum
    printf("Sum of the polynomials: ");
    int first = 1;
    for (int i = max_expo; i >= 0; i--)
    {
        if (sum[i] == 0) 
            continue;
        first && sum[i] > 0 ? printf("%d", sum[i]) : printf("%+d", sum[i]);
        first = 0;
        i == 0 ? printf(" ") : (i == 1 ? printf("x ") : printf("x^%d ", i));
    }  

    if (first)
        printf("0");
        
    free(poly1);
    free(poly2);
    free(sum);
    printf("\n");
    return 0;
}