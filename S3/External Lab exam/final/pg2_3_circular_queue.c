#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1, size;

int is_full(){
  //((front == 0 && rear == size - 1) || (front == rear + 1))
  return front == (rear + 1) % size; // full, if advancing rear overlap front
}

int is_empty(){
  return front == -1;
}

void enqueue(int x) {
  if (is_full()) { 
    printf("Overflow\n");
    return;
  }
  if (is_empty())
    front = 0;
  rear = (rear + 1) % size; //advance rear
  queue[rear] = x;
}

int dequeue() {
  if (is_empty()){
    printf("Underflow\n");
    return -1;
  }
  int x = queue[front];
  if (front == rear) //If front and rear are pointing to the same element, that means this is the last element in the queue
    front = rear = -1;
  else
    front = (front + 1) % size; //advance front
  return x;
}

void display() {
  if (is_empty()){
    printf("Empty\n");
    return;
  }
  printf("Queue: ");
  for (int i = front; ; i = (i + 1) % size) { //from front to rear, advance i, to also include rear
    printf("%d ", queue[i]);
    if (i == rear) break; //to stop the circular loop
  }
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
        printf("Invalid Choice\n");
    }
  }while(choice != 3);
  return 0;
}