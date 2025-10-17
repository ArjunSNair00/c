// Linear Queue

#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

int is_full(int size)
{
  return rear == size - 1;
}

int is_empty()
{
  return front == -1 || front > rear;
}

int enqueue(int data, int size)
{
  if (is_full(size))
  {
    printf("Overflow\n");
    return -1;
  }
  if (is_empty())
  {
    front = 0;
  }
  queue[++rear] = data;
  return 0;
}

int dequeue()
{
  if (is_empty())
  {
    printf("Underflow\n");
    return -1;
  }
  int data = queue[front];
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front++;
  }
  return data;
}

void display()
{
  if (is_empty())
  {
    printf("Empty\n");
    return;
  }
  printf("Queue: ");
  for (int i = front; i <= rear; i++)
  {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main()
{
  int size, choice, data;
  printf("Enter queue size: ");
  scanf("%d", &size);

  while (1)
  {
    printf("\n1. Enqueue 2. Dequeue 3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      printf("Enter data: ");
      scanf("%d", &data);
      enqueue(data, size);
      display();
    }
    else if (choice == 2)
    {
      dequeue();
      display();
    }
    else if (choice == 3)
    {
      break;
    }
    else
    {
      printf("Invalid choice\n");
    }
  }
  return 0;
}