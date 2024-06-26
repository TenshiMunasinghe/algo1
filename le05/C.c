#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
  double x;
  double y;
} Point;

void printPoint(Point p)
{
  printf("%.8lf %.8lf\n", p.x, p.y);
};

void koch(int n, Point p1, Point p2)
{
  if (n == 0)
    return;

  Point s, t, u;

  s.x = p1.x + ((p2.x - p1.x) / 3);
  s.y = p1.y + ((p2.y - p1.y) / 3);

  t.x = p1.x + (2 * (p2.x - p1.x) / 3);
  t.y = p1.y + (2 * (p2.y - p1.y) / 3);

  u.x = ((t.x - s.x) * cos(M_PI / 3)) - ((t.y - s.y) * sin(M_PI / 3)) + s.x;
  u.y = ((t.x - s.x) * sin(M_PI / 3)) + ((t.y - s.y) * cos(M_PI / 3)) + s.y;

  koch(n - 1, p1, s);
  printPoint(s);

  koch(n - 1, s, u);
  printPoint(u);

  koch(n - 1, u, t);
  printPoint(t);

  koch(n - 1, t, p2);
}

int main()
{
  int n;
  scanf("%d", &n);

  Point p1, p2;

  p1.x = 0;
  p1.y = 0;

  p2.x = 100;
  p2.y = 0;

  printPoint(p1);
  koch(n, p1, p2);
  printPoint(p2);

  return EXIT_SUCCESS;
}