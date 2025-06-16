#include <stdio.h>
#include <limits.h>
#define V 5
#define inf INT_MAX

int dist[V][V];
int pred[V][V];

void initialize(int graph[V][V])
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      dist[i][j] = graph[i][j];
      if (i != j && graph[i][j] != inf)
        pred[i][j] = i;
      else
        pred[i][j] = -1;
    }
  }
}

void printMatrix(int dist[V][V])
{
  printf("Shortest distances between every pair of vertices:\n");
  for (int i = 0; i < V; i++)
  {
    printf("%7c", i + 'A');
  }
  printf("\n");
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (dist[i][j] == inf)
        printf("%7s", "INF");
      else
        printf("%7d", dist[i][j]);
    }
    printf("\n");
  }
}

void floyd(int graph[V][V])
{
  initialize(graph);

  for (int k = 0; k < V; k++)
  {
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (dist[i][k] == inf || dist[k][j] == inf)
          continue;
        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          pred[i][j] = pred[k][j];
        }
      }
    }
  }
  printMatrix(dist);
}

void APSP(int i, int j)
{
  if (i == j)
    printf("%c", i + 'A');
  else if (pred[i][j] == -1)
  {
    printf("No Path exist between %c to %c.\n", i + 'A', j + 'A');
  }
  else
  {
    APSP(i, pred[i][j]);
    printf(" -> %c ", j + 'A');
  }
}

int main()
{
  int graph[V][V] = {
      {0, 7, inf, 2, inf},
      {inf, 0, 1, 2, inf},
      {inf, inf, 0, inf, 4},
      {inf, 3, 8, 0, 5},
      {inf, inf, 5, inf, 0}};

  floyd(graph);

  printf("\nAll Pairs Shortest Paths:\n\n");
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (i != j)
      {
        if (dist[i][j] == inf)
        {
          printf("No path from %c to %c\n", i + 'A', j + 'A');
          printf("\n");
        }
        else
        {
          printf("Cost from %c to %c: %d\n", i + 'A', j + 'A', dist[i][j]);
          printf("Path: ");
          APSP(i, j);
          printf("\n\n");
        }
      }
    }
  }
}