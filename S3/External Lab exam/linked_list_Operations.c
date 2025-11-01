#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node* createNode(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

node* createLinkedList(node *head, int data) {
    if (head == NULL) {
        head = createNode(data);
    } else {
        node *last = head;
        while (last->link != NULL) {
            last = last->link;
        }
        last->link = createNode(data);
    }
    return head;
}

void display(node *head) {
    node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main() {
    node *head = NULL; //pointer to first node

    head = createLinkedList(head, 10);
    head = createLinkedList(head, 50);
    head = createLinkedList(head, 60);
    head = createLinkedList(head, 90);
    display(head);

    node *first=createNode(100);
    first->link=head;
    head=first;
    display(head);

    node *second=createNode(150);
    second->link=head;
    head=second;
    display(head);
    return 0;
}
