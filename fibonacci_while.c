#include <stdio.h>
int main()
{
    int a=0,b=1,c=1;
    printf("%d %d ",a,b);
    while (c<=100)
    {
        printf("%d ",c);
        a=b;
        b=c;
        c=a+b;
    }
    return 0;
}