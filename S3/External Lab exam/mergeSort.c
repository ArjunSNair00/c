#include <stdio.h>

void print(int *arr,int n){
  for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void merge(int arr[],int low,int mid,int high){
  int i=low,j=mid+1,k=0,B[high-low+1];
  while(i<=mid && j<=high){
    B[k++]=(arr[i]<=arr[j])?arr[i++]:arr[j++];
  }
  while(i<=mid)
    B[k++]=arr[i++];
  while(j<=high)
    B[k++]=arr[j++];
  for(int i=low;i<=high;i++)
    arr[i]=B[i-low];
}

void mergeSort(int arr[],int low,int high){
  if(low<high){
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}

int main(){
  int arr[]={1,7,3,19,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("Unsorted Array: ");
  print(arr,n);
  mergeSort(arr,0,n-1);
  printf("\nSorted Array: ");
  print(arr,n);
}