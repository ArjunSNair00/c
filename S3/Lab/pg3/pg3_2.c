#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int deque[MAX];

int is_full(int size) {
    return (front == 0 && rear == size - 1) || (front == rear + 1); 
}
int is_empty() {
    return front == -1; 
}

void insert_front(int data, int size) {
    if (is_full(size)) {
        printf("Overflow\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    deque[front] = data;
}

void insert_rear(int data, int size) {
    if (is_full(size)) {
        printf("Overflow\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
}

void delete_front(int size) {
    if (is_empty()) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
}

void delete_rear(int size) {
    if (is_empty()) {
        printf("Underflow\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

void display(int size) {
    if (is_empty()) {
        printf("Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}
int main() {
    int size, choice, data;

    printf("Enter deque size: ");
    scanf("%d", &size);

    while (1) {
        printf("\nSelect an option: \n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_front(data, size);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_rear(data, size);
                break;
            case 3:
                delete_front(size);
                break;
            case 4:
                delete_rear(size);
                break;
            case 5:
                display(size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}