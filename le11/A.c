#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int M[n][n];

  // initialize matrix
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      M[i][j] = 0;

  for (int i = 0; i < n; i++)
  {
    int u, k;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++)
    {
      int v;
      scanf("%d", &v);
      M[u - 1][v - 1] = 1;
    }
    for (int j = 0; j < n - 1; j++)
      printf("%d ", M[i][j]);
    printf("%d\n", M[i][n - 1]);
  }

  return 0;
}