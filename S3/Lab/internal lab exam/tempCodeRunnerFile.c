#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int num[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int key;
    printf("Enter the key to search in the array: ");
    scanf("%d", &key);

    int flag = 0;
    int l = 0, u = n - 1;

    while (l <= u) {
        int mid = floor((l + u) / 2);
        if (num[mid] == key) {
            printf("Key is found in the array\n");
            flag = 1;
            break;
        } else if (num[mid] < key) {
            l = mid + 1;
        } else { // num[mid] > key
            u = mid - 1;
        }
    }

    if (!flag) {
        printf("Key is not found in the array\n");
    }

    return 0;
}