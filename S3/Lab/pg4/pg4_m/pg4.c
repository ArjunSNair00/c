//helloooolll

#include <stdio.h>
#include <ctype.h>
#define max 100
char stack[max];
int top=-1;

void push(char op) {
    if (top == max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = op;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int priority(char op){
  if (op=='(') return 0;
  if (op=='-' || op=='+') return 1;
  if (op=='/' || op=='*') return 2;
  if (op=='^') return 3;
  return -1;
}

int main()
{
  char infix[]="1+2-3/2";
  for (char *s=infix;*s!='\0';s++)
  {
    if (isalnum(*s))
      printf("%c",*s);

    else if(priority(*s)==0)
      push(*s);

    else if (*s == ')') {
      while (top != -1 && stack[top] != '(')
        printf("%c", pop());
      pop();
    }

    else {
      while (top != -1 && priority(stack[top]) >= priority(*s)) 
        printf("%c", pop());
      push(*s);
    }
  }

  while(top!=-1)
  {
    printf("%c",pop());
  }
  return 0;
}