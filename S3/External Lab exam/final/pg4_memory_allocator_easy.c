#include <stdio.h>
#include <stdlib.h>

typedef struct Block{
  int size;
  int isFree;
  struct Block *prev;
  struct Block *next;
}Block;

Block *createBlock(int size){
  Block *newBlock=(Block*)malloc(sizeof(Block));
  if(newBlock == NULL){
    printf("Memory allocation failed\n");
    return NULL;
  }
  newBlock->size=size;
  newBlock->isFree=1;
  newBlock->prev=newBlock->next=NULL;
  return newBlock;
}

Block *allocate(Block *head, int reqSize) {
  Block *temp = head;

  //First Fit
  while (temp != NULL) {
    if (temp->isFree && temp->size >= reqSize) {
      temp->isFree = 0;
      printf("Allocated %d units from block of size %d\n",reqSize, temp->size);
      return temp;
    }
    temp = temp->next;
  }
  printf("Allocation failed: No suitable free block\n");
  return NULL;
}

void displayMemory(Block* head){
  printf("\nMemory Layout\n");
  Block *temp=head;
  while(temp!=NULL){
    printf("[SIZE: %d | %s] <-> ",temp->size,temp->isFree?"Free":"Allocated");
    temp=temp->next;
  }printf("NULL\n\n");
}

void freeBlock(Block *block){
  if(block != NULL && !block->isFree){
    block->isFree=1;
    printf("Block of size %d is now freed\n",block->size);
  }else{
    printf("Block is already free or invalid\n");
  }
}

void addBlock(Block **head,int size){
  Block *newBlock=createBlock(size);
  if(*head == NULL){
    *head=newBlock;
  }else{
  Block *temp=*head;
  while(temp->next!=NULL){ //important to let it be temp->link(second last element)and not temp 
    temp=temp->next;
  }
  temp->next=newBlock;
  newBlock->prev=temp;
}}

int main(){
  Block *head=NULL;
  addBlock(&head,50);
  addBlock(&head,30);
  addBlock(&head,15);

  displayMemory(head);

  Block *p1 = allocate(head,20);
  Block *p2 = allocate(head,15);

  displayMemory(head); 

  //simulate freeing of memory
  freeBlock(p1);
  displayMemory(head);

  //actually free all dynamically allocated blocks from heap
  Block *temp;
  while (head!=NULL){
    temp=head; //store current node to temp
    head=head->next; //travel to next node
    free(temp); //free current node
  }

  printf("All memory blocks free\n");
  return 0;
 }