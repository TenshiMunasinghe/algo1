#include <stdio.h>
#include <stdlib.h>

void printArr(int start, int end, int *arr)
{
  for (int i = start; i < end; i++)
    printf("%d ", arr[i]);

  printf("%d", arr[end]);
}

void swap(int *A, int idx1, int idx2)
{
  int temp = A[idx1];
  A[idx1] = A[idx2];
  A[idx2] = temp;
}

int partition(int *A, int start, int end)
{
  int i = start - 1;
  for (int j = 0; j < end; j++)
  {
    if (A[j] <= A[end])
      swap(A, ++i, j);
  }
  swap(A, ++i, end);

  printArr(start, i - 1, A);
  printf(" [%d] ", A[i]);
  printArr(i + 1, end, A);
  printf("\n");

  return i;
}

// void quickSort(int *A, int start, int end)
// {
//   if (start < end)
//   {
//     int pivot = partition(A, start, end);
//     quickSort(A, start, pivot - 1);
//     quickSort(A, pivot + 1, end);
//   }
// }

int main()
{
  int *A;
  int n;

  scanf("%d", &n);

  A = malloc(sizeof(int) * n + 1);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  partition(A, 0, n - 1);

  return 0;
}