#include <stdio.h>
int main()
{
    int m,n,p,q,i,j,k;
    printf("Enter number of rows and columns of 1st matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter number of rows and columns of 2nd matrix: ");
    scanf("%d%d",&p,&q);
    if (n!=p)
        printf("Matrix multiplication not possible");
    else
    {
        int a[m][n],b[p][q],c[m][q];
        printf("Enter elements of 1st matrix: \n");
        for (i=0;i<m;i++)
            for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        printf("Enter elements of 2nd matrix: \n");
        for (i=0;i<p;i++)
            for (j=0;j<q;j++)
                scanf("%d",&b[i][j]);
        printf("the resultant matrix is: \n");
        for (i=0;i<m;i++)
        {
            printf("[ ");
            for (j=0;j<q;j++)
            {
                c[i][j]=0;
                for (k=0;k<n;k++)
                    c[i][j]+=a[i][k]*b[k][j];
                printf("%d ",c[i][j]);
            }
            printf("]\n");
        }
    }
    return 0;
}