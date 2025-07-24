#include<stdio.h>
int main()
{
    char v[]="aeiou",a;
    int is_vowel=0;
    printf("Enter a character: ");
    scanf("%c",&a);
    for (int i=0;i<5;i++)
    {
        if (v[i]==a)
        {
            is_vowel=1;
            break;
        }
    }
    printf("It is %s vowel",is_vowel?"a":"not a");
    return 0;
}