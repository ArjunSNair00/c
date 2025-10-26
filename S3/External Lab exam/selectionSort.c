#include<stdio.h>

void print(int *arr,int n){
  for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");
}

int selectionSort(int arr[],int n){
  int indexOfMin;
  int temp;
  for (int i=0;i<n-1;i++)//loop till 2nd last
  {
    indexOfMin=i;
    for (int j=i+1;j<n;j++){ //because we need to compare even the last element
      if(arr[j]<arr[indexOfMin])
        indexOfMin=j;
    }
    temp=arr[i];
    arr[i]=arr[indexOfMin];
    arr[indexOfMin]=temp;
  }
}

int main(){
  int arr[]={1,6,19,15,14,3};
  int n=sizeof(arr)/sizeof(int);
  printf("Unsorted Array: ");
  print(arr,n);
  selectionSort(arr,n);
  printf("Sorted Array: ");
  print(arr,n);
  return 0;
}