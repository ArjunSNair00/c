#include <stdio.h>
#include <stdlib.h>

struct node
{
  int coeff, exp;
  struct node *link;
};

struct node *createtempnode(int co, int ex)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->coeff = co;
  newnode->exp = ex;
  newnode->link = NULL;
  return newnode;
}

struct node *createpoly()
{
  struct node *TP = NULL, *temp = NULL, *LTP = NULL;
  int n, coeff, exp, i;
  printf("\nEnter number of terms: ");
  scanf("%d", &n);
  printf("Enter coefficient and exponent (in decreasing order):\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d%d", &coeff, &exp);
    temp = createtempnode(coeff, exp);
    if (TP == NULL)
    {
      TP = temp;
      LTP = temp;
    }
    else
    {
      LTP->link = temp;
      LTP = temp;
    }
  }
  return TP;
}

void displaypoly(struct node *temp)
{
  if (temp == NULL)
  {
    printf("0\n");
    return;
  }
  while (temp != NULL)
  {
    printf("%dx^%d", temp->coeff, temp->exp);
    temp = temp->link;
    if (temp != NULL)
      printf(" + ");
  }
  printf("\n");
}

struct node *polyadd(struct node *P1, struct node *P2)
{
  struct node *result = NULL, *last = NULL;
  while (P1 != NULL && P2 != NULL)
  {
    struct node *temp;
    if (P1->exp > P2->exp)
    {
      temp = createtempnode(P1->coeff, P1->exp);
      P1 = P1->link;
    }
    else if (P2->exp > P1->exp)
    {
      temp = createtempnode(P2->coeff, P2->exp);
      P2 = P2->link;
    }
    else
    {
      temp = createtempnode(P1->coeff + P2->coeff, P1->exp);
      P1 = P1->link;
      P2 = P2->link;
    }
    if (result == NULL)
      result = last = temp;
    else
    {
      last->link = temp;
      last = temp;
    }
  }
  while (P1 != NULL)
  {
    struct node *temp = createtempnode(P1->coeff, P1->exp);
    if (result == NULL)
      result = last = temp;
    else
    {
      last->link = temp;
      last = temp;
    }
    P1 = P1->link;
  }
  while (P2 != NULL)
  {
    struct node *temp = createtempnode(P2->coeff, P2->exp);
    if (result == NULL)
      result = last = temp;
    else
    {
      last->link = temp;
      last = temp;
    }
    P2 = P2->link;
  }
  return result;
}

struct node *polymult(struct node *P1, struct node *P2)
{
  struct node *P = NULL;
  while (P1 != NULL)
  {
    struct node *Q = P2;
    struct node *CTEMP = NULL, *last = NULL;
    while (Q != NULL)
    {
      struct node *temp = createtempnode(P1->coeff * Q->coeff, P1->exp + Q->exp);
      if (CTEMP == NULL)
        CTEMP = last = temp;
      else
      {
        last->link = temp;
        last = temp;
      }
      Q = Q->link;
    }

    P = polyadd(P, CTEMP);
    P1 = P1->link;
  }
  return P;
}

int main()
{
  struct node *A = NULL, *B = NULL, *Sum = NULL, *Prod = NULL;
  int ch;

  printf("Enter Polynomial A\n");
  A = createpoly();
  printf("\nEnter Polynomial B\n");
  B = createpoly();

  printf("\nPolynomial A: ");
  displaypoly(A);
  printf("Polynomial B: ");
  displaypoly(B);

  do
  {
    printf("\n1. Add Polynomials (A + B)");
    printf("\n2. Multiply Polynomials (A * B)");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      Sum = polyadd(A, B);
      printf("\nA + B = ");
      displaypoly(Sum);
      break;
    case 2:
      Prod = polymult(A, B);
      printf("\nA * B = ");
      displaypoly(Prod);
      break;
    case 3:
      exit(0);
    default:
      printf("\nInvalid option!");
    }
  } while (1);

  return 0;
}