#include <stdio.h>

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(nums) / sizeof(nums[0]);
    int step = 5;
    step=step%length; // Normalize step in case it's > length
    
    int numms[length];
    int s;

    for (int i = 0; i < length; i++) {
        s=(i+step)%length;
        numms[s]=nums[i];
    }

    // Print rotated array
    for (int i = 0; i < length; i++) {
        printf("%d ", numms[i]);
    }

    return 0;
}