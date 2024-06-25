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
  int pIdx = -1;
  int puddle[100];

  char stack[MAX_STACK_SIZE];
  int top = 0;

  char c;
  int elevation = 0;
  int done = 0;

  while (scanf("%s", c) && done == 0)
  {
    switch (c)
    {
    case '\\':
      push(top, stack, c);
      elevation--;
      break;
    case '/':
      pop(top, stack);
      tempArea += (elevation + -1);
      elevation++;
      break;
    case '_':
      break;
    case '\n':
      done = 1;
      break;
    default:
      printf("Invalid character\n");
      exit(1);
      break;
    }

    if (elevation > 0 || done == 1)
    {
      puddle[++pIdx] = tempArea;
      tot += tempArea;
      tempArea = 0;
    }
  }

  return EXIT_SUCCESS;
}