#include <stdio.h>
int main()
{
    int size=5,i,j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<size-i-1;j++)
        {
            printf(" ");
        }
        for (j=0;j<i+1;j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    for (i=size-1;i>0;i--)
    {
        for (j=size-i;j>0;j--)
        {
            printf(" ");
        }
        for (j=i;j>0;j--)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}