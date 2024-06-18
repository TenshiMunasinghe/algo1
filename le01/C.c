#include <stdio.h>
#include <math.h>

int isPrime(int n);

int main()
{
  int n;
  int count = 0;

  scanf("%d", &n); // read the size of array

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]); // get each element of array one by one
  }

  for (int i = 0; i < n; i++)
  {
    if (isPrime(arr[i]) == 1)
      count++;
  }

  printf("%d\n", count);

  return 0;
}

int isPrime(int n)
{
  if (n == 2)
    return 1;

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}