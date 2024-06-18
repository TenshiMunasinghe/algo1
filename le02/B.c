#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int swapCount = 0;

  for (int i = 0; i < n; i++)
  {
    // find max
    int minIdx = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }

    // swap
    if (minIdx != i)
    {
      int temp = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = temp;
      swapCount++;
    }
  }

  for (int i = 0; i < n - 1; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("%d\n", arr[n - 1]);

  printf("%d\n", swapCount);

  return EXIT_SUCCESS;
}