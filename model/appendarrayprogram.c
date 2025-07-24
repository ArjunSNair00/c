#include <stdio.h>
#include <mytools.h>
void appendarray(int p,int e[],int n,int n2,int arr[])
{
    int temp=arr[p];
    int t;
    for (int i=n;i>=p;i--)
        arr[i+n2]=arr[i];
    for (int i=p,j=0;j<n2;i++,j++) 
        arr[i]=e[j];
}
int main()
{
    //original array
    int ar[30]={2,3,4,23,25};
    int n1=5;
    printf("Before inserting: \n");
    printarray(n1,ar);
    printf("\n");

    //array to append
    int e[]={14,15,16};
    int n2=len(e);
    printf("Array to append: \n");
    printarray(n2,e);
    printf("\n");

    //appendarray(position,arraysource,lengthofdestinationarray,lengthofsourcearray,destinationarray)
    int p= 0;
    //appendarray(p,(int[]){14,15,16},n1,n1+3,ar);
    appendarray(p,e,n1,n2,ar);
    printf("After inserting array at index(%d): \n", p);
    printarray(n1+n2,ar);
    return 0;
}