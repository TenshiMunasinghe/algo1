#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

int push(int *top, char stack[*top + 1], char x)
{
  if (*top >= MAX_STACK_SIZE - 1)
  {
    printf("Memory overflow\n");
    exit(1);
  }
  (*top)++;
  stack[*top] = x;
  return stack[*top];
}

int pop(int *top, char stack[*top + 1])
{
  if (*top == 0)
  {
    printf("Memory underflow\n");
    exit(1);
  }
  (*top)--;
  return stack[*top + 1];
}

int main()
{
  int tot = 0;
  int tempArea = 0;
  int pIdx = 0;
  int puddle[100];

  char stack[MAX_STACK_SIZE];
  int top = 0;

  char s[100];
  char *c = s;
  int elevation = 0;

  scanf("%s", s);

  while (*c)
  {
    if (elevation > 0)
    {
      puddle[pIdx] = tempArea;
      tot += tempArea;
      pIdx++;
    }
    switch (*c)
    {
    case '\\':
      push(top, stack, c);
      elevation--;
      break;
    case '/':
      pop(top, stack);
      elevation++;
      break;
    case '_':
      break;
    default:
      printf("Invalid character\n");
      exit(1);
      break;
    }

    c++;
  }

  return EXIT_SUCCESS;
}