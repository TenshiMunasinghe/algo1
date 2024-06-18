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
    for (int j = 1; j < n - i; j++)
    {
      if (arr[j] < arr[j - 1])
      {
        // swap
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        swapCount++;
      }
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