#include <stdio.h>

void slice(char s[], int a, int b, char result[]) {
    int i=a;
    for (i; i < b && s[i] != '\0'; i++) {
        result[i-a] = s[i];
    }
    result[i] = '\0';
}

int main() {
    char a[] = "abvifke";
    char b[30];  // Buffer to store the sliced string
    slice(a, 1, 5, b);
    printf("%s\n", b);  // Expected output: "abv"
    return 0;
}
