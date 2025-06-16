#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 6

int minKey(int key[], int mstSet[])
{
  int min = INF, minIndex;
  for (int v = 0; v < V; v++)
  {
    if (!mstSet[v] && key[v] < min)
    {
      min = key[v];
      minIndex = v;
    }
  }
  return minIndex;
}

void printSolution(int key[], int parent[], int src)
{
  int cost = 0;
  printf("Edge \t Weight \n");
  for (int i = 1; i < V; i++)
  {
    printf("%c - %c \t   %d", parent[i] + 'A', i + 'A', key[i]);
    printf("\n");
    cost += key[i];
  }
  printf("Minimum Cost: %d\n", cost);
}

void prims(int graph[V][V], int src)
{
  int key[V], mstSet[V], parent[V];

  for (int i = 0; i < V; i++)
  {
    key[i] = INF;
    mstSet[i] = 0;
    parent[i] = -1;
  }

  key[src] = 0;

  for (int j = 0; j < V - 1; j++)
  {
    int u = minKey(key, mstSet);
    mstSet[u] = 1;

    for (int v = 0; v < V; v++)
    {
      if (!mstSet[v] && graph[u][v] && key[u] != INF && graph[u][v] < key[v])
      {
        key[v] = graph[u][v];
        parent[v] = u;
      }
    }
  }

  printSolution(key, parent, src);
}

int main()
{
  int graph[V][V] = {
      {0, 7, INF, 8, INF, INF},
      {7, 0, 6, 3, INF, INF},
      {INF, 6, 0, 4, 2, 5},
      {8, 3, 4, 0, 3, INF},
      {INF, INF, 2, 3, 0, 2},
      {INF, INF, 5, INF, 2, 0}};

  prims(graph, 0);

  return 0;
}