#include <stdio.h>
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

int is_full(int size) { 
    return rear == size - 1; 
}

int is_empty() { 
    return front == -1 || front > rear; 
}

int enqueue(int data, int size) {
    if (is_full(size)) {
        printf("Overflow\n");
        return -1;
    }
    if (is_empty()) 
        front = 0;
    queue[++rear] = data;
    return 0;
}

int dequeue() {
    if (is_empty()) {
        printf("Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (is_empty()) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) 
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int size, choice, data, val;
    printf("Enter queue size: "); 
    scanf("%d", &size);

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Exit: ");
        scanf("%d", &choice);

        if (choice == 1) { 
            printf("Enter data: ");
            scanf("%d", &data); 
            val=enqueue(data, size); 
            if (val!=-1)
            {
                printf("Enqueue: ");
                display();
            }
        }
        else if (choice == 2) {
            val=dequeue();
            if (val!=-1)
            {
                printf("Dequeue: ");
                display();
            }
        }
        else 
            break;
    }
}