#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SENTINEL 1000000001

int merge(int *A, int left, int mid, int right)
{
  int cnt = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++)
  {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = A[mid + i];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++)
  {
    if (L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];

    cnt++;
  }
  return cnt;
}

int mergeSort(int *A, int left, int right)
{
  int cnt = 0;
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    cnt += mergeSort(A, left, mid);
    cnt += mergeSort(A, mid, right);
    cnt += merge(A, left, mid, right);
  }
  return cnt;
}

int main()
{
  int n;
  scanf("%d", &n);

  int A[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }

  int cnt = mergeSort(A, 0, n);

  for (int i = 0; i < n - 1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n - 1]);
  printf("%d\n", cnt);

  return EXIT_SUCCESS;
}