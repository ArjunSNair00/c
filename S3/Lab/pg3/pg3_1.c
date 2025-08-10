#include <stdio.h>
int front=-1,rear=-1;

int is_full(int size){
  return rear==size-1;
}

int is_empty(){
  return front == -1 || front > rear;
}

int enqueue(int data,int queue[],int size){
  if (is_full(size)){
    printf("\nQueue Overflow\n");
    return -1;
  }
  else if(is_empty()){
    front=0;
  }
  rear++;
  queue[rear]=data;
  return 0;
}

int dequeue(int queue[]){
  if(is_empty()){
    printf("\n\nQueue Underflow\n");
    return -1;
  }
  int data=queue[front];
  front++;
  return data;
}

void display(int queue[]){
  if (is_empty()) {
    printf("\n\nQueue is empty");
    return;
  }
  for (int i = front; i <= rear; i++)
    printf("%d ", queue[i]);
  printf("\n");
}

int main()
{
  int size,choice,data;
  printf("Enter the size of queue: ");
  scanf("%d",&size);
  int queue[size];
  while(1){
  printf("\n\nSelect the operation:\n1. Insertion\n2. Deletion\n3. Exit\nEnter the Choice: ");
  scanf("%d",&choice);
  switch (choice)
  {
  case 1:
    printf("Enter the data to enqueue element: ");
    scanf("%d", &data);
    if (enqueue(data, queue, size) == 0) {
      printf("\nQueue after enqueue: \n");
      display(queue);
    }
    break;

  case 2:
    dequeue(queue);
    printf("\nQueue after dequeue: \n");
    display(queue);
    break;
    
  case 3:
    return 0;

  default:
    printf("\nInvalid choice\n");
  }}
  return 0;
}