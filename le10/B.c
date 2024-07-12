#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 101
#define INF 1000000

int matrixChainOrder(int p[MAX_SIZE], int n)
{
  int M[n][n];

  // initialize
  for (int i = 1; i < n; i++)
    M[i][i] = 0;

  // l is current chain length
  for (int l = 2; l < n; l++)
  {
    for (int i = 1; i < n - l + 1; i++)
    {
      int j = i + l - 1;
      M[i][j] = INF;
      for (int k = i; k <= j - 1; k++)
      {
        int q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < M[i][j]) // replace M[i][j] if computed value is smaller
          M[i][j] = q;
      }
    }
  }

  return M[1][n - 1];
}

// matrixChainOrder(p)
// n = p.length-1
// for i = 1 to n
// M[i, i] = 0
// for l = 2 to n /* length = the number of matrix */
// for i = 1 to n-l+1
// j = i+l-1
// M[i, j] = INF
// for k = i to j-1
// q = M[i,k] + M[k+1, j] + p[i-1]*p[k]*p[j]
// M[i,j] = min(M[i,j], q)

int main()
{
  int n;
  scanf("%d", &n);
  int p[n + 1];

  for (int i = 0; i < n; i++)
  {
    int r, c;
    scanf("%d %d", &r, &c);
    if (i % 2 == 0)
    {
      p[i] = r;
    }
    p[i + 1] = c;
  }

  printf("%d\n", matrixChainOrder(p, n + 1));

  return 0;
}