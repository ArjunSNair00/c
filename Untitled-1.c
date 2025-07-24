#include <stdio.h>
int main()
{
    int num[]={34,2,12,23,56,354,13},temp,size=7;
    for (int i=0;i<size-1;i++)
    {
        for (int j=0;j<size-i-1;j++)
        {
            if (num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for (int i=0;i<size;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}