#include <stdio.h>
int main(){
  typedef int array[10];
  array a1={1,2,3,4,5,6,7,8,9,10};
  for(int i=0;i<10;i++) printf("%d ",a1[i]);
  return 0;
}