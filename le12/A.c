#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INF 1000000

typedef struct
{
  int x;
  int y;
} IntTuple;

IntTuple minWeightIdx(int n, bool *isVisited, int M[n][n])
{
  IntTuple idx;
  idx.x = 0;
  idx.y = 0;
  for (int i = 0; i < n; i++)
  {
    if (!isVisited[i])
      continue;
    for (int j = 0; j < n; j++)
    {
      if (M[i][j] != -1 && M[i][j] < M[idx.x][idx.y] && !isVisited[j])
      {
        idx.x = i;
        idx.y = j;
      }
    }
  }
  return idx;
}

int primTotal(int n, int M[n][n])
{
  int parent[n];
  bool isVisited[n];
  int total = 0;

  for (int i = 0; i < n; i++)
    isVisited[i] = false;

  parent[0] = -1;
  isVisited[0] = true;

  for (int i = 0; i < n - 1; i++)
  {
    IntTuple minIdx = minWeightIdx(n, isVisited, M);
    isVisited[minIdx.y] = true;
    int minWeight = M[minIdx.x][minIdx.y];
    if (minWeight == -1)
      break;
    total += minWeight;
  }
  return total;
}

int main()
{
  int n;
  scanf("%d", &n);

  int M[n][n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      int k;
      scanf("%d", &k);
      M[i][j] = k == -1 ? INF : k;
    }

  printf("%d\n", primTotal(n, M));

  return 0;
}