#include <stdio.h>

struct term {
    int coef;
    int exp;
};

void sort_terms(int size, struct term poly[]) //bubble sort
{
    struct term temp;
    for (int i=0;i<size-1;i++)
    {
        for (int j=0;j<size-i-1;j++)
        {
            if (poly[j].exp < poly[j+1].exp) //sort in descending order
            {
                temp=poly[j];
                poly[j]=poly[j+1];
                poly[j+1]=temp;
            }}}}

void read_term(int n, struct term poly[]) 
{
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &poly[i].coef, &poly[i].exp);
    }
}

void print_terms(int n, struct term poly[]) 
{
    for (int i = 0; i < n; i++) {
        printf("%+dx^%d ", poly[i].coef, poly[i].exp);
    }
}

int main() 
{
    int n1, n2;
    printf("Enter the number of non-zero terms of 1st polynomial: ");
    scanf("%d", &n1);
    struct term poly1[n1];
    printf("Enter the terms of polynomial 1:\n");
    read_term(n1, poly1);
    sort_terms(n1, poly1);
    printf("Enter the number of non-zero terms of 2nd polynomial: ");
    scanf("%d", &n2);
    struct term poly2[n2];
    printf("Enter the terms of polynomial 2:\n");
    read_term(n2, poly2);
    sort_terms(n2, poly2);
    struct term sum[n1 + n2]; //assume the worst case scenario for memory
    int i = 0, j = 0, k = 0;

    // Merge process
    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            sum[k].exp = poly1[i].exp;
            sum[k].coef = poly1[i].coef + poly2[j].coef;
            i++; j++; k++;
        } else if (poly1[i].exp > poly2[j].exp) {
            sum[k++] = poly1[i++];
            //sum[k]=poly1[i];
            //k++;i++;
        } else {
            sum[k++] = poly2[j++];
            //sum[k]=poly2[j];
            //k++;j++;
        }
    }

    while (i < n1) 
        sum[k++] = poly1[i++]; //for remaining terms in poly1
    while (j < n2) 
        sum[k++] = poly2[j++]; //for remaining terms in poly2

    printf("\nThe sum of the two sparse polynomials is:\n");
    print_terms(k, sum);

    return 0;
}