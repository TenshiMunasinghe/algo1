#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printArr(int n, int arr[n], char delimeter);

void selectionSort(int n, int arr[n], int gap, int *cnt)
{
  for (int i = gap; i < n; i++)
  {
    int temp = arr[i];

    int j = i;
    while (j >= gap && arr[j - gap] > temp)
    {
      arr[j] = arr[j - gap];
      j -= gap;
      (*cnt)++;
    }

    arr[j] = temp;
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int cnt = 0;
  int m = log2(n) + 1;
  int G[m]; // {n/2, n/4, n/8, ...}

  for (int i = 0; i < m; i++)
  {
    G[i] = n / pow(2, i + 1);
    selectionSort(n, arr, G[i], &cnt);
  }

  printf("%d\n", m);
  printArr(m, G, ' ');
  printf("%d\n", cnt);
  printArr(n, arr, '\n');

  return EXIT_SUCCESS;
}

void printArr(int n, int arr[n], char delimeter)
{
  for (int i = 0; i < n - 1; i++)
  {
    printf("%d%c", arr[i], delimeter);
  }
  printf("%d\n", arr[n - 1]);
}