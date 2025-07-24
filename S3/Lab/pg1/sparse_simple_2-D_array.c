#include <stdio.h>

int main() 
{
    int n1, n2;
    printf("Enter the number of non-zero terms of first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the number of non-zero terms of second polynomial: ");
    scanf("%d", &n2);

    int poly1[2][n1], poly2[2][n2];

    printf("Enter the coefficient and exponent of each term in polynomial 1 (in descending order):\n");
    for (int i = 0; i < n1; i++) 
    {
        scanf("%d %d", &poly1[0][i], &poly1[1][i]);
    }

    printf("Enter the coefficient and exponent of each term in polynomial 2 (in descending order):\n");
    for (int i = 0; i < n2; i++) 
    {
        scanf("%d %d", &poly2[0][i], &poly2[1][i]);
    }

    int sum[2][n1 + n2];
    int i = 0, j = 0, k = 0;

    // Merge terms
    while (i < n1 && j < n2) 
    {
        if (poly1[1][i] == poly2[1][j]) 
        {
            sum[0][k] = poly1[0][i] + poly2[0][j];
            sum[1][k] = poly1[1][i];
            i++; j++; k++;
        } 
        else if (poly1[1][i] > poly2[1][j]) 
        {
            sum[0][k] = poly1[0][i];
            sum[1][k] = poly1[1][i];
            i++; k++;
        } 
        else 
        {
            sum[0][k] = poly2[0][j];
            sum[1][k] = poly2[1][j];
            j++; k++;
        }
    }

    // copying remaining terms
    while (i < n1) 
    {
        sum[0][k] = poly1[0][i];
        sum[1][k] = poly1[1][i];
        i++; k++;
    }
    while (j < n2) 
    {
        sum[0][k] = poly2[0][j];
        sum[1][k] = poly2[1][j];
        j++; k++;
    }

    // Print the resulting polynomial
    printf("Sum of the polynomials: ");
    for (int i=0;i<k;i++)
    {
        if (sum[0][i]==0) //if coefficient is 0
            continue;
        i==0 && sum[0][i]>0 ? printf("%d",sum[0][i]) : printf("%+d",sum[0][i]); //IF COEFFICENT IS a positive first term
        sum[1][i] == 0 ? printf(" ") :(sum[1][i] == 1 ? printf("x ") :printf("x^%d ", sum[1][i])); //if coefficient is 0 or 1 or more than 1
    }
    return 0;
}
