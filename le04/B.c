#include <stdio.h>
#include <stdlib.h>

int binarySearch(int n, int *arr, int key)
{
  int left = 0, right = n, m;
  while (left < right)
  {
    m = (left + right) / 2;
    if (key == arr[m])
      return m;
    if (arr[m] > key)
    {
      right = m;
    }
    else
    {
      left = m + 1;
    }
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

  int cnt = 0;

  for (int i = 0; i < q; i++)
  {
    if (binarySearch(n, S, T[i]) != -1)
      cnt++;
  }

  printf("%d\n", cnt);
  return EXIT_SUCCESS;
}