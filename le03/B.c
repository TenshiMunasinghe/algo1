#include
#include
#define LEN 100005

typedef struct pp
{
  char name[100];
  int t;
} P;

P Q[LEN + 1];
int head, tail, n;

void enqueue(P x)
{
}

P dequeue()
{
}

int main()
{
  int elaps = 0, c;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);

  for (i = 1; i <= n; i++)
  {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);
  }

  return 0;
}