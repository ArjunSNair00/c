#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,p=1;
    char str[30];
    printf("Enter a string: ");
    gets(str);
    int n=strlen(str);
    for (i=0,j=n-1;i<n/2;i++,j--)
    {
        if (str[i]!=str[j])
            p=0;
            break;
    }
    printf("It is %s palindrome",p?"a":"not a");
    return 0;
}