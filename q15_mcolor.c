#include <stdio.h>

#define MAX 20

int G[4][4] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0}};

int x[MAX];
int n = 4;
int m;
int count = 0;

void printSolution()
{
  count++;
  printf("Solution %d: ", count);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", x[i]);
  }
  printf("\n");
}

int nextValue(int k)
{
  while (1)
  {
    x[k] = (x[k] + 1) % (m + 1);
    if (x[k] == 0)
      return 0;

    int j;
    for (j = 0; j < n; j++)
    {
      if (G[k][j] == 1 && x[k] == x[j])
        break;
    }

    if (j == n)
      return 1;
  }
}

void mColoring(int k)
{
  while (nextValue(k))
  {
    if (k == n - 1)
      printSolution();
    else
      mColoring(k + 1);
  }
}

int main()
{
  printf("Enter the number of colors: ");
  scanf("%d", &m);
  for (int i = 0; i < n; i++)
    x[i] = 0;
  mColoring(0);
  if (count == 0)
    printf("No valid coloring exists with %d colors.\n", m);
}