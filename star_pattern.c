#include <stdio.h>

int main() {
    int size = 20;
    for (int i = 0; i <= size; i++) {
        // Print spaces: as i increases, print fewer spaces
        for (int k = size; k > i; k--) {
            printf("     ");
        }
        // Print stars: i+1 stars on the i-th row
        for (int j = 0; j <= i; j++) {
            printf("ARJUN");
        }
        printf("\n");
    }
    return 0;
}
