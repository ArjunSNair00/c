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

int len(char a[])
{
    int length = 0;
    for (int i = 0; a[i] != '\0'; i++)
        length++;
    return length;
}

void slice(char s[], int a, int b, char result[])
{
    int j = 0;
    for (int i = a; i < b && s[i] != '\0'; i++)
    {
        result[j++] = s[i];
    }
    result[j] = '\0'; // Null-terminate the string
}
int main()
{
    char s[] = "abcabcabcdefgab"; // Replace with your input string

    int leftIndex = 0;
    int rightIndex = 0;
    int record = 0;
    char substr[100];

    while (rightIndex != len(s))
    {
        if (in(s[rightIndex], substr))
            leftIndex += 1;
        else
            rightIndex += 1;
        slice(s, leftIndex, rightIndex, substr);
        if (len(substr) > record)
            record = len(substr);
    }
    printf("%d", record);
    return 0;
}