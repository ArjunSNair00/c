#include <stdio.h>
#include <string.h>
int main()
{
    char a[]="amogmosem";
    const char *ptr=a;
    char b='m';
    int count=0;
    while (ptr!=NULL)
    {
        count++;
        ptr++;
        ptr=strchr(ptr,b);
    }
    printf("%d",count);
    return 0;
}