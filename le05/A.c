#include <stdlib.h>
#include <stdio.h>

int solve(int n, int *A, int i, int m)
{
  if (m == 0)
    return 1;
  if (i >= n)
    return 0;
  return solve(n, A, i + 1, m - A[i]) || solve(n, A, i + 1, m);
};

int main()
{
  int n;
  scanf("%d", &n);

  int A[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int q;
  scanf("%d", &q);

  for (int i = 0; i < q; i++)
  {
    int m;
    scanf("%d", &m);
    if (solve(n, A, 0, m) == 1)
      printf("yes\n");
    else
      printf("no\n");
  }

  return EXIT_SUCCESS;
}