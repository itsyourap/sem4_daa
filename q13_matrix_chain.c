#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define max 100
#define inf INT_MAX

void printMatrix(int matrix[max + 1][max + 1], int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int p[max + 1];
int s[max + 1][max + 1];
int m[max + 1][max + 1];

void matrixChainOrder(int n)
{
  for (int i = 1; i <= n; i++)
    m[i][i] = 0;
  for (int len = 2; len <= n; len++)
  {
    for (int i = 1; i <= n - len + 1; i++)
    {
      int j = i + len - 1;
      m[i][j] = inf;
      for (int k = i; k < j; k++)
      {
        int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (cost < m[i][j])
        {
          m[i][j] = cost;
          s[i][j] = k;
        }
      }
    }
  }
  printf("M Matrix: \n");
  printMatrix(m, n);
  printf("S Matrix: \n");
  printMatrix(s, n);
}

void pop(int i, int j)
{
  if (i == j)
  {
    printf("A%d", i);
  }
  else
  {
    printf("(");
    pop(i, s[i][j]);
    pop(s[i][j] + 1, j);
    printf(")");
  }
}

int main()
{
  int n;
  printf("Enter number of matrices: ");
  scanf("%d", &n);
  if (n < 1 || n > max)
  {
    printf("Number of matrices must be between 1 and %d\n", max);
    return 1;
  }

  printf("Enter dimensions p0 p1 ... p%d:\n", n);
  for (int i = 0; i <= n; i++)
  {
    scanf("%d", &p[i]);
  }

  matrixChainOrder(n);
  printf("Minimum number of scalar multiplications: %d\n", m[1][n]);
  printf("Optimal parenthesization: ");
  pop(1, n);
  printf("\n");
}