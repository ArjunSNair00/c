#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

int is_full(int size) {
    return (front == (rear + 1) % size);
}

int is_empty() {
    return front == -1;
}

int enqueue(int data, int size) {
    if (is_full(size)) {
        printf("Overflow\n");
        return -1;
    }
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    queue[rear] = data;
    return 0;
}

int dequeue(int size) {
    if (is_empty()) {
        printf("Underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;  // queue became empty
    } else {
        front = (front + 1) % size;
    }
    return data;
}

void display(int size) {
    if (is_empty()) {
        printf("Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int size, choice, data;
    printf("Enter queue size: ");
    scanf("%d", &size);

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            if (enqueue(data, size) != -1) {
                printf("Enqueue: ");
                display(size);
            }
        }
        else if (choice == 2) {
            if (dequeue(size) != -1) {
                printf("Dequeue: ");
                display(size);
            }
        }
        else break;
    }
}