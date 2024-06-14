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

  int maxProf = arr[1] - arr[0];
  int currMin;
  if (arr[0] < arr[1])
  {
    currMin = arr[0];
  }
  else
  {
    currMin = arr[1];
  }

  for (int i = 2; i < n; i++)
  {
    if (arr[i] < currMin)
    {
      currMin = arr[i];
      continue;
    }
    int diff = arr[i] - currMin;
    if (diff > maxProf)
    {
      maxProf = diff;
    }
  }

  printf("%d\n", maxProf);

  return 0;
}