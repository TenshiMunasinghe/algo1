#include <stdlib.h>
#include <stdio.h>

void maxHeapify(int n, int *heap, int idx)
{
  int largest, l, r;
  l = (idx + 1) * 2 - 1;
  r = (idx + 1) * 2;

  largest = (l < n && heap[l] > heap[idx]) ? l : idx;
  largest = (r < n && heap[r] > heap[largest]) ? r : largest;

  if (largest != idx)
  {
    int temp = heap[idx];
    heap[idx] = heap[largest];
    heap[largest] = temp;
    maxHeapify(n, heap, largest);
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  int heap[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &heap[i]);
  }

  for (int i = n / 2; i >= 0; i--)
    maxHeapify(n, heap, i);

  for (int i = 0; i < n; i++)
  {
    printf(" %d", heap[i]);
  }
  printf("\n");

  return 0;
}