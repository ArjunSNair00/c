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

Block *allocate(Block *head,int reqSize){
  Block *temp=head;
  while(temp!=NULL){
    if(temp->isFree && temp->size>=reqSize){
      temp->isFree=0;
      printf("Allocated %d units\n",reqSize);
      return temp;
    }
    temp=temp->next;
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
  }printf("NULL\n");
}

void freeBlock(Block *block){
  if(block != NULL && !block->isFree){
    block->isFree=1;
    printf("Block of size %d is now freed\n",block->size);
  }else{
    printf("Block is already free or invalid\n");
  }
}

int main(){
  Block *head=createBlock(50);
  Block *second=createBlock(10);
  Block *third=createBlock(20);
  Block *fourth=createBlock(70);
  head->next=second;
  second->prev=head;
  second->next=third;
  third->prev=second;
  third->next=fourth;
  fourth->prev=third;

  displayMemory(head);

  Block *p1 = allocate(head,20);
  Block *p2 = allocate(head,15);

  displayMemory(head); 


  return 0;
 }