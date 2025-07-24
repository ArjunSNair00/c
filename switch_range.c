#include <stdio.h>
int main()
{
    int mark;
    printf("Enter your mark: ");
    scanf("%d",&mark);
    switch (mark)
    {
        case 0 ...39:
            printf("Fail");
            break;
        case 40 ...100:
            printf("Pass");
            break;
        default:
            printf("Invalid marks");
    }
    return 0;
}