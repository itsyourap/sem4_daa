#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define V 5

int minKeyIndex(int dist[], int sptSet[])
{
  int min = INF, minIndex;
  for (int v = 0; v < V; v++)
  {
    if (!sptSet[v] && dist[v] < min)
    {
      min = dist[v];
      minIndex = v;
    }
  }
  return minIndex;
}

void printPath(int pred[], int j)
{
  if (pred[j] == -1)
  {
    printf("%c ", j + 'A');
    return;
  }
  printPath(pred, pred[j]);
  printf("-> %c ", j + 'A');
}

void printSolution(int dist[], int pred[], int src)
{
  printf("Source  Vertex  Distance  Path\n");
  for (int i = 0; i < V; i++)
  {
    printf("  %c \t %c \t   %d \t   ", src + 'A', i + 'A', dist[i]);
    printPath(pred, i);
    printf("\n");
  }
}

void dijkstra(int graph[V][V], int src)
{
  int dist[V], sptSet[V], pred[V];

  for (int i = 0; i < V; i++)
  {
    dist[i] = INF;
    sptSet[i] = 0;
    pred[i] = -1;
  }

  dist[src] = 0;

  for (int j = 0; j < V - 1; j++)
  {
    int u = minKeyIndex(dist, sptSet);
    sptSet[u] = 1;

    for (int v = 0; v < V; v++)
    {
      if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
        pred[v] = u;
      }
    }
  }

  printSolution(dist, pred, src);
}

int main()
{
  int graph[V][V] = {
      {0, 7, 0, 2, 0},
      {0, 0, 1, 2, 0},
      {0, 0, 0, 0, 4},
      {0, 3, 8, 0, 5},
      {0, 0, 5, 0, 0}};

  dijkstra(graph, 0);

  return 0;
}