#include <stdio.h>
int main()
{
    int temp,i,j,n;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int num[n];
    printf("Enter elements in array: ");
    for (i=0;i<n;i++)
        scanf("%d",&num[i]);
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if (num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    printf("The sorted array is: { ");
    for (i=0;i<n;i++)
    {
        printf("%d",num[i]);
        if (i<n-1)
            printf(", ");
    }
    printf(" }");
    return 0;
}