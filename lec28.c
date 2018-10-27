#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

struct BstNode
{
  int data;
  struct Node *left;
  struct Node *right;
};

struct BstNode *
get_new_node(int data)
{
  struct BstNode *new_node = (struct BstNode *)malloc(sizeof(struct BstNode));
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

struct BstNode *insert(struct BstNode *root, int data)
{
  if (root == NULL)
  {
    root = get_new_node(data);
  }
  else if (data <= root->data)
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}

bool search(struct BstNode *root, int data)
{
  if (root == NULL)
    return false;
  if (root->data == data)
    return true;
  else if (data <= root->data)
    return search(root->left, data);
  else
    return search(root->right, data);
}

int main(void)
{
  struct BstNode *root = NULL; // address of root
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 25);
  root = insert(root, 8);
  root = insert(root, 12);

  int search[] = {15, 10, 20, 25, 8, 12, 21, 22, 30, 5, 45};
  int len = sizeof(search) / sizeof(search[0]);
  for (int i = 0; i < len; i++)
  {
    int val = search[i];
    bool found = search(root, val);
    printf("%d: %s\n", val, found ? "Found!" : "Not found!");
  }

  return 0;
}