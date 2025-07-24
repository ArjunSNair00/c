#include <stdio.h>
int main()
{
  int a[] = {1,3,7,0,2,142,4,9,5,8,6,35,42};
  int n = 13,swapped,i=0;

  do 
  {
    swapped = 0;
    for (int j = 0; j < n-1-i; j++)
    {
      if (a[j] > a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = 1;
      } 
    }
    i++;
  } while (swapped);

  for (int i = 0; i < n; i++)
    printf("%d ",a[i]);

  return 0;
}