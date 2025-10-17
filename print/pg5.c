#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  char url[100];
  struct Node *prev;
  struct Node *next;
} Node;

Node *createNode()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
    exit(1);
  newNode->prev = newNode->next = NULL;
  return newNode;
}

void visitPage(Node **current)
{
  Node *newNode = createNode();
  printf("Enter URL: ");
  scanf("%s", newNode->url);

  if (*current)
  {
    Node *temp = (*current)->next;
    while (temp)
    {
      Node *toDelete = temp;
      temp = temp->next;
      free(toDelete);
    }
    (*current)->next = NULL;
    newNode->prev = *current;
  }

  if (*current)
    (*current)->next = newNode;
  *current = newNode;

  printf("Visited: %s\n", newNode->url);
}

void showCurrent(Node *current)
{
  if (current)
    printf("Current: %s\n", current->url);
  else
    printf("Empty\n");
}

void goBack(Node **current)
{
  if (*current && (*current)->prev)
  {
    *current = (*current)->prev;
    printf("Back: %s\n", (*current)->url);
  }
  else
    printf("Empty\n");
}

void goForward(Node **current)
{
  if (*current && (*current)->next)
  {
    *current = (*current)->next;
    printf("Forward: %s\n", (*current)->url);
  }
  else
    printf("Empty\n");
}

int main()
{
  Node *current = NULL;
  int cmd;

  printf("Commands: 1=Visit 2=Back 3=Forward 4=Current 5=Exit\n");

  while (1)
  {
    printf("\nEnter command: ");
    if (scanf("%d", &cmd) != 1)
      break;
    if (cmd == 5)
      break;

    switch (cmd)
    {
    case 1:
      visitPage(&current);
      break;
    case 2:
      goBack(&current);
      break;
    case 3:
      goForward(&current);
      break;
    case 4:
      showCurrent(current);
      break;
    default:
      printf("Invalid\n");
    }
  }

  while (current && current->prev)
    current = current->prev;
  while (current)
  {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
  return 0;
}
