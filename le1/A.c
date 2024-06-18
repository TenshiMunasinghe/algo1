#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void printArr(int n, int *arr);

int main()
{
  int n;

  scanf("%d", &n); // read the size of array

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]); // get each element of array one by one
  }

  for (int i = 1; i < n; i++)
  {
    printArr(n, arr);
    int temp = arr[i];

    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = temp;
  }

  printArr(n, arr);
}

void printArr(int n, int *arr)
{
  for (int i = 0; i < n - 1; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("%d\n", arr[n - 1]);
}
