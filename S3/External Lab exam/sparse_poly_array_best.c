#include <stdio.h>
#define MAXX 100

void addPoly(int *poly1,int *poly2,int n){
  for(int i=0;i<=n;i++)
    poly1[i]+=poly2[i];
}

void readPoly(int *poly,int n){
  int exp,coef;
  for(int i=0;i<n;i++){
    scanf("%d %d",&coef,&exp);
    poly[exp]=coef;
  }
}

void printPoly(int *poly,int max){
  int first = 1;
  for(int i = max; i >= 0; i--){
    if(poly[i] != 0) {
      if(!first && poly[i] > 0) 
        printf("+ ");
      printf("%d", poly[i]);
      if(i != 0) {
        printf("x");
        if(i != 1) 
          printf("^%d", i);
        printf(" ");
      }
      first = 0;
  }}
  printf("\n");
}

int main(){
  int n1,n2,d1,d2;
  printf("Enter the degree & number of non-zero terms of first polynomial: ");
  scanf("%d %d",&d1,&n1);
  printf("Enter the degree & number of non-zero terms of second polynomial: ");
  scanf("%d %d",&d2,&n2);

  int poly1[MAXX+1]={0},poly2[MAXX+1]={0};
  
  printf("Enter the coefficient and exponent of first polynomial (maximum degree %d): \n",d1);
  readPoly(poly1,n1);
  printf("First polynomial: ");
  printPoly(poly1,d1);

  printf("\nEnter the coefficient and exponent of second polynomial (maximum degree %d): \n",d2);
  readPoly(poly2,n2);
  printf("Second polynomial: ");
  printPoly(poly2,d2);

  if(d1 >= d2) {
    addPoly(poly1, poly2, d2);
    printf("\nSum polynomial: ");
    printPoly(poly1, d1);
  } else {
    addPoly(poly2, poly1, d1);
    printf("\nSum polynomial: ");
    printPoly(poly2, d2);
  }

  return 0;
}