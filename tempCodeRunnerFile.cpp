#include <stdio.h>

#define max 100

char stack[max];
int top=-1;

int push(int data,int size){
  if (top==size-1){
    return -1;
  }
  top++;
  stack[top]=data;
  return 1;
}

char pop(){
  if (top!=-1)
  {
    char data;
    data=stack[top];
    top--;
    return data;
  }
}

void display(int size){
  for(int i=0;i<size;i++)
    printf("%c ",stack[i]);
}


int precedence(int op)
{
  int p;
  if (op=='^')
    p=3;
  else if (op == '/' || op == '*')
    p=2;
  else if (op == '+' || op == '-')
    p=1;
  return p;
}

int main()
{
  int pr=0;
  int data;
  int size=100;
  char symbol='/';

  if (precedence(symbol)>pr)
  {
    push(symbol,size);
    pr=precedence(symbol);
  }
  display(size);

  symbol='/';
  if (precedence(symbol)>pr)
  {
    push(symbol,size);
    pr=precedence(symbol);
  }
  else if (precedence(symbol)<=pr)
  {
    data=pop();
    push(symbol,size);
  }
  display(size);
  return 0;
}