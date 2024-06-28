#include <stdlib.h>
#include <stdio.h>

#define MAX_STACK_SIZE 200

int push(int *top, int stack[*top + 1], int x)
{
  if (*top >= MAX_STACK_SIZE - 1)
  {
    printf("Memory overflow\n");
    exit(1);
  }
  (*top)++;
  stack[*top] = x;
  // printf("%d %d\n", *top, stack[*top]);
  return stack[*top];
}

int pop(int *top, int stack[*top + 1])
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
  int stack[MAX_STACK_SIZE];
  int top = 0;
  char s[100];
  char c;

  while (scanf("%s%c", s, &c) != EOF)
  {
    // printf("%c\n", s[0]);
    if (s[0] == '+')
    {
      int x = pop(&top, stack);
      x = pop(&top, stack) + x;

      push(&top, stack, x);
    }
    else if (s[0] == '-')
    {
      int x = pop(&top, stack);
      x = pop(&top, stack) - x;

      push(&top, stack, x);
    }
    else if (s[0] == '*')
    {
      int x = pop(&top, stack);
      x = pop(&top, stack) * x;

      push(&top, stack, x);
    }
    else
    {
      push(&top, stack, atoi(&s[0]));
    }
    if (c == '\n')
      break;
  }

  printf("%d\n", pop(&top, stack));

  return EXIT_SUCCESS;
}
