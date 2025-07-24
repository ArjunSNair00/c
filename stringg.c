#include <stdio.h>
#include <string.h>
void main()
{
    char name[30];
    char address[30];
    printf("Enter your name: ");
    gets(name);
    printf("Enter your address: ");
    gets(address);
    printf("Your name is: %s\n",name);
    printf("Your address is: %s\n",address);
}