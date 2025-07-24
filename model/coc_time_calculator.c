#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

// Struct to store upgrade info
typedef struct {
    char name[50];
    time_t completion_time;
} Upgrade;

int main() {
    Upgrade upgrades[MAX_ENTRIES];
    int n;

    printf("Enter number of buildings/troops: ");
    scanf("%d", &n);
    getchar();  // Clear newline from buffer

    for (int i = 0; i < n; i++) {
        char name[50];
        int days, hours, minutes;

        printf("\nEntry %d:\n", i + 1);

        // Get name
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }

        // Get time
        printf("Enter time (days hours minutes): ");
        scanf("%d %d %d", &days, &hours, &minutes);
        getchar();  // Clear newline after scanf

        // Calculate completion time
        time_t now = time(NULL);
        time_t added_seconds = (days * 86400) + (hours * 3600) + (minutes * 60);
        time_t completion = now + added_seconds;

        // Store in struct
        strcpy(upgrades[i].name, name);
        upgrades[i].completion_time = completion;
    }

    // Sort by completion time (ascending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (upgrades[i].completion_time > upgrades[j].completion_time) {
                Upgrade temp = upgrades[i];
                upgrades[i] = upgrades[j];
                upgrades[j] = temp;
            }
        }
    }

    // Display sorted results
    printf("\n=== Upgrade Completion Schedule ===\n");
    for (int i = 0; i < n; i++) {
        struct tm *local = localtime(&upgrades[i].completion_time);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "(%B %d) %I:%M %p", local);
        printf("%s: %s\n", upgrades[i].name, buffer);
    }

    return 0;
}
