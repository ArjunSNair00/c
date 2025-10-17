#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *p1,*p2;
  int a=20;
  p1=&a;
  p2=p1;
  printf("%d %d",*p1,*p2);
  // printf("%x",p1);
}