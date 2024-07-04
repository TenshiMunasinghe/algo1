#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int parent;
  int left_child;
  int right_sibling;
} node;

void initNode(node *node)
{
  node->parent = -1;
  node->left_child = -1;
  node->right_sibling = -1;
}

int main()
{
  int n;
  scanf("%d", &n);

  node tree[n];
  for (int i = 0; i < n; i++)
    initNode(&tree[i]);

  int *current;
  int p, child_count;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &p, &child_count);

    current = &(tree[p].left_child);
    for (int j = 0; j < child_count; j++)
    {
      scanf("%d", current);
      tree[*current].parent = p;

      current = &(tree[*current].right_sibling);
    }
  }

  int depth, child;
  for (int i = 0; i < n; i++)
  {
    printf("node %d: parent = %d, depth = ", i, tree[i].parent);

    depth = 0;
    node *currentNode = &(tree[i]);
    while (currentNode->parent != -1)
    {
      depth++;
      currentNode = &(tree[currentNode->parent]);
    }

    printf("%d", depth);

    if (tree[i].parent == -1)
      printf(", root, [");
    else if (tree[i].left_child != -1)
      printf(", internal node, [");
    else
    {
      printf(", leaf, []\n");
      continue;
    }

    child = tree[i].left_child;
    while (child != -1)
    {
      printf("%d", child);

      child = tree[child].right_sibling;
      if (child != -1)
        printf(", ");
    }
    printf("]\n");
  }
  return 0;
}