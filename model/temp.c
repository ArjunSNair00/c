#include <stdio.h>
#include <mytools.h>
void append(int p,int e,int n,int arr[])
{
    int temp=arr[p];
    int t;
    for (int i=n;i>=p;i--)
        arr[i+1]=arr[i];
    arr[p]=e;
}
int main()
{
    int ar[]={2,3,4,23,25};
    printf("Before inserting: \n");
    int n=sizeof(ar)/sizeof(ar[0]);
    printarray(n,ar);
    printf("\n");
    //append element 
    append(2,12,n,ar);
    printf("After inserting: \n");
    printarray(n+1,ar);
    return 0;
}