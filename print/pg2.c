#include <stdio.h>

int main()
{
  int r, c, e1 = 0, e2 = 0;
  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &r, &c);

  int m1[r][c], m2[r][c];

  printf("Enter the elements of matrix 1: \n");
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%d", &m1[i][j]);
      if (m1[i][j] != 0)
        e1++;
    }
  }

  printf("Enter the elements of matrix 2: \n");
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%d", &m2[i][j]);
      if (m2[i][j] != 0)
        e2++;
    }
  }

  int sp1[e1][3], sp2[e2][3];
  int row = 0;

  printf("The tuple representation of first sparse matrix is:\n");
  printf("r c v\n");
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (m1[i][j] != 0)
      {
        sp1[row][0] = i;
        sp1[row][1] = j;
        sp1[row][2] = m1[i][j];
        printf("%d %d %d\n", i, j, m1[i][j]);
        row++;
      }
    }
  }

  printf("The tuple representation of second sparse matrix is:\n");
  printf("r c v\n");
  row = 0;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (m2[i][j] != 0)
      {
        sp2[row][0] = i;
        sp2[row][1] = j;
        sp2[row][2] = m2[i][j];
        printf("%d %d %d\n", i, j, m2[i][j]);
        row++;
      }
    }
  }

  int sum[e1 + e2][3];
  int i = 0, j = 0, k = 0;

  while (i < e1 && j < e2)
  {
    if (sp1[i][0] == sp2[j][0] && sp1[i][1] == sp2[j][1])
    {
      int s = sp1[i][2] + sp2[j][2];
      if (s != 0)
      {
        sum[k][0] = sp1[i][0];
        sum[k][1] = sp1[i][1];
        sum[k][2] = s;
        k++;
      }
      i++;
      j++;
    }
    else if (sp1[i][0] < sp2[j][0] || (sp1[i][0] == sp2[j][0] && sp1[i][1] < sp2[j][1]))
    {
      sum[k][0] = sp1[i][0];
      sum[k][1] = sp1[i][1];
      sum[k][2] = sp1[i][2];
      k++;
      i++;
    }
    else
    {
      sum[k][0] = sp2[j][0];
      sum[k][1] = sp2[j][1];
      sum[k][2] = sp2[j][2];
      k++;
      j++;
    }
  }

  while (i < e1)
  {
    sum[k][0] = sp1[i][0];
    sum[k][1] = sp1[i][1];
    sum[k][2] = sp1[i][2];
    k++;
    i++;
  }

  while (j < e2)
  {
    sum[k][0] = sp2[j][0];
    sum[k][1] = sp2[j][1];
    sum[k][2] = sp2[j][2];
    k++;
    j++;
  }

  printf("The tuple representation of sum matrix is:\n");
  printf("r c v\n");
  for (int p = 0; p < k; p++)
  {
    printf("%d %d %d\n", sum[p][0], sum[p][1], sum[p][2]);
  }

  printf("The transpose of tuple representation of sum matrix is:\n");
  printf("r c v\n");
  for (int p = 0; p < k; p++)
  {
    printf("%d %d %d\n", sum[p][1], sum[p][0], sum[p][2]);
  }

  return 0;
}
