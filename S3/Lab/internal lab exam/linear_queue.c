#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1, size;

void enqueue(int x) {
    if (rear == size - 1) { printf("Overflow\n"); return; }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) { printf("Underflow\n"); return -1; }
    int x = queue[front++];
    if (front > rear) front = rear = -1;
    return x;
}

void display() {
    if (front == -1) { printf("Empty\n"); return; }
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, x;
    printf("Enter queue size: ");
    scanf("%d", &size);

    while (1) {
        scanf("%d", &choice);
        if (choice == 1) { scanf("%d", &x); enqueue(x); display(); }
        else if (choice == 2) { dequeue(); display(); }
        else if (choice == 3) break;
    }
    return 0;
}
