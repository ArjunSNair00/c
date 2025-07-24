#include <stdio.h>
void main()
{
    char a[]="amogus";
    int size=sizeof(a)/sizeof(a[0]);
    char b[size];
    int len=size-1;
    for (int i=0;i<len;i++)
    {
        b[i]=a[len-1-i];
    }
    b[len] = '\0';
    printf("%s",b);
}