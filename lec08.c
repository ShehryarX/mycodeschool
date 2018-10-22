#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *head;

/*
  Insert integer at end of list
*/
void insert(int data)
{
  struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
  insert->data = data;
  insert->next = NULL;

  if (head == NULL)
  {
    head = insert;
    return;
  }

  struct Node *temp = head;
  struct Node *last = NULL;

  while (temp != NULL)
  {
    last = temp;
    temp = temp->next;
  }
  last->next = insert;
}

/*
  Print all the elements in the list
*/
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

/*
  Deletes node at position n
*/
void delete (int n)
{
  struct Node *temp1 = head;

  if (n == 1)
  {
    head = temp1->next;
    free(temp1);
    return;
  }

  for (int i = 0; i < n - 2; i++)
  {
    temp1 = temp1->next; // n-1 th node
  }
  struct Node *temp2 = temp1->next; // nth node
  temp1->next = temp2->next;        // n+1 th node
  free(temp2);                      // frees memory allocated with malloc
}

int main()
{
  head = NULL;
  insert(2);
  insert(4);
  insert(6);
  insert(5);
  print();
  int n;
  printf("Enter a position: \n");
  scanf("%d", &n);
  delete (n);
  print();
  return 0;
}