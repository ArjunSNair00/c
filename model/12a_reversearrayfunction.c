#include <stdio.h>

void reverse(int nums[], int start, int end) { //function to reverse portion of array
    for(;start<end;start++,end--) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(nums) / sizeof(nums[0]);
    int step = 3;
    step = step % length; // Normalize step in case it's > length

    reverse(nums, 0, length - 1);           // Reverse whole array
    reverse(nums, 0, length - step - 1);    // Reverse first part
    reverse(nums, length - step, length - 1); // Reverse second part

    // Print rotated array
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
