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

void displayPoly(node* head){
  if(head==NULL){
    printf("Empty polynomial");
    return;
  }
  node* temp=head;
  int first=1;
  while(temp!=NULL){
    if(temp->coef!=0){
      if(!first && temp->coef > 0)
        printf(" +");
      printf(" %d",temp->coef);
      if(temp->exp!=0){
        if(temp->exp==1)  printf("x");
        else printf("x^%d",temp->exp);
      }
      first=0;
    }
    temp=temp->link;
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
void createLinkedList(node** head,int coef,int exp){
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
  node* i,j,k;
  return sum;
}

int main(){
  node* poly1=NULL;
  node* poly2=NULL;
  node* sum=NULL;

  createLinkedList(&poly1,8,16);
  createLinkedList(&poly1,4,2);
  createLinkedList(&poly1,1,0);
  displayPoly(poly1);
  freeLinkedlist(&poly1);

  createLinkedList(&poly2,10,16);
  createLinkedList(&poly2,5,5);
  createLinkedList(&poly2,2,2);
  createLinkedList(&poly2,3,0);
  displayPoly(poly2);
  freeLinkedlist(&poly2);

  sum=addPoly(poly1,poly2);
  return 0;
}