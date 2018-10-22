// reverse a linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}

reverse(struct Node *head)
{
  struct Node *current, *prev, *next;
  current = head;
  prev = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
}

void print()
{
  struct Node *temp = head;

  printf("Printing: \n");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void)
{
  struct Node *head;
  head = NULL;
  insert(head, 2);
  insert(head, 4);
  insert(head, 6);
  insert(head, 5);
  print();
  reverse(head);
  print();
  return 0;
}