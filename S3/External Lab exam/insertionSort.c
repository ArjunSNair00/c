#include <stdio.h>

void print(int *arr,int n){
  for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void insertionSort(int arr[],int n){
  for (int i=1;i<n;i++){
    int j=i;
    while (j>0 && arr[j-1]>arr[j]){
      swap(&arr[j],&arr[j-1]);
      j=j-1;
    }
  }
}


int main(){
  int arr[]={1,6,19,15,14,3};
  int n=sizeof(arr)/sizeof(int);
  printf("Unsorted Array: ");
  print(arr,n);
  insertionSort(arr,n);
  printf("Sorted Array: ");
  print(arr,n);
  return 0;
}