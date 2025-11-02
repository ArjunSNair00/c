#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1, size;

void enqueue(int x) {
    if ((rear + 1) % size == front) { // full
      printf("Overflow\n");
      return;
    }
    if (front == -1) 
      front = 0;
    rear = (rear + 1) % size;
    queue[rear] = x;
}

int dequeue() {
    if (front == -1){ // empty
      printf("Underflow\n");
      return -1;
    }
    int x = queue[front];
    if (front == rear) 
      front = rear = -1;
    else 
      front = (front + 1) % size;
    return x;
}

void display() {
  if (front == -1){ 
    printf("Empty\n"); 
    return; 
  }
  for (int i = front; ; i = (i + 1) % size) {
    printf("%d ", queue[i]);
    if (i == rear) break;
  }
  printf("\n");
}

int main() {
  int cmd, x;
  printf("Enter queue size: ");
  scanf("%d", &size);
  printf("Commands: 1 x=Enqueue, 2=Dequeue, 3=Display, 4=Exit\n");
  do{
    scanf("%d", &cmd);
    if (cmd == 1) { 
      scanf("%d", &x); 
      enqueue(x); 
      display(); }
    else if (cmd == 2) { 
      dequeue(); 
      display(); }
    else if (cmd == 3) 
      display();
  }while(cmd != 4);
  return 0;
}
