#include<stdio.h>

int top=-1;

int is_full(int size){
  return top==size-1;
}

int is_empty(){
  return top==-1;
}

// Corrected push function with void return type
void push(int data, int stack[], int size){
  if (is_full(size)){
    printf("Stack Overflow\n");
    return; // No return value needed
  }
  top++;
  stack[top]=data;
}

int pop(int stack[]){
  if (is_empty()){
    printf("Stack Underflow\n");
    return -1; // Return an indicator of failure
  }
  int data = stack[top];
  top--;
  return data;
}

void display(int stack[]){
  if (is_empty()) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements: ");
  for (int i = 0; i <= top; i++)
    printf("%d ", stack[i]);
  printf("\n");
}

int main()
{
  int size=3;
  int stack[size];
  int data;
  int choice;

  while(1){
    printf("\n\nSelect the operation:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter the Choice: ");
    scanf("%d",&choice);

    switch(choice){
    case 1:
      printf("Enter the data to push: ");
      scanf("%d", &data);
      push(data, stack, size); // No return value to check
      break;
    case 2:
      data = pop(stack);
      if (data != -1) { // Check for a valid pop operation
        printf("Popped element: %d\n", data);
      }
      break;
    case 3:
      display(stack);
      break;
    case 4:
      printf("Exiting program.\n");
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}