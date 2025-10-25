#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) 
                min = j;
        if (min != i) { 
            int t = arr[i]; 
            arr[i] = arr[min]; 
            arr[min] = t; 
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    selectionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    return 0;
}
