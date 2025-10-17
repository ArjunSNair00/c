#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

int is_full(int size)
{
  return (front == 0 && rear == size - 1) || (front == rear + 1);
}

int is_empty()
{
  return front == -1;
}

void insert_front(int data, int size)
{
  if (is_full(size))
  {
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

void insert_rear(int data, int size)
{
  if (is_full(size))
  {
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

void delete_front(int size)
{
  if (is_empty())
  {
    printf("Underflow\n");
    return;
  }
  if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % size;
}

void delete_rear(int size)
{
  if (is_empty())
  {
    printf("Underflow\n");
    return;
  }
  if (front == rear)
    front = rear = -1;
  else
    rear = (rear - 1 + size) % size;
}

void display_queue(int size)
{
  if (is_empty())
  {
    printf("Empty\n");
    return;
  }
  int i = front;
  while (1)
  {
    printf("%d ", queue[i]);
    if (i == rear)
      break;
    i = (i + 1) % size;
  }
  printf("\n");
}

int main()
{
  int size = 5;
  int choice, data;

  printf("Queue initialized (size %d)\n", size);
  printf("Commands: 1=IF, 2=IR, 3=DF, 4=DR, 5=Disp, 6=Exit\n");

  while (1)
  {
    printf(">> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      scanf("%d", &data);
      insert_front(data, size);
      break;
    case 2:
      scanf("%d", &data);
      insert_rear(data, size);
      break;
    case 3:
      delete_front(size);
      break;
    case 4:
      delete_rear(size);
      break;
    case 5:
      display_queue(size);
      break;
    case 6:
      return 0;
    default:
      printf("Invalid\n");
    }
  }
}
