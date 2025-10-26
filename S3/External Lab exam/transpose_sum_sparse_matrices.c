#include <stdio.h>
int main(){
  int r=2,c=2,e1=0,e2=0;
  int m1[r][c],m2[r][c];
  printf("Enter elements of 1st matrix: ");
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++){
      scanf("%d",&m1[i][j]);
      if(m1[i][j]!=0)
        e1++;
    }

  printf("Enter elements of 2nd matrix: ");
  for (int i=0;i<r;i++)
    for (int j=0;j<c;j++){
      scanf("%d",&m2[i][j]);
      if(m1[i][j]!=0)
        e2++;
    }
  int sp1[e1][3],sp2[e2][3];
  int row=0;
}