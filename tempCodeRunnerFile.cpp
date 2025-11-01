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

int main(){
  int arr[]={1,6,19,15,400,5,1000,140};
  int key=6;
  int n=sizeof(arr)/sizeof(int);
  selectionSort(arr,n);
  print(arr,n);
  return 0;
}