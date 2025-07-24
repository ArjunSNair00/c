#include <stdio.h>
#include <string.h>
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
    char s[] = "abcdab"; // Replace with your input string

    int leftIndex = 0;
    int rightIndex = 0;
    int record = 0;
    char substr[100];

    while (rightIndex != strlen(s))
    {
        //if (in(s[rightIndex], substr))
        if (strchr(substr,s[rightIndex]))
            leftIndex += 1;
        else
            rightIndex += 1;
        slice(s, leftIndex, rightIndex, substr);
        if (strlen(substr) > record)
            record = strlen(substr);
    }
    printf("%d", record);
    return 0;
}