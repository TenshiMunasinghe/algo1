#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int sum = 1;
  int prev = 0;
  for (int i = 2; i <= n; i++)
  {
    int temp = sum;
    sum += prev;
    prev = temp;
  }

  printf("%d\n", sum + prev);
  return 0;
}