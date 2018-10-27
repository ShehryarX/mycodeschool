#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

struct BstNode
{
  int data;
  struct BstNode *left;
  struct BstNode *right;
};

struct BstNode *get_new_node(int data)
{
  struct BstNode *new_node = (struct BstNode *)malloc(sizeof(struct BstNode));
  new_node->data = data;
  new_node->right = new_node->left = NULL;
  return new_node;
}

struct BstNode *insert(BstNode *root, int data)
{
  if (root == NULL)
  {
    root = get_new_node(data);
    return root;
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

bool search(BstNode *root, int data)
{
  if (root == NULL)
  {
    return false;
  }
  else if (root->data == data)
  {
    return true;
  }
  else if (data <= root->data)
  {
    return search(root->left, data);
  }
  else
  {
    return search(root->right, data);
  }
}
