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

void preOrderPrint(Node *tree, int k)
{
  printf(" %d", k);

  if (tree[k].left != -1)
    preOrderPrint(tree, tree[k].left);

  if (tree[k].right != -1)
    preOrderPrint(tree, tree[k].right);
}

void inOrderPrint(Node *tree, int k)
{
  if (tree[k].left != -1)
    inOrderPrint(tree, tree[k].left);

  printf(" %d", k);

  if (tree[k].right != -1)
    inOrderPrint(tree, tree[k].right);
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

  for (int i = 0; i < n; i++)
  {
    int p;
    scanf("%d", &p);
    scanf("%d%d", &tree[p].left, &tree[p].right);
    tree[tree[p].left].parent = p;
    tree[tree[p].right].parent = p;
  }

  int root = findRoot(n, tree);

  printf("Preorder\n");
  preOrderPrint(tree, root);
  printf("\n");

  printf("Inorder\n");
  inOrderPrint(tree, root);
  printf("\n");

  printf("Postorder\n");
  postOrderPrint(tree, root);
  printf("\n");

  return 0;
}