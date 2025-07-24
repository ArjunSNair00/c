#include <stdio.h>

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int temp,m;
    int length = sizeof(nums) / sizeof(nums[0]);
    int step = 3;
    step=step%length; // Normalize step in case it's > length

    for (int i=0;i<length/2;i++) //reverese whole array
    {
        temp=nums[i];
        nums[i]=nums[length-1-i];
        nums[length-1-i]=temp;
    }
    m=length-step;

    for (int i=0;i<m/2;i++) //reverese first part of array
    {
        temp=nums[i];
        nums[i]=nums[m-1-i];
        nums[m-1-i]=temp;
    }

    for (int i = 0; i < step / 2; i++) {
        temp = nums[m + i];
        nums[m + i] = nums[length - 1 - i];
        nums[length - 1 - i] = temp;
    }
    

    // Print rotated array
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}