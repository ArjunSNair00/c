#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp = fopen("myfile.txt", "r");

    // Check if file opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char finput[50];

    while (fgets(finput, 50, fp)) {
        int len = strlen(finput);
        if (len > 0 && finput[len - 1] == '\n') {
            finput[len - 1] = '\0';
        }

        printf("%s ", finput);
    }

    
    fclose(fp);
    return 0;
}
