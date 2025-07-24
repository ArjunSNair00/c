#include <stdio.h>
int in(char b, char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == b)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char a = 'b';
    char b[] = "aifbrof";
    if (in(a, b))
        printf("Yes");
    else
        printf("No");
    return 0;
}