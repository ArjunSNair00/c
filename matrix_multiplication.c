#include <stdio.h>
int main()
{
    int m,n,p,q,i,j,k,sum;
    printf("Enter the number of rows and columns of 1st matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter the number of rows and columns of 2nd matrix: ");
    scanf("%d%d",&p,&q);
    if (n!=p)
    {
        printf("Matrix multiplication not possible");
    }
    else
    {
        int a[m][n],b[p][q],c[m][q];
        printf("Enter the elements of 1st matrix: \n");
        for (i=0;i<m;i++)
            for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        printf("Enter the elements of 2nd matrix: \n");
        for (i=0;i<p;i++)
            for (j=0;j<q;j++)
                scanf("%d",&b[i][j]);
        for (i=0;i<m;i++)
        {
            for (j=0;j<q;j++)
            {
                sum=0;
                for (k=0;k<n;k++)
                {
                    sum+=a[i][k]*b[k][j];
                }
                c[i][j]=sum;
            }
        }
        printf("The resultant matrix is: \n");
        for (i=0;i<m;i++)
        {
            printf("[");
            for (j=0;j<q;j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("]\n");
        }
    }
    return 0;
}