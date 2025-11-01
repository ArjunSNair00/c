#include <stdio.h>

void print(int *arr,int n){
  for (int i=0;i<n;i++) printf("%d ",arr[i]);
  printf("\n");
}

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void selectionSort(int arr[],int n){
  int min;
  for (int i=0;i<n-1;i++)
  {
    min=i;
    for (int j=i+1;j<n;j++){
      if(arr[j]<arr[min])
        min=j;
    }
    if(min!=i)  swap(&arr[i],&arr[min]);
  }
}

void binarySearch(int arr[],int size,int key,int *index,int *found){
  int left=0;
  int right=size-1;
  int mid;
  while(left<=right){
    mid=(left+right)/2;
    if(arr[mid]==key){
      *index=mid;
      *found=1;
      return;
    }else if(arr[mid]<key){
      left=mid+1;
    }else right=mid-1;
  }
}

int main(){
  int arr[]={1,6,19,15,400,5,1000,140};
  int key=8;
  int index=-1,found=0;
  int n=sizeof(arr)/sizeof(int);
  selectionSort(arr,n);
  printf("Array: ");
  print(arr,n);
  binarySearch(arr,n,key,&index,&found);
  printf("The element was %sfound in the array",found?"":"not ");
  found?printf(" at index %d",index):0;
  return 0;
}