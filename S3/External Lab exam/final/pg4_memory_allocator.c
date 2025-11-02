#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
  int size;
  int isFree; // 1=free, 0=allocated
  struct Block *prev;
  struct Block *next;
} Block;

Block *createBlock(int size) {
  Block *newBlock = (Block *)malloc(sizeof(Block));
  if (newBlock == NULL) {
    printf("Memory Allocation Failed\n");
    exit(1);
  }
  newBlock->size = size;
  newBlock->isFree = 1;
  newBlock->prev = NULL;
  newBlock->next = NULL;
  return newBlock;
}

void displayMemory(Block *head) {
  printf("\nMemory layout:\n");
  Block *temp = head;
  while (temp != NULL) {
    printf("[SIZE: %d | %s] <-> ",
      temp->size, temp->isFree ? "Free" : "Allocated");
    temp = temp->next;
  }
  printf("NULL\n");
}

Block *allocate(Block *head, int reqSize) {
  Block *temp = head;
  while (temp != NULL) {
    if (temp->isFree && temp->size >= reqSize) {
      temp->isFree = 0;  //false (allocated)
      printf("Allocated %d units\n", reqSize);
      return temp;
    }
    temp = temp->next;
  }
  printf("Allocation failed: No suitable free block\n");
  return NULL;
}

void freeBlock(Block *block) {
    if (block != NULL && block->isFree == 0) {
      block->isFree = 1;  //true (freed)
      printf("Block of size %d is now freed\n", block->size);
    }else
      printf("Block is already free or invalid\n");
}

int main() {
  Block *head = createBlock(50);
  Block *second = createBlock(30);
  Block *third = createBlock(20);
  Block *fourth = createBlock(70);

  head->next = second;
  second->prev = head;
  second->next = third;
  third->prev = second;
  third->next = fourth;
  fourth->prev = third;

  displayMemory(head);

  Block *p1 = allocate(head, 20);
  Block *p2 = allocate(head, 15);
  displayMemory(head);
  freeBlock(p1);
  displayMemory(head);

  Block *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
  printf("\nAll memory blocks freed\n");
  return 0;
}
