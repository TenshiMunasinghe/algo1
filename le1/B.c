#include <stdio.h>
#include <math.h>

int main()
{
  int a, b, x, y;
  int gcd = 1;

  scanf("%d %d", &a, &b);

  if (a == b)
  {
    printf("%d\n", a);
    return 0;
  }

  // x >= y
  if (a >= b)
  {
    x = a;
    y = b;
  }
  else
  {
    x = b;
    y = a;
  }

  x = x % y;

  for (int i = 2; i < sqrt(y); i++)
  {
    if (x % i == 0 && y % i == 0 && i > gcd)
    {
      gcd = i;
    }

    int correspondingFactor = y / i;
    if (x % correspondingFactor == 0 && y % i == 0 && correspondingFactor > gcd)
    {
      gcd = correspondingFactor;
    }
  }

  printf("%d\n", gcd);

  return 0;
}
