// bracket pair verifier
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct Node
{
  int val;
  struct Node *next;
};

int indexof(char C[], int n, int match)
{
  for (int i = 0; i < n; i++)
  {
    if (C[i] == match)
      return i;
  }

  return -1;
}

struct Node *create_node(int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->val = data;
  temp->next = NULL;
  return temp;
}

void print_linked_list(struct Node *start)
{
  struct Node *temp = start;
  while (temp != NULL)
  {
    printf("%c ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

bool validate(char A[], int n)
{
  struct Node *head = NULL;

  char opening_arr[] = {'{', '(', '['};
  char closing_arr[] = {'}', ')', ']'};

  for (int i = 0; i < n; i++)
  {
    print_linked_list(head);

    char c = A[i];
    int opening = indexof(opening_arr, n, c);
    if (opening >= 0)
    {
      struct Node *insert = create_node(c);
      insert->next = head;
      head = insert;
    }
    else
    {
      int closing = indexof(closing_arr, n, c);
      if (closing < 0)
        continue;

      if (head == NULL)
      {
        return false;
      }
      else
      {
        char opening = head->val;

        if (c == '}')
        {
          if (opening != '{')
            return false;
        }
        else if (c == ']')
        {
          if (opening != '[')
            return false;
        }
        else if (c == ')')
        {
          if (opening != '(')
            return false;
        }

        head = head->next;
      }
    }
  }

  return head == NULL;
}

int main(void)
{
  char A[] = {'[', '{', '(', 'a', '+', 'b', ')', '/', '2', '}', ']'};
  char B[] = {'[', '{', '(', 'a', '+', 'b', ')', '/', '3', ')', '}'};

  // assert(validate(A, 11));
  // assert(!validate(B, 11));
  printf("%d\n", validate(A, 11));
  printf("%d\n", validate(B, 11));
  return 0;
}