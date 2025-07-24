#include <stdio.h>
//rotate array by n steps 
void rotate_once_right_steps(int nums[],int length,int steps)
{

    steps=steps%length; // Normalize step in case it's > length

    for (int i=0;i<steps;i++)
    {
        int last=nums[length-1];
        for (int j=(length-1);j>=0;j--)
        {
            nums[j]=nums[j-1];
        }   
        nums[0]=last;
    }
}

int main()
{
    int nums[]={1,2,3,4,5};
    int length=sizeof(nums)/sizeof(nums[0]);
    int n=2; 

    rotate_once_right_steps(nums,length,n);

    for (int i=0;i<length;i++)
    {
        printf("%d ",nums[i]);
    }
    return 0;
}