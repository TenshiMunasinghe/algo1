#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void selectionSort(int n, char arr[n][3])
{
  for (int i = 0; i < n; i++)
  {
    // find max
    int minIdx = i;
    for (int j = i; j < n; j++)
    {
      int a = atoi(&arr[j][1]);
      int b = atoi(&arr[minIdx][1]);
      if (a < b)
        minIdx = j;
    }

    // swap
    if (minIdx != i)
    {
      char temp[3];
      strcpy(temp, arr[i]);
      strcpy(arr[i], arr[minIdx]);
      strcpy(arr[minIdx], temp);
    }
  }
}

void bubbleSort(int n, char arr[n][3])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < n - i; j++)
    {
      int a = atoi(&arr[j][1]);
      int b = atoi(&arr[j - 1][1]);
      if (a < b)
      {
        // swap
        char temp[3];
        strcpy(temp, arr[j - 1]);
        strcpy(arr[j - 1], arr[j]);
        strcpy(arr[j], temp);
      }
    }
  }
}

int isStable(int n, char bubbleArr[n][3], char arr[n][3])
{
  //   for (int i = 0; i < n; i++)
  //     for (int j = i + 1; j < n; j++)
  //       for (int a = 0; a < n; a++)
  //         for (int b = a + 1; b < n; b++)
  //           if (strcmp(in[i][1], in[j][1]) == 0 && strcmp(in[i], out[b]) == 0 && strcmp(in[j], out[a]) == 0)
  //             return 0;
  //   return 1;

  // compare with bubble sort result
  for (int i = 0; i < n; i++)
  {
    if (strcmp(bubbleArr[i], arr[i]) != 0)
      return 0;
  }
  return 1;
};

void printArr(int n, char arr[n][3]);

int main()
{
  int n;
  scanf("%d", &n);

  char bubbleArr[n][3], selectionArr[n][3];
  for (int i = 0; i < n; i++)
  {
    char input[3];
    scanf("%3s", input);
    strcpy(bubbleArr[i], input);
    strcpy(selectionArr[i], input);
  }

  bubbleSort(n, bubbleArr);
  selectionSort(n, selectionArr);

  printArr(n, bubbleArr);
  printf("Stable\n");

  printArr(n, selectionArr);
  if (isStable(n, bubbleArr, selectionArr) == 0)
  {
    printf("Not stable\n");
  }
  else
  {
    printf("Stable\n");
  }

  return EXIT_SUCCESS;
}

void printArr(int n, char arr[n][3])
{
  for (int i = 0; i < n - 1; i++)
  {
    printf("%s ", arr[i]);
  }
  printf("%s\n", arr[n - 1]);
}