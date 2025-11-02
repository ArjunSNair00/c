#include <stdio.h>
#include <ctype.h>
#define MAX 100
char valStack[MAX],TOP=-1;

int isEmpty(){
  return TOP==-1;
}

int isFull(){
  return TOP==MAX-1;
}

void pushVal(char data){
  if(isFull()){
    printf("\nStack Overflow");
    return;
  }valStack[++TOP]=data;
}

void pushVal(char data){
  if(isFull()){
    printf("\nvalvalStack Overflow");
    return;
  }valvalStack[++TOP]=data;
}

int pop(){
  if(isEmpty()){
    printf("\nStack Underflow");
    return 0;
  }int data=valStack[TOP--];
  return data;
}

void display(){
  if(isEmpty()){
    printf("\nEmpty Stack");
    return;
  }printf("\nvalStack:\n");
  for(int i=0;i<=TOP;i++)  printf("%c",valStack[i]);
}

int main(){
  char infix[]="1+2-3*(4+8/4)";
  for(int i=0;infix[i]!='\0';i++){
    if(isalnum(infix[i]))
      pushVal(infix[i]);
  }
  display();
  return 0;
}