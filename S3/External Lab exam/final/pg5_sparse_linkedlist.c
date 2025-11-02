#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int coef;
  int exp;
  struct node* link;
}node;

node* createNode(int coef,int exp){
  node* newNode=(node*)malloc(sizeof(node));
  if (newNode == NULL){
    printf("Memory allocation failed\n");
    return NULL;
  }
  newNode->exp=exp;
  newNode->coef=coef;
  newNode->link=NULL;
  return newNode;
}

void displayPoly(node* head) {
    if (head == NULL) {
        printf("Empty polynomial\n");
        return;
    }

    int first = 1;
    while (head != NULL) {
        if (head->coef != 0) {
            if (!first && head->coef > 0)
                printf(" +");
            printf(" %d", head->coef);
            if (head->exp != 0) {
                if (head->exp == 1)
                    printf("x");
                else
                    printf("x^%d", head->exp);
            }
            first = 0;
        }
        head = head->link;   // same as temp = temp->link;
    }
    printf("\n");
}

void freeLinkedlist(node** head){ //free linkedlist
  node* temp;
  while(*head!=NULL){
    temp=*head; //store current node
    *head=(*head)->link; //move to next node
    free(temp); //free the current node
  }*head=NULL;
}

// Function to add a node to the end of the linked list
void insertTerm(node** head,int coef,int exp){
  node* newNode=createNode(coef,exp);
  if(*head==NULL){ // If the list is empty, the new node becomes the head
    *head=newNode;
  }else{
    node* temp=*head;
    while(temp->link!=NULL){ // Traverse to the last node
      temp=temp->link;
    }
    temp->link=newNode;
  }
}

node* addPoly(node* poly1,node* poly2){
  node* sum=NULL;
  node *i=poly1,*j=poly2;
  while(i!=NULL && j!=NULL){
  if(i->exp == j->exp){
      insertTerm(&sum,i->coef+j->coef,i->exp);
      i=i->link;
      j=j->link;
  }else if(i->exp > j->exp){
      insertTerm(&sum,i->coef,i->exp);
      i=i->link;
  }else{
      insertTerm(&sum,j->coef,j->exp);
      j=j->link;
  }}
  while(i!=NULL){
      insertTerm(&sum,i->coef,i->exp);
      i=i->link;
  }
  while(j!=NULL){
      insertTerm(&sum,j->coef,j->exp);
      j=j->link;
  } 
  return sum;
}

node* multiPoly(node* poly1, node* poly2) {
  node *product = NULL;
  for (node *i = poly1; i != NULL; i = i->link) {
      node *tempProduct = NULL;
      // Multiply each term of poly2 with current term of poly1
      for (node *j = poly2; j != NULL; j = j->link) {
          insertTerm(&tempProduct, i->coef * j->coef, i->exp + j->exp);
      }
      product = addPoly(product, tempProduct);
  }
  return product;
}

void readPoly(node** poly){
  int exp,coef,n;
  printf("\nEnter no. of non-zero terms in polynomial: ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("Enter the coefficient and exponent: ");
    scanf("%d %d",&coef,&exp);
    insertTerm(poly,coef,exp);
  }
}

int main(){
  node *poly1=NULL, *poly2=NULL, *sum=NULL, *product=NULL;

  readPoly(&poly1);
  printf("\nFirst Polynomial: \n");
  displayPoly(poly1);

  readPoly(&poly2);
  printf("\nSecond Polynomial: \n");
  displayPoly(poly2);

  sum=addPoly(poly1,poly2);
  printf("\nSum Polynomial: \n");
  displayPoly(sum);
  freeLinkedlist(&sum);

  product=multiPoly(poly1,poly2);
  printf("\nProduct Polynomial: \n");
  displayPoly(product);
  freeLinkedlist(&product);
  
  freeLinkedlist(&poly1);
  freeLinkedlist(&poly2);
  return 0;
}