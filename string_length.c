#include <stdio.h>
int len(char a[])
{
    int length=0;
    for(int i=0;a[i]!='\0';i++)
        length++;
    return length;
}
int main()
{
    char a[]="abcded";
    printf("%d",len(a));
    return 0;
}