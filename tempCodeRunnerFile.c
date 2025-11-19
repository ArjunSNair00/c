#include <stdio.h>
#include <math.h>
#define MAX 100

char opstack[MAX];
int valstack[MAX];
int topOp = -1;
int topVal = -1;

void pushOp(char x){
  opstack[++topOp] = x;
}

char popOp(){
  if (topOp == -1)
    return '\0';
  return opstack[topOp--];
}

int priority(char x)
{
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  if (x == '^')
    return 3;
  return -1;
}

int is_num(char c){
  return (c >= '0' && c <= '9');
}

void infixToPostfix(char infix[], char postfix[]){
  char *e = infix;
  char x;
  int k = 0;
  while (*e != '\0'){
    if (is_num(*e))
      postfix[k++] = *e;
    else if (*e == '(')
      pushOp(*e);
    else if (*e == ')')
      while (topOp != -1 && (x = popOp()) != '(')
        postfix[k++] = x;
    else{
      while (topOp != -1 && priority(opstack[topOp]) >= priority(*e))
        postfix[k++] = popOp();
      pushOp(*e);
    }
    e++;
  }

  while (topOp != -1)
    postfix[k++] = popOp();

  postfix[k] = '\0';
}

void pushVal(int x){
  valstack[++topVal] = x;
}

int popVal(){
  if (topVal == -1)
    return 0;
  return valstack[topVal--];
}

int evaluatePostfix(char postfix[])
{
  char *p = postfix;
  int a, b;
  while (*p != '\0')
  {
    if (is_num(*p)){
      pushVal(*p - '0');
    }
    else{
      b = popVal();
      a = popVal();
      switch (*p){
        case '+':
          pushVal(a + b);
          break;
        case '-':
          pushVal(a - b);
          break;
        case '*':
          pushVal(a * b);
          break;
        case '/':
          if (b != 0)
            pushVal(a / b);
          break;
        case '^':
          pushVal((int) pow(a, b));
          break;
      }
    }
    p++;
  }
  return popVal();
}

int main()
{
  char infix[MAX], postfix[MAX];
  printf("Enter infix expression: ");
  scanf("%s", infix);
  infixToPostfix(infix, postfix);
  printf("Postfix expression: %s\n", postfix);
  int result = evaluatePostfix(postfix);
  printf("Result: %d\n", result);
  return 0;
}