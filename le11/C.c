#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int k;
  int d;
  int *adj;
} Node;

void visit(int u, int dist, Node *graph)
{
  Node *node = &graph[u];

  if (node->d != -1 && dist > node->d)
    return;

  node->d = dist;

  for (int i = 0; i < node->k; i++)
    visit(node->adj[i], dist + 1, graph);
}

void bfs(Node *graph)
{
  visit(0, 0, graph);
}

int main()
{
  int n;
  scanf("%d", &n);

  Node *graph;
  graph = malloc((n) * sizeof(Node));

  for (int i = 0; i < n; i++)
  {
    int u;
    scanf("%d", &u);
    Node *node = &graph[u - 1];
    node->d = -1;
    scanf("%d", &node->k);
    node->adj = malloc(node->k * sizeof(int));
    for (int j = 0; j < node->k; j++)
    {
      int v;
      scanf("%d", &v);
      node->adj[j] = v - 1;
    }
  }

  bfs(graph);

  for (int i = 0; i < n; i++)
    printf("%d %d\n", i + 1, graph[i].d);

  for (int i = 0; i < n; i++)
    free(graph[i].adj);

  free(graph);

  return 0;
}
