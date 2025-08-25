#include <stdio.h>
int main()
{
  int a[]={1,2,3,5};
  //read a poly1 (for i from 0 to size1)
  int b[]={5,0,6};
  //read a poly2 (for i from 0 to size2)
  int size1=sizeof(a)/sizeof(a[0]);
  int size2=sizeof(b)/sizeof(b[0]);
  int l=size1 > size2 ? size1 : size2;
  printf("%d ",l);
  int result[l];
  for (int i=0; i<l; i++) {
    result[i] = 0;
  }
  for (int i=0;i<l;i++){
    result[i]+=a[i];
    printf("%d ",result[i]);
  }
  return 0;
}