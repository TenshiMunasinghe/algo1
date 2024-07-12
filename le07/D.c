#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int parent;
  int left;
  int right;
} Node;

void initNode(Node *node)
{
  node->parent = -1;
  node->left = -1;
  node->right = -1;
}

void postOrderPrint(Node *tree, int k)
{
  if (tree[k].left != -1)
    postOrderPrint(tree, tree[k].left);

  if (tree[k].right != -1)
    postOrderPrint(tree, tree[k].right);

  printf(" %d", k);
}

int findRoot(int n, Node *tree)
{
  for (int i = 0; i < n; i++)
    if (tree[i].parent == -1)
      return i;
  return -1;
}

int main()
{
  int n;
  scanf("%d", &n);

  Node tree[n];
  for (int i = 0; i < n; i++)
    initNode(&tree[i]);

  int preArr[n], inArr[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &preArr[i]);

  for (int i = 0; i < n; i++)
    scanf("%d", &inArr[i]);

  return 0;
}