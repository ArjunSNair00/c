#include <stdio.h>
int main()
{
    int x;
    char str[30];
    printf("Enter something: ");
    scanf("%[^\n]%n",str,&x);
    printf("%d",x);
    return 0;
}