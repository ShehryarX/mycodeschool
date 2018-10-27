#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
};

struct Node *head;

struct Node *pop()
{
  struct Node *new_head = head;
  head = head->next;
  return new_head;
}

void push(char c)
{
  struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
  insert->data = c;
  insert->next = head;
  head = insert;
}

void reverse(char C[], int n)
{
  // build the stack
  for (int i = 0; i < n; i++)
  {
    push(C[i]);
  }

  for (int i = 0; i < n; i++)
  {
    struct Node *popped = pop();
    C[i] = popped->data;
  }
}

void reverse_efficient(char C[], int n)
{
  int i = 0;
  int j = n - 1;

  while (i < j)
  {
    char t = C[j];
    C[j] = C[i];
    C[i] = t;
    i++;
    j--;
  }
}

void print_array(char C[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%c ", C[i]);
  }
  printf("\n");
}

int main(void)
{
  head = NULL;
  char C[] = {'s', 'h', 'e', 'h', 'r', 'y', 'a', 'r'};
  print_array(C, 8);
  reverse_efficient(C, sizeof(C) / sizeof(C[0]));
  print_array(C, 8);
  return 0;
}