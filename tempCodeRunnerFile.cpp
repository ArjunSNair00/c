#include <stdio.h>
#include <stdlib.h>  // for system(), abs()
#include <windows.h> // for Sleep() and console colors

// Set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Print array with highlighted element
void printAnimatedArray(int arr[], int size, int highlight) {
    for (int i = 0; i < size; i++) {
        if (i == highlight) {
            setColor(12); // Bright red
            printf("[%d] ", arr[i]);
            setColor(7);  // Back to default (gray)
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Clear console screen
void clearScreen() {
    system("cls");
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int steps, dir;
    int speed = 500; // Animation speed in milliseconds
    int originalFirstPos = 0; // Tracks original first element position

    printf("Original array: ");
    printAnimatedArray(arr, size, originalFirstPos);
    
    printf("\nEnter rotation steps (positive for right, negative for left): ");
    scanf("%d", &steps);
    
    // Determine direction and make steps positive
    dir = (steps > 0) ? 1 : 0;
    steps = abs(steps); // Handle overflow

    for (int i = 0; i < steps; i++) {
        clearScreen();
        printf("Performing %s rotation (%d of %d):\n", 
              dir ? "right" : "left", i+1, steps);
        
        if (dir) { // Right rotation
            int temp = arr[size-1];
            printf("Moving last element [%d] to front:\n", temp);
            
            for (int j = size-2; j >= 0; j--) {
                arr[j+1] = arr[j];
                printAnimatedArray(arr, size, originalFirstPos);
                Sleep(speed);
                if (j > 0) clearScreen();
            }
            
            arr[0] = temp;
            originalFirstPos = (originalFirstPos + 1) % size;
        } 
        else { // Left rotation
            int temp = arr[0];
            printf("Moving first element [%d] to end:\n", temp);
            
            for (int j = 0; j < size-1; j++) {
                arr[j] = arr[j+1];
                printAnimatedArray(arr, size, originalFirstPos);
                Sleep(speed);
                if (j < size-2) clearScreen();
            }
            
            arr[size-1] = temp;
            originalFirstPos = (originalFirstPos - 1 + size) % size;
        }
        
        printf("\nOriginal first element is now at position %d\n", originalFirstPos);
        Sleep(1000); // Pause to show result
    }

    clearScreen();
    printf("Final result after %d %s rotation(s):\n", 
          steps, dir ? "right" : "left");
    printAnimatedArray(arr, size, originalFirstPos);
    printf("\nThe original first element moved from position 0 to %d\n", originalFirstPos);

    return 0;
}