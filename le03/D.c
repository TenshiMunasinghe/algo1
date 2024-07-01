#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20000

int min(int a, int b)
{
  return (a < b) ? a : b;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

void printArr(int n, int *arr)
{
  for (int i = 0; i < n; i++)
    printf(" %d", arr[i]);
}

void calculate_flooded_areas(char *terrain, int *totalArea, int *floodCount, int *floodAreas)
{
  int len = strlen(terrain);

  // generate height map
  int heights[len];
  int waterLevels[len];

  heights[0] = 0;
  int hasIncrement = 0;
  for (int i = 0; i < len; i++)
  {
    if (terrain[i] == '\\')
      heights[i + 1] = heights[i] - 1;
    else if (terrain[i] == '/')
    {
      heights[i + 1] = heights[i] + 1;
      hasIncrement = 1;
    }
    else // '_'
      heights[i + 1] = heights[i];
  }

  if (hasIncrement == 0)
  {
    return;
  }

  // water level at the point is the min of left peak and right peak
  int leftMax = heights[0];
  for (int i = 0; i <= len; i++)
  {
    leftMax = max(leftMax, heights[i]);
    waterLevels[i] = leftMax;
  }

  int rightMax = heights[len - 1];
  for (int i = len; i >= 0; i--)
  {
    rightMax = max(rightMax, heights[i]);
    waterLevels[i] = min(waterLevels[i], rightMax);
  }

  *totalArea = 0;
  *floodCount = 0;
  int currentFlood = 0;

  // printArr(len, heights);
  // printArr(len, waterLevels);

  for (int i = 0; i <= len; i++)
  {
    if (waterLevels[i] > heights[i])
    {
      currentFlood += waterLevels[i] - heights[i];
    }
    else if (currentFlood > 0)
    {
      floodAreas[*floodCount] = currentFlood;
      *totalArea += currentFlood;
      (*floodCount)++;
      currentFlood = 0;
    }
  }
}

int main()
{
  char terrain[MAX_LENGTH + 1];
  int totalArea, floodCount;
  int floodAreas[MAX_LENGTH];

  scanf("%s", terrain);

  calculate_flooded_areas(terrain, &totalArea, &floodCount, floodAreas);

  printf("%d\n", totalArea);
  printf("%d", floodCount);
  printArr(floodCount, floodAreas);
  printf("\n");
  return 0;
}