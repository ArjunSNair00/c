#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){ 
  stack[++top] = c; 
}

char pop(){ 
  return (top == -1) ? '\0' : stack[top--]; 
}
  
int priority(char c){
  if(c=='+'||c=='-') return 1;
  if(c=='*'||c=='/') return 2;
  if(c=='^') return 3;
  return 0;
}

int main() {
  char infix[MAX], postfix[MAX];
  int k = 0;
  printf("Enter infix expression: ");
  scanf("%s", infix);

  for(int i=0; infix[i]!='\0'; i++){
    char c = infix[i];
    if(c>='0' && c<='9')
      postfix[k++] = c;
    else if(c=='(')
      push(c);
    else if(c==')'){
      while(top!=-1 && stack[top]!='(')
        postfix[k++] = pop();
      pop();
    }
    else{
      while(top!=-1 && priority(stack[top]) >= priority(c))
        postfix[k++] = pop();
      push(c);
    }
  }

  while(top!=-1)
    postfix[k++] = pop();

  postfix[k] = '\0';
  printf("Postfix expression: %s\n", postfix);
  return 0;
}
