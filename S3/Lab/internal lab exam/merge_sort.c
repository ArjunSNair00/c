#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, i, j, k;//no. of elements in left sub array (from l to m and inclusive)
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j];

    i = j = 0; k = l;
    while (i < n1 && j < n2) 
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    //replace left and right to original array
    while (i < n1) 
        arr[k++] = L[i++];
    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[50], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
