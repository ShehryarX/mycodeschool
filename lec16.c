// stack modelled using linked lists
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
  int data;
  struct Node *link;
}

struct Node *top = NULL;

void push(int x)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = top->next;
  top = temp;
}

void *pop()
{
  struct Node *temp;
  if (top == NULL)
    return;
  temp = top;
  top = top->next;
  free(temp);
}

struct Node *top()
{
  return top;
}

bool isEmpty()
{
  return top == NULL;
}