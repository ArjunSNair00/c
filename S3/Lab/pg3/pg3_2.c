#include <stdio.h>

int front = -1, rear = -1;

int is_full(int size) {
    return ((rear + 1) % size) == front;
}

int is_empty() {
    return front == -1;
}

int enqueue(int data, int queue[], int size) {
    if (is_full(size)) {
        printf("\nQueue Overflow\n");
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

int dequeue(int queue[], int size) {
    if (is_empty()) {
        printf("\nQueue Underflow\n");
        return -1;
    }

    int data = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    return data;
}

void display(int queue[], int size) {
    printf("Queue contents: ");
    for (int i = 0; i < size; i++) {
        // Check if the index i is part of the active queue
        int inQueue = 0;
        if (!is_empty()) {
            if (front <= rear) {
                if (i >= front && i <= rear) inQueue = 1;
            } else {
                if (i >= front || i <= rear) inQueue = 1;
            }
        }

        if (inQueue)
            printf("%d ",queue[i]);
    }
    printf("\n");
}



int main() {
    int size, choice, data;
    printf("Enter the size of queue: ");
    scanf("%d", &size);
    int queue[size];

    while (1) {
        printf("\nSelect the operation:\n1. Insertion\n2. Deletion\n3. Exit\nEnter the Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue element: ");
                scanf("%d", &data);
                if (enqueue(data, queue, size) == 0) {
                    printf("Queue after enqueue:\n");
                    display(queue, size);
                }
                break;

            case 2:
                if (dequeue(queue, size) != -1) {
                    printf("Queue after dequeue:\n");
                    display(queue, size);
                }
                break;

            case 3:
                return 0;

            default:
                printf("\nInvalid choice\n");
                break;
        }
    }

    return 0;
}
