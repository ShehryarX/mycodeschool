#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}

struct Node *head;

recurse_print()
{
  if (p == NULL)
    return;

  recurse_print(p->next);
  printf("%d ", p->data);
}

void reverse(struct Node *p)
{
  if (p->next = NULL)
  {
    head = p;
    return;
  }
  reverse(p->next);

  struct Node *q = p->next;
  q->next = p;
  q->next = NULL;
}

int main(void)
{
  return 0;
}