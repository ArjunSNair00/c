#include<stdio.h>
int main()
{
    char name[30];
    printf("Enter name: ");
    fgets(name,30,stdin);
    printf("Your name: %s",name);
    return 0;
}