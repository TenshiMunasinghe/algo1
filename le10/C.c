#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 1000

int max(int a, int b)
{
  return a > b ? a : b;
}

size_t strlen(const char *str)
{
  const char *s;
  for (s = str; *s; ++s)
    ;
  return (s - str);
}

int lcs(char x[MAX_LENGTH], char y[MAX_LENGTH], int p, int q)
{
  int L[p + 1][q + 1];

  for (int i = 0; i <= p; i++)
  {
    for (int j = 0; j <= q; j++)
    {
      if (i == 0 || j == 0)
        L[i][j] = 0;

      else if (x[i - 1] == y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;

      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }
  return L[p][q];
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    char x[MAX_LENGTH];
    char y[MAX_LENGTH];

    scanf("%s", x);
    scanf("%s", y);

    int i = strlen(x);
    int j = strlen(y);
    // printf("%d %d\n", i, j);
    printf("%d\n", lcs(x, y, i, j));
  }
  return 0;
}