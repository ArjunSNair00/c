#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    int sum=0;
    int i;
    printf("Count: %d\n",argc);
    printf("File name: %s\n",argv[0]);
    printf("inputs: ");
    for (i=1;i<argc;i++)
    {
        printf("%d ",atoi(argv[i]));
        sum+=atoi(argv[i]);
    }
    printf("\nSum: %d",sum);
    return 0;
}