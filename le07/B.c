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

int computeHeight(Node *tree, int i)
{
  if (i == -1 || (tree[i].left == -1 && tree[i].right == -1))
    return 0;

  int left = computeHeight(tree, tree[i].left);
  int right = computeHeight(tree, tree[i].right);

  return left > right ? left + 1 : right + 1;
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

  for (int i = 0; i < n; i++)
  {
    int depth, sibling, degree, height;
    Node *currentNode;

    // check sibling
    if (tree[i].parent == -1)
      sibling = -1;
    else if (i == tree[tree[i].parent].left)
      sibling = tree[tree[i].parent].right;
    else
      sibling = tree[tree[i].parent].left;

    // compute depth
    depth = 0;
    currentNode = &tree[i];
    while (currentNode->parent != -1)
    {
      depth++;
      currentNode = &(tree[currentNode->parent]);
    }

    if (tree[i].left == -1 && tree[i].right == -1)
      degree = 0;
    else if (tree[i].left != -1 && tree[i].right != -1)
      degree = 2;
    else
      degree = 1;

    height = computeHeight(tree, i);

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, tree[i].parent, sibling, degree, depth, height);

    if (tree[i].parent == -1)
      printf("root");
    else if (tree[i].left == -1 && tree[i].right == -1)
      printf("leaf");
    else
      printf("internal node");

    printf("\n");
  }

  return 0;
}