#include <stdio.h>

int binarySearch(int arr[],int n,int key){
  int low=0;
  int high=n-1;
  int mid;
  while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==key)
      return 1;
    else if (key<arr[mid]){
      high=mid-1;
    }
    else
      low=mid+1;
  }
  return 0;
}

int main(){
  int arr[]={1,5,7,10,16,26,47,1654,15453,62735};
  int e=11;
  int n=sizeof(arr)/sizeof(int);
  printf("Element was %sfound in Array",binarySearch(arr,n,e)?"":"not ");
  return 0;
}