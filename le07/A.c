#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int parent;
  int childrenCount;
  int *children;
} Node;

int main()
{
  int n;
  scanf("%d", &n);

  Node root;
  root.depth = 0;

  for (int i = 0; i < n; i++)
  {
    Node node;
    scanf("%d %d", &node.value, &node.childrenCount);

    node.children = (int *)malloc(sizeof(int) * node.childrenCount);
    for (int j = 0; i < node.childrenCount; j++)
    {
      scanf("%d", &node.children[j]);
    }
  }

  return 0;
}