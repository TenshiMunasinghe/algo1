#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 100005

typedef struct
{
  char name[100];
  int t;
} P;

P Q[LEN + 1];
int head = 0, tail = 0, n;

int isEmpty()
{
  return head == tail ? 1 : 0;
}

int isFull()
{
  return (head == (tail + 1) % n) ? 1 : 0;
}

void enqueue(P x)
{
  if (isFull() == 1)
  {
    printf("Memory overflow\n");
    exit(1);
  }
  tail = (tail + 1) % n;
  Q[tail] = x;
}

P dequeue()
{
  if (isEmpty() == 1)
  {
    printf("Memory underflow\n");
    exit(1);
  }
  P x = Q[head];
  // printf("head %d\n", head);
  head = (head + 1) % n;

  return x;
}

int main()
{
  int elapse = 0;
  int i, q;
  P u;

  scanf("%d %d", &n, &q);

  for (i = 0; i < n; i++)
  {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
    // printf("insert %s %d\n", Q[i].name, Q[i].t);
  }
  tail = n - 1;
  // printf("initial %d %d\n", head, tail);

  while (isEmpty() == 0)
  {
    u = dequeue();
    // printf("dequeue %d %d\n", head, tail);
    // printf("u %s %d\n", u.name, u.t);
    if (u.t > q)
    {
      elapse += q;
      u.t -= q;
      enqueue(u);
      // printf("enqueue %d %d\n", head, tail);
    }
    else
    {
      elapse += u.t;
      printf("%s %d\n", u.name, elapse);
    }
  };
  elapse += Q[head].t;
  printf("%s %d\n", Q[head].name, elapse);

  return EXIT_SUCCESS;
}