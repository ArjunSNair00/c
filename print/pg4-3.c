#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

int is_full(int size)
{
  return (rear + 1) % size == front;
}

int is_empty()
{
  return front == -1;
}

int enqueue(int data, int size)
{
  if (is_full(size))
  {
    printf("Overflow\n");
    return -1;
  }
  if (is_empty())
    front = 0;
  rear = (rear + 1) % size;
  queue[rear] = data;
  return 0;
}

int dequeue(int size)
{
  if (is_empty())
  {
    printf("Underflow\n");
    return -1;
  }
  int data = queue[front];
  if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % size;
  return data;
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
  int size, command, data;

  printf("Enter queue size: ");
  scanf("%d", &size);

  printf("Commands: 1 x=Enqueue x, 2=Dequeue, 3=Display, 4=Exit\n");

  while (1)
  {
    printf("Enter command: ");
    if (scanf("%d", &command) != 1)
      break;
    if (command == 4)
      break;

    switch (command)
    {
    case 1:
      printf("Enter value to enqueue: ");
      if (scanf("%d", &data) != 1)
        break;
      if (enqueue(data, size) == 0)
        display_queue(size);
      break;
    case 2:
      if (dequeue(size) != -1)
        display_queue(size);
      break;
    case 3:
      display_queue(size);
      break;
    default:
      printf("Invalid command\n");
    }
  }

  return 0;
}
