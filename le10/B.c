#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 101
#define INF 1000000

int min(int a, int b)
{
  return a < b ? a : b;
}

void matrixChainOrder(int M[MAX_SIZE][MAX_SIZE], int n, int p[MAX_SIZE])
{
  for (int i = 0; i < n; i++)
    M[i][i] = 0;
  for (int l = 1; l < n; l++)
    for (int i = 0; i < n - l + 1; i++)
    {
      int j = i + l - 1;
      M[i][j] = INF;
      for (int k = i; k < j - 1; k++)
      {
        int q = M[i][k] + M[k + 1][j] + (p[i - 1] * p[k] * p[j]);
        printf("%d %d %d\n", M[i][k], M[k + 1][j], (p[i - 1] * p[k] * p[j]));
        M[i][j] = min(M[i][j], q);
      }
    }
}

// matrixChainOrder(p)
// n = p.length-1
// for i = 1 to n
// m[i, i] = 0
// for l = 2 to n /* length = the number of matrix */
// for i = 1 to n-l+1
// j = i+l-1
// m[i, j] = INF
// for k = i to j-1
// q = m[i,k] + m[k+1, j] + p[i-1]*p[k]*p[j]
// m[i,j] = min(m[i,j], q)

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

  int M[MAX_SIZE][MAX_SIZE];

  matrixChainOrder(M, n + 1, p);

  printf("%d\n", M[0][n - 1]);

  return 0;
}