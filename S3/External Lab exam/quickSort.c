#include <stdio.h>

void print(int *arr,int n){
  for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int partition(int arr[],int low, int high){
  int pivot=arr[low]; //first element as pivot
  int i=low+1; //dont include pivot (+1)
  int j=high; 
  do{
  while(arr[i]<=pivot){ //find larger element than pivot
    i++; 
  }
  while(arr[j]>pivot){ //find smaller element than pivot
    j--;
  }
  if(i<j){ //because dont swap if i>=j
    swap(&arr[i],&arr[j]); //normal swap
  }}while(i<j);
  swap(&arr[low],&arr[j]); //
  return j; //return partitionIndex
}

void quickSort(int arr[],int low,int high){
  int partitionIndex; //pivot index in sorted position
  
  if (low < high){//atleast 1 element
    partitionIndex=partition(arr,low,high);
    quickSort(arr,low,partitionIndex-1); //left subarray
    quickSort(arr,partitionIndex+1,high); //right subarray
}}

int main(){
  int arr[]={1,7,3,19,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  printf("Unsorted Array: ");
  print(arr,n);
  quickSort(arr,0,n-1);
  printf("\nSorted Array: ");
  print(arr,n);
}