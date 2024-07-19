#include <stdlib.h>
#include <stdio.h>

#define INF 1000000

typedef struct
{
  int target;
  int length;
} Edge;

typedef struct
{
  int k;
  Edge *edges;
} Node;

void shortestPath(int n, Node nodes[n], int u, int weight[n])
{
  Node node = nodes[u];
  for (int j = 0; j < node.k; j++)
  {
    Edge edge = node.edges[j];
    int newWeight = edge.length + weight[u];
    if (weight[edge.target] > newWeight)
    {
      weight[edge.target] = newWeight;
      shortestPath(n, nodes, edge.target, weight);
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  Node nodes[n];
  int weight[n];

  for (int i = 0; i < n; i++)
  {
    int u;
    scanf("%d", &u);
    Node *pNode = &nodes[u];
    scanf("%d", &pNode->k);
    pNode->edges = malloc(pNode->k * sizeof(Edge));
    for (int j = 0; j < pNode->k; j++)
    {
      scanf("%d", &(pNode->edges[j].target));
      scanf("%d", &(pNode->edges[j].length));
    }
    weight[u] = INF;
  }
  weight[0] = 0;
  shortestPath(n, nodes, 0, weight);

  for (int i = 0; i < n; i++)
  {
    printf("%d %d\n", i, weight[i]);
  }
  return 0;
}