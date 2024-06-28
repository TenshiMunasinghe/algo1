#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000003
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch)
{
  if (ch == 'A')
    return 1;
  else if (ch == 'C')
    return 2;
  else if (ch == 'G')
    return 3;
  else if (ch == 'T')
    return 4;

  return 0;
}

/* convert a string into an integer value */
long long getKey(char str[L])
{
  long long sum = 0, p = 1, i;
  for (i = 0; i < strlen(str); i++)
  {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

int find(char str[L])
{
  int key = getKey(str);
  int i = 0;
  while (1)
  {
    int j = (h1(key) + (i * h2(key))) % M;
    if (H[j][0] == '\0' || i >= M)
      return 0;
    else if (strcmp(H[j], str) == 0)
      return 1;
    else
      i++;
  }
}

int insert(char str[L])
{
  int key = getKey(str);
  int i = 0;
  while (1)
  {
    int j = (h1(key) + (i * h2(key))) % M;
    if (H[j][0] != '\0')
      i++;
    else
    {
      strcpy(H[j], str);
      return 1;
    }
  }
}

int main()
{
  int i, n, h;
  char str[L], com[9];
  for (i = 0; i < M; i++)
    H[i][0] = '\0';

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%s %s", com, str);

    if (com[0] == 'i')
    {
      insert(str);
    }
    else
    {
      if (find(str))
      {
        printf("yes\n");
      }
      else
      {
        printf("no\n");
      }
    }
  }

  return 0;
}