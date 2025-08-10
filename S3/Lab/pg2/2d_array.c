#include <stdio.h>
int main()
{
    int r,c,e1=0,e2=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&r,&c);
    int m1[r][c],m2[r][c];
    printf("Enter the elements of matrix 1:  \n");
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        {
            scanf("%d",&m1[i][j]);
            if (m1[i][j]!=0)
                e1++;
        }
    printf("Enter the elements of matrix 2:  \n");
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        {
            scanf("%d",&m2[i][j]);
            if (m2[i][j]!=0)
                e2++;
        }
    int sp1[e1][3],sp2[e2][3];
    printf("The tuple representation of first sparse matrix is: \n");
    printf("r c v\n");
    int row=0;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        {
            if (m1[i][j]!=0)
            {
                sp1[row][0]=i;
                sp1[row][1]=j;
                sp1[row][2]=m1[i][j];
                printf("%d %d %d\n",sp1[row][0],sp1[row][1],sp1[row][2]);
                row++;
            }
        }
    printf("The tuple representation of second sparse matrix is: \n");
    printf("r c v\n");
    row=0;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
        {
            if (m2[i][j]!=0)
            {
                sp2[row][0]=i;
                sp2[row][1]=j;
                sp2[row][2]=m2[i][j];
                printf("%d %d %d\n",sp2[row][0],sp2[row][1],sp2[row][2]);
                row++;
            }
        }
    int sum[e1+e2][3];
    int i=0,j=0,k=0;
    while (i<e1 && j<e2)
    {
        if (sp1[i][0]==sp2[j][0] && sp1[i][1]==sp2[j][1])
        {
            sum[k][0]=sp1[i][0];
            sum[k][1]=sp1[i][1];
            sum[k][2]=sp1[i][2]+sp2[j][2];
            i++;j++;k++;
        }
        else if (sp1[i][0]<sp2[j][0] || (sp1[i][0]==sp2[j][0] && sp1[i][1]<sp2[j][1]))
        {
            sum[k][0]=sp1[i][0];
            sum[k][1]=sp1[i][1];
            sum[k][2]=sp1[i][2];
            i++;k++;
        }
        else
        {
            sum[k][0]=sp2[j][0];
            sum[k][1]=sp2[j][1];
            sum[k][2]=sp2[j][2];
            j++;k++;
        }
    }
    while (i<e1)
    {
            sum[k][0]=sp1[i][0];
            sum[k][1]=sp1[i][1];
            sum[k][2]=sp1[i][2];
            i++;k++;
    }
    while (j<e2)
    {
            sum[k][0]=sp2[j][0];
            sum[k][1]=sp2[j][1];
            sum[k][2]=sp2[j][2];
            j++;k++;
    }
    printf("The tuple representation of sum matrix is: \n");
    for (int i=0;i<k;i++)
    {
        printf("%d %d %d\n",sum[i][0],sum[i][1],sum[i][2]);
    }

    int t[k][3];
    printf("The transpose of tuple representation of sum matrix is: \n");
    for (int i=0;i<k;i++){
        t[i][0]=sum[i][1];
        t[i][1]=sum[i][0];
        t[i][2]=sum[i][2];
        printf("%d %d %d\n",t[i][0],t[i][1],t[i][2]);
    }
    return 0;
}