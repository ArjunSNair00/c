#include<stdio.h>
int main()
{
  int n;
  printf("Enter array size: ");
  scanf("%d",&n);
  int arr[n];
  int freq[n];
  int count;
  printf("Enter %d elements (repeat some elements): \n",n);
  for (int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
    freq[i]=-1;
  }
    
  for (int i=0;i<n;i++)
  {
    if (freq[i]==0)
      continue;
    count=1;
    for (int j=i+1;j<n;j++)
    {
      if (arr[i]==arr[j])
      {
        count++;
        freq[j]=0;
      }
    }
    freq[i]=count;
  }

  for (int i=0;i<n;i++)
  {
    printf("%d ",freq[i]);
    // if (freq[i]>0)
    //   printf("%d occurs %d times\n",arr[i],freq[i]);
  }
  return 0;
}