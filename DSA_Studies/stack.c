#include <stdio.h>
#include <stdlib.h>
#define size 5

int stack[size];
int top=-1;
int overflow=0;

int isFull() {
  return top>=size-1;
}

int isEmpty() {
  return top==-1;
}

void push(int data) {
    if (isFull()) {
      if (!overflow) {
        printf("Stack Overflow\n");
        overflow=1;
      }
      return;
    }
    stack[++top]=data;
    overflow=0;
}

int pop() {
    if (isEmpty()) {
      printf("Stack is empty\n");
      return -1;
    }
    int data = stack[top--];
    overflow = 0;
    return data;
}

void display() {
  if (!overflow) {
      printf("Stack: ");
      for (int i=0;i<=top;i++)
        printf("%d ",stack[i]);
      printf("\n");
  }
}

int main() {
  int choice,data;
  while(1){
    printf("\n1.Push\n2.Pop\n3.Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:
          printf("Enter data: ");
          scanf("%d", &data);
          push(data);
          display();
          break;

      case 2:
          data=pop();
          if(data!=-1)
            printf("Popped: %d\n",data);
          display();
          break;

      case 3:
          printf("Program exited\n");
          exit(0);

      default:
          printf("Invalid Choice\n");
    }}
  return 0;
}
