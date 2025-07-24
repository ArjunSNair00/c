#include <stdio.h>
int main()
{
    int first_check=0;
    int second_check=0;
    printf("%s",first_check?"access denied":second_check?"access denied":"access granted");
    return 0;
}