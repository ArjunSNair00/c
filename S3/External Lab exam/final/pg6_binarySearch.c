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
  int key;
  int arr[]={1,5,7,10,16,26,47,1654,15453,62735};
  int n=sizeof(arr)/sizeof(int);
  printf("\nArray: ");
  for(int i=0;i<n;i++)  printf("%d ",arr[i]);
  printf("\nEnter key to search: ");
  scanf("%d",&key);
  
  printf("Element was %sfound in Array",binarySearch(arr,n,key)?"":"not ");
  return 0;
}