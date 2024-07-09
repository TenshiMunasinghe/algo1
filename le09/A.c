#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int heap[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &heap[i]);
  }

  for (int i = 0; i < n; i++)
  {
    int node, key, parent, left, right;
    node = i + 1;
    key = heap[i];

    printf("node %d: key = %d,", node, key);

    if (node != 1)
    {
      parent = heap[(node / 2) - 1];
      printf(" parent key = %d,", parent);
    }

    if (node * 2 - 1 < n)
    {
      left = heap[node * 2 - 1];
      printf(" left key = %d,", left);
    }
    if ((node * 2) < n)
    {
      right = heap[node * 2];
      printf(" right key = %d,", right);
    }

    printf("\n");
  }

  return 0;
}