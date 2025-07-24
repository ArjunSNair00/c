#include <stdio.h>

void reverse(char arr[], int i, int j) {
    char temp;
    for (; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    char string[80];
    printf("Enter something: ");
    scanf(" %[^\n]", string);  // Note the leading space to consume leftover newline

    int len = 0;
    while (string[len] != '\0') {
        len++;
    }
    reverse(string, 0, len - 1);  // Correct: use actual string length

    printf("Reversed: %s\n", string);
    return 0;
}
