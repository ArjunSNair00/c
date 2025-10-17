#include <stdio.h>



struct person
{
  char name[30];
  int age;
  int height;
}p1,p2;

int main()
{
  struct person;
  p1.age=19;
  p2.age=19;
  char n[]="Arjun S Nair";
  char n2[]="Malavika R";
  for (int i=0;n[i]!='\0';i++)
    p1.name[i]=n[i];
  for (int i=0;n2[i]!='\0';i++)
    p2.name[i]=n2[i];
  p1.height=173;
  p2.height=172;
  printf("Person 1\n");
  printf("%d\n",p1.age);
  printf("%s\n",p1.name);
  printf("%d",p1.height);
  printf("\n\nPerson 2\n");
  printf("%d\n",p2.age);
  printf("%s\n",p2.name);
  printf("%d",p2.height);
  return 0;
}
//conditional statement,looping, functions, structure, 