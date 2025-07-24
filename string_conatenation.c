#include <stdio.h>

int len(char a[])
{
    int length=0;
    for(int i=0;a[i]!='\0';i++)
        length++;
    return length;
}

void strcat(char s1[], char s2[])
{
    int len1 = len(s1); // Length of s1
    int len2 = len(s2); // Length of s2

    // Concatenate s2 to s1
    for (int i = 0; i < len2; i++)
    {
        s1[len1 + i] = s2[i];
    }

    // Null-terminate the result
    s1[len1 + len2] = '\0';
}

int main()
{
    char s1[100] = "amogus"; // Ensure s1 has enough space for concatenation
    char s2[] = "baka";

    strcat(s1, s2); // Concatenate s2 to s1
    printf("%s\n", s1);    // Print the result

    return 0;
}