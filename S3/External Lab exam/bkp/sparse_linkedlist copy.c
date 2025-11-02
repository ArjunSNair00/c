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
        printf("Empty polynomial");
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
// insertion sort
void insertTerm(node** head,int coef,int exp){
  if (coef == 0) return;  // skip zero terms

  node* newNode=createNode(coef,exp);

  //CASE 1: If the list is empty or exp is higher, the new node becomes the head
  if(*head==NULL || exp>(*head)->exp){ 
    newNode->link=*head;
    *head=newNode;
    return;
  }

  node* curr = *head;
  node* prev = NULL;

  // Traverse to find correct position or same exponent
  for (;curr != NULL && curr->exp > exp; curr = curr->link;) {
      prev = curr; //remember the previous node, so we can insert the new one between prev and curr late
  }



  node* temp=*head;
  while(temp->link!=NULL){ // Traverse to the last node
    temp=temp->link;
  }
  temp->link=newNode;
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

#include <stdlib.h>

node* combineLikeTerms(node* head) {
    if (head == NULL)
        return NULL;

    node *ptr1, *ptr2, *prev;

    ptr1 = head;
    while (ptr1 != NULL && ptr1->link != NULL) {
        prev = ptr1;
        ptr2 = ptr1->link;

        while (ptr2 != NULL) {
            if (ptr1->exp == ptr2->exp) {
                // Combine coefficients
                ptr1->coef += ptr2->coef;

                // Remove ptr2
                prev->link = ptr2->link;
                free(ptr2);
                ptr2 = prev->link;
            } else {
                prev = ptr2;
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }

    return head;
}


node* multiPoly(node* poly1,node* poly2){
  node *product=NULL;
  for(node *i=poly1;i!=NULL;i=i->link){
    for(node *j=poly2;j!=NULL;j=j->link){
      insertTerm(&product,i->coef*j->coef,i->exp+j->exp);
    }
  }
  return product;
}

int main(){
  node* poly1=NULL;
  node* poly2=NULL;
  node* sum=NULL;
  node* product=NULL;

  insertTerm(&poly1,8,16);
  insertTerm(&poly1,4,2);
  insertTerm(&poly1,1,0);
  printf("First Polynomial: \n");
  displayPoly(poly1);

  insertTerm(&poly2,10,16);
  insertTerm(&poly2,5,5);
  insertTerm(&poly2,2,2);
  insertTerm(&poly2,3,0);
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