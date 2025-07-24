#include <stdio.h>
int main()
{
    char a[30];
    char e;
    char e2=' ';
    int count=0;
    printf("Enter a string: ");
    scanf("%[^\n]",a);
    printf("Enter the element: ");
    scanf(" %c",&e);
    int n=sizeof(a);
    if (e>='a' && e<='z')
        e2=e-32;
    else if (e>='A' && e<='Z')
        e2=e+32;
    for (int i=0;i<n;i++)
    {
        if (a[i]==e || a[i]==e2)
            count++;
    }
    printf("The frequency is: %d",count);
    return 0;
}