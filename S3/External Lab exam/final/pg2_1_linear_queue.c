#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1, size;

void enqueue(int x) {
  if (rear == size - 1) { 
    printf("Overflow\n"); 
    return; 
  }
  if (front == -1) 
    front = 0;
  queue[++rear] = x;
}

int dequeue() {
  if (front == -1 || front > rear) { //never had values or if all elements have been dequeued, making front move past rear 
    printf("Underflow\n"); 
    return -1; }
  int x = queue[front++];
  if (front > rear) 
    front = rear = -1;
  return x;
}

void display() {
  if (front == -1) { 
    printf("Empty\n"); 
    return; 
  }
  printf("Queue: ");
  for (int i = front; i <= rear; i++) 
    printf("%d ", queue[i]);
  printf("\n");
}

int main() {
  int choice, x;
  printf("Enter queue size: ");
  scanf("%d", &size);
  printf("\nEnter choice: 1=Enqueue, 2=Dequeue, 3=Exit: \n");
  do{   
    printf(" > ");
    scanf("%d", &choice);
    switch(choice){
    case 1: 
      printf("Enter element: ");
      scanf("%d", &x); 
      enqueue(x); 
      display(); 
      break;
    case 2: 
      dequeue(); 
      display();
      break;
    case 3: 
      printf("Exiting.....");
      break;
    default:
      printf("Invalid Choice");
    }}while(choice != 3);
  return 0;
}