#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* createNode(int data){
  struct node *newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->link=NULL;
  return newNode;
}

struct node* linkedList(struct node* head,int data){
  if(head == NULL)
    head = createNode(data);
  else{
    struct node *last = head;
    while(last->link != NULL){
      last=last->link;
  }
  last->link=createNode(data);
  }
  return head;
}

struct node *removeLastNode(struct node *head)
{
    // If the list is empty
    if (head == NULL)
        return NULL;

    // If the list has only one node
    if (head->link == NULL)
    {
        free(head);
        return NULL;
    }

    // Find the second last node
    struct node *secondLast = head;
    while (secondLast->link->link != NULL)
    {
        secondLast = secondLast->link;
    }

    // Delete the last node
    free(secondLast->link);

    // Update link of second last node
    secondLast->link = NULL;

    return head;
}

void display(struct node *head){
  struct node *ptr=head;
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->link;
  }
  printf("\n");
}

void freeList(struct node* head) {
  struct node* temp;
  while (head != NULL) {
      temp = head;         // store current node
      head = head->link;   // move to next node
      free(temp);          // free current node
  }
  printf("Linked list freed successfully.\n");
}


int main(){
  struct node *head=NULL;
  int ch;
  int data;
  do{
    printf("\nEnter choice: 1 - Insert Element, 2-Remove last element, 3 - Display, 4 - Exit: ");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        scanf("%d",&data);
        head=linkedList(head,data);
        display(head);
        break;
      case 2:
        head=removeLastNode(head);
        display(head);
        break;
      case 3:
        display(head);
        break;
      case 4:
        freeList(head);
        printf("Exiting.....");
        break;
      default:
        printf("Invalid Choice");
    }
  }while(ch!=4);
  return 0;
}