#include <stdio.h>

void print(int *arr,int n){
  for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

int main(){
  int arr[]={1,7,3,19,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("Unsorted Array: ");
  print(arr,n);
}