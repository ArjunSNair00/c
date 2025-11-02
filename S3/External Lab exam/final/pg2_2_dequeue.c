#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];
int size;

int is_full(){
  return ((front == 0 && rear == size - 1) || (front == rear + 1));
}

int is_empty(){
  return (front == -1);
}

void insert_front(int data){
  if (is_full(size)){
    printf("Overflow\n");
    return;
  }
  if (front == -1)
    front = rear = 0;
  else if (front == 0)
    front = size - 1;
  else
    front--;
  queue[front] = data;
}

void insert_rear(int data){
  if (is_full(size)){
    printf("Overflow\n");
    return;
  }
  if (front == -1)
    front = rear = 0;
  else if (rear == size - 1)
    rear = 0;
  else
    rear++;
  queue[rear] = data;
}

void delete_front(){
  if (is_empty()){
    printf("Underflow\n");
    return;
  }
  if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % size;
}

void delete_rear(){
  if (is_empty()){
    printf("Underflow\n");
    return;
  }
  if (front == rear)
    front = rear = -1;
  else
    rear = (rear - 1 + size) % size;
}

void display()
{
  if (is_empty()){
    printf("Empty\n");
    return;
  }
  int i = front;
  printf("Queue: ");
  while (1){
    printf("%d ", queue[i]);
    if (i == rear)
        break;
    i = (i + 1) % size;
  }
  printf("\n");
}

int main()
{
  int choice, x;
  printf("Enter queue size: ");
  scanf("%d", &size);

  printf("\nEnter choice:\n");
  printf("1 = Insert Front\n");
  printf("2 = Insert Rear\n");
  printf("3 = Delete Front\n");
  printf("4 = Delete Rear\n");
  printf("5 = Exit\n");

  do{
  printf(" > ");
  scanf("%d", &choice);
  switch (choice){
  case 1:
    printf("Enter element: ");
    scanf("%d", &x);
    insert_front(x);
    display();
    break;
  case 2:
    printf("Enter element: ");
    scanf("%d", &x);
    insert_rear(x);
    display();
    break;
  case 3:
    delete_front();
    display();
    break;
  case 4:
    delete_rear();
    display();
    break;
  case 5:
    printf("Exiting....");
    break;
  default:
    printf("Invalid choice\n");
  }}while(choice != 5);
  return 0;
}