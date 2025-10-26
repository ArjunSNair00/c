#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return -1;
    }
    if (front == -1)  // first element
        front = 0;
    rear++;
    queue[rear] = data;
    return 1;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        front = rear = -1;  // reset
        return -1;
    }
    int removed = queue[front];
    printf("Dequeued: %d\n", removed);
    front++;

    // if last element removed, reset to initial state
    if (front > rear)
        front = rear = -1;
    return removed;
}

void display() {
    if (front == -1)
        printf("Queue is Empty\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(13); display();
    enqueue(15); display();
    enqueue(188); display();

    dequeue();  // removes 13
    dequeue();  // removes 15
    display();  // shows remaining elements

    enqueue(200); display();
    enqueue(300); display();
    enqueue(400); display();
    dequeue(); display();
    return 0;
}
