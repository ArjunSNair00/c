#include <stdio.h>

void matrix(int m,int n,int x[m][n],int option)
{
    int i,j;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            option? printf("%d ",x[i][j]) : scanf("%d",&x[i][j]);
        option? printf("\n") : 0;
    }
}

void multiply_matrix(int m,int n,int p, int q,int a[m][n],int b[p][q],int c[m][q])
{
    int i,j,k;
    for (i=0;i<m;i++)
    {
        for (j=0;j<q;j++)
        {
            c[i][j]=0;
            for (k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
    }
}

int main()
{
    int m,n,p,q;
    printf("Enter the size of 1st matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter the size of 2nd matrix: ");
    scanf("%d %d",&p,&q);
    if (n!=p)
        printf("Matrix multiplication not possible");
    else
    {
        int a[m][n],b[p][q],c[m][q];
        printf("Enter the elements of 1st matrix: \n");
        matrix(m,n,a,0);
        printf("Enter the elements of 2nd matrix: \n");
        matrix(p,q,b,0);
        multiply_matrix(m,n,p,q,a,b,c);
        printf("The resultant matrix is: \n");
        matrix(m,q,c,1);
    }
    return 0;
}