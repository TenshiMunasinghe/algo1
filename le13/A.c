#include <stdlib.h>
#include <stdio.h>

#define N 8

enum
{
  EMPTY,
  NON_EMPTY,
};

void placeQueen(int u, int v, int row[N], int col[N], int dePos[2 * N], int deNeg[2 * N], int queen[N])
{
  queen[u] = v;
  row[u] = NON_EMPTY;
  col[v] = NON_EMPTY;
  dePos[u + v] = NON_EMPTY;
  deNeg[u - v + N - 1] = NON_EMPTY;
}

void removeQueen(int u, int v, int row[N], int col[N], int dePos[2 * N], int deNeg[2 * N], int queen[N])
{
  queen[u] = -1;
  row[u] = EMPTY;
  col[v] = EMPTY;
  dePos[u + v] = EMPTY;
  deNeg[u - v + N - 1] = EMPTY;
}

int solveNQueens(int i, int row[N], int col[N], int dePos[2 * N], int deNeg[2 * N], int queen[N])
{
  if (i == N)
    return 1;

  if (row[i] == NON_EMPTY)
    return solveNQueens(i + 1, row, col, dePos, deNeg, queen);

  for (int j = 0; j < N; j++)
  {
    if (col[j] == NON_EMPTY || dePos[i + j] == NON_EMPTY || deNeg[i - j + N - 1] == NON_EMPTY)
      continue;

    placeQueen(i, j, row, col, dePos, deNeg, queen);

    if (solveNQueens(i + 1, row, col, dePos, deNeg, queen))
      return 1;

    removeQueen(i, j, row, col, dePos, deNeg, queen);
  }

  return 0;
}

int main()
{
  int n;
  scanf("%d", &n);

  int row[N], col[N], dePos[2 * N], deNeg[2 * N], queen[N];

  for (int i = 0; i < N; i++)
  {
    row[i] = EMPTY;
    col[i] = EMPTY;
    dePos[i] = EMPTY;
    dePos[(2 * N) - i - 1] = EMPTY;
    deNeg[i] = EMPTY;
    deNeg[(2 * N) - i - 1] = EMPTY;
    queen[i] = -1;
  }

  // initialize
  for (int i = 0; i < n; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    placeQueen(u, v, row, col, dePos, deNeg, queen);
  }

  if (!solveNQueens(0, row, col, dePos, deNeg, queen))
  {
    printf("No solution found\n");
    return 1;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (queen[i] == j)
        printf("Q");
      else
        printf(".");
    }
    printf("\n");
  }

  return 0;
}