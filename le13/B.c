#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define N (SIZE * SIZE)
#define MAX_DEPTH 100

int goal[N] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

int isGoal(int board[N])
{
  for (int i = 0; i < N; i++)
  {
    if (board[i] != goal[i])
    {
      return 0;
    }
  }
  return 1;
}

int isSolvable(int board[N])
{
  int inversions = 0;
  for (int i = 0; i < N; i++)
  {
    if (board[i] == 0)
      continue;
    for (int j = i + 1; j < N; j++)
    {
      if (board[j] == 0)
        continue;
      if (board[i] > board[j])
        inversions++;
    }
  }
  return inversions % 2 == 0;
}

int solve(int board[N], int blankPos, int g, int maxDepth, int prevMove)
{
  if (g > maxDepth)
    return 0;
  if (isGoal(board))
    return g;

  int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int moveIdx[4] = {1, -1, 2, -2};
  int solved = 0;
  int minSteps = MAX_DEPTH;

  for (int i = 0; i < 4; i++)
  {
    if (moveIdx[i] == -prevMove)
      continue; // Avoid going back to the previous state
    int newBlankRow = blankPos / SIZE + moves[i][0];
    int newBlankCol = blankPos % SIZE + moves[i][1];
    if (newBlankRow >= 0 && newBlankRow < SIZE && newBlankCol >= 0 && newBlankCol < SIZE)
    {
      int newBlankPos = newBlankRow * SIZE + newBlankCol;

      // Swap blank with the new position
      int temp = board[blankPos];
      board[blankPos] = board[newBlankPos];
      board[newBlankPos] = temp;

      int result = solve(board, newBlankPos, g + 1, maxDepth, moveIdx[i]);

      // Undo the move
      temp = board[blankPos];
      board[blankPos] = board[newBlankPos];
      board[newBlankPos] = temp;

      if (result > 0)
      {
        if (result < minSteps)
          minSteps = result;
        solved = 1;
      }
    }
  }

  return solved ? minSteps : 0;
}

int main()
{
  int board[N];
  int blankPos;

  printf("Enter the initial board configuration (row-wise, use 0 for blank space):\n");
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &board[i]);
    if (board[i] == 0)
    {
      blankPos = i;
    }
  }

  if (!isSolvable(board))
  {
    printf("The puzzle is not solvable.\n");
    return 0;
  }

  int minSteps = MAX_DEPTH;
  int maxDepth = 0;

  while (minSteps == MAX_DEPTH)
  {
    minSteps = solve(board, blankPos, 0, maxDepth, 0);
    maxDepth++;
  }

  printf("Number of steps: %d\n", minSteps);

  return 0;
}
