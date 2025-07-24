#include <stdio.h>

int main() {
    char a[30], b[30];
    
    printf("Enter a word: ");
    scanf("%[^\n]", a);
    printf("Enter a word: ");
    scanf("%*c %[^\n]", b);
    
    printf("The two words are: %s %s\n", a, b);
    return 0;
}
