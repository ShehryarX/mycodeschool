// recursive traversal of linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *
insert(struct Node *head, int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    struct Node *temp1 = head;
    while (temp1->next != NULL)
    {
      temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
  }
  return head;
}

void print(struct Node *p)
{
  if (p == NULL)
    return;

  printf("%d ", p->data); // print current value
  print(p->next);         // recursive call
}

void print_reverse(struct Node *p)
{
  if (p == NULL)
    return;

  print_reverse(p->next);
  printf("%d ", p->data);
}

int main(void)
{
  struct Node *head = NULL;
  head = insert(head, 2);
  head = insert(head, 4);
  head = insert(head, 6);
  head = insert(head, 5);
  print(head);
}