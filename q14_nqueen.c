#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX];
int count = 0;

int placed(int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    if (board[i] == col || abs(board[i] - col) == abs(i - row))
    {
      return 0;
    }
  }
  return 1;
}

void printSolution(int n)
{
  count++;
  printf("Solution %d:\n", count);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i] == j)
        printf(" Q ");
      else
        printf(" . ");
    }
    printf("\n");
  }
  printf("\n");
}

void nQueen(int row, int n)
{
  if (row == n)
  {
    printSolution(n);
    return;
  }

  for (int col = 0; col < n; col++)
  {
    if (placed(row, col))
    {
      board[row] = col;
      nQueen(row + 1, n);
    }
  }
}

int main()
{
  int n;

  printf("Enter the value of N for N-Queen problem: ");
  scanf("%d", &n);

  if (n <= 0 || n > MAX)
  {
    printf("Invalid value of N. Please enter between 1 and %d.\n", MAX);
    return 1;
  }

  nQueen(0, n);

  if (count == 0)
    printf("No solutions found for N = %d\n", n);
}