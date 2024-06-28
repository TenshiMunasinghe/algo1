#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10001

void countSort(unsigned short *A, unsigned short *B, int n)
{
  int C[VMAX];
  for (int i = 0; i < VMAX; i++)
    C[i] = 0;

  for (int i = 0; i < n; i++)
    C[A[i]]++;

  for (int i = 1; i < VMAX; i++)
    C[i] += C[i - 1];

  for (int i = n - 1; i >= 0; i--)
    B[C[A[i]]-- - 1] = A[i];
}

void printArr(int n, unsigned short *arr)
{
  for (int i = 0; i < n - 1; i++)
    printf("%d ", arr[i]);

  printf("%d\n", arr[n - 1]);
}

int main()
{
  unsigned short *A, *B;
  int n;

  scanf("%d", &n);

  A = malloc(sizeof(short) * n + 1);
  B = malloc(sizeof(short) * n + 1);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  countSort(A, B, n);
  printArr(n, B);

  return 0;
}