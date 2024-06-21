#include <stdio.h>
#include <stdlib.h>

int linearSearch(int n, int *arr, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  scanf("%d", &n);

  int S[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
  }
  int q;
  scanf("%d", &q);

  int T[n];
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &T[i]);
  }

  int cnt;

  for (int i = 0; i < q; i++)
  {
    if (linearSearch(n, S, T[i]) != -1)
      cnt++;
  }

  printf("%d\n", cnt);
  return EXIT_SUCCESS;
}