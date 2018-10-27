#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head;

void insert(int data)
{
  struct Node *insert_node = (struct Node *)malloc(sizeof(struct Node));
  insert_node->data = data;
  insert_node->next = NULL;

  struct Node *temp = head;
  if (head == NULL)
  {
    head = insert_node;
    return;
  }
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = insert_node;
}

void reverse()
{
  struct Node *stack_head = NULL;
  struct Node *temp = head;
  while (temp != NULL)
  {
    int val = temp->data;

    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    insert->data = val;
    insert->next = stack_head;
    stack_head = insert;

    temp = temp->next;
  }

  temp = stack_head;
  while (temp != NULL)
  {
    int val = temp->data;
    printf("%d ", val);
    temp = temp->next;
  }
}

void print_linked_list()
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void)
{
  head = NULL;

  insert(5);
  insert(7);
  insert(8);
  insert(0);
  insert(8);
  insert(4);

  print_linked_list();

  reverse();

  // print_linked_list();

  return 0;
}