#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char x){
  if (top == MAX-1)
    return;
  stack[++top] = x;
}

char pop(){
  if(top == -1)
    return -1;
  else 
    return stack[top--]; 
}

int priority(char x){
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  if (x == '^')
    return 3;
}

int main(){
  char exp[]="2*3+4*(5-6)";
  char *e, x;
  e = exp;
  while(*e != '\0'){
    if (isalnum(*e))
      printf("%c",*e);
    else if (*e == '(')
      push(*e);
    else if (*e == ')')
    {
      while ((x=pop()) != '(')
        printf("%c",x);
    }
    else{
      while(top != -1 && priority(stack[top]) >= priority(*e))
        printf("%c",pop());
      push(*e);
    }
    e++;
  }
  while (top != -1)
    printf("%c",pop());
  return 0;
}