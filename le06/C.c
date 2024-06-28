#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char suit;
  int val;
} Card;

void swap(int *A, int idx1, int idx2)
{
  int temp = A[idx1];
  A[idx1] = A[idx2];
  A[idx2] = temp;
}

int partition(Card *A, int start, int end)
{
  int i = start - 1;
  for (int j = 0; j < end; j++)
  {
    if (A[j].val <= A[end].val)
      swap(A, ++i, j);
  }
  swap(A, ++i, A[end].val);
  return i;
}

void quickSort(Card *A, int start, int end)
{
  if (start < end)
  {
    int pivot = partition(A, start, end);
    quickSort(A, start, pivot - 1);
    quickSort(A, pivot + 1, end);
  }
}

void printArr(int n, Card *arr)
{
  for (int i = 0; i < n - 1; i++)
    printf("%c %d\n", arr[i].suit, arr[i].val);
}

int main()
{
  Card *A;
  int n;

  scanf("%d", &n);

  A = malloc(sizeof(Card) * n + 1);

  for (int i = 0; i < n; i++)
  {
    scanf("%c %d", &A[i].suit, &A[i].val);
  }

  quickSort(A, 0, n - 1);
  printArr(n, A);

  return 0;
}