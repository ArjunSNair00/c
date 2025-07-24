/*given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.
{7 4 2 346 76 1 0 4}
target = 6
output = 1 2
*/
#include <stdio.h>
int main()
{
    int i,j;
    int num[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int result[2];
    printf("The array is: ");
    for (i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    int target;
    printf("Enter target: ");
    scanf("%d",&target);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (i!=j && num[i]+num[j] == target)
            {
                result[0]=i;
                result[1]=j;
                break;
            }
        }
    }
    printf("The indices are: ");
    for (i=0;i<2;i++)
    {
        printf("%d(%d) ",result[i],num[result[i]]);
    }
    return 0;
}

