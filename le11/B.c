#include <stdlib.h>
#include <stdio.h>

enum colors
{
  WHITE,
  GRAY,
  BLACK,
};

typedef struct
{
  enum colors color;
  int k;
  int d;
  int f;
  int *adj;
} Node;

void visit(int u, int *time, Node *graph)
{
  Node *node = &graph[u];
  node->color = GRAY;
  node->d = ++(*time);

  for (int i = 0; i < node->k; i++)
  {
    if (graph[node->adj[i]].color == WHITE)
    {
      visit(node->adj[i], time, graph);
    }
  }
  node->color = BLACK;
  node->f = ++(*time);
}

void dfs(int n, Node *graph)
{
  int time = 0;
  for (int i = 0; i < n; i++)
  {
    if (graph[i].color == WHITE)
      visit(i, &time, graph);
  }
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
    node->color = WHITE;
    scanf("%d", &node->k);
    node->adj = malloc(node->k * sizeof(int));
    for (int j = 0; j < node->k; j++)
    {
      int v;
      scanf("%d", &v);
      node->adj[j] = v - 1;
    }
  }

  dfs(n, graph);

  for (int i = 0; i < n; i++)
    printf("%d %d %d\n", i + 1, graph[i].d, graph[i].f);

  for (int i = 0; i < n; i++)
    free(graph[i].adj);

  free(graph);

  return 0;
}