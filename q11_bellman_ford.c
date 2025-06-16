#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 5
#define E 8

typedef struct Edge
{
  int src, dest, weight;
} Edge;

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
  printf("Source Vertex Distance Path\n");
  for (int i = 0; i < V; i++)
  {
    printf(" %c \t %c \t %d \t ", src + 'A', i + 'A', dist[i]);
    printPath(pred, i);
    printf("\n");
  }
}

void bellmanFord(Edge edges[], int src)
{
  int dist[V], pred[V];

  for (int i = 0; i < V; i++)
  {
    dist[i] = INF;
    pred[i] = -1;
  }

  dist[src] = 0;
  for (int i = 0; i < V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = edges[j].src;
      int v = edges[j].dest;
      int weight = edges[j].weight;
      if (dist[u] != INF && dist[u] + weight < dist[v])
      {
        dist[v] = dist[u] + weight;
        pred[v] = u;
      }
    }
  }

  for (int i = 0; i < E; i++)
  {
    int u = edges[i].src;
    int v = edges[i].dest;
    int weight = edges[i].weight;
    if (dist[u] != INF && dist[u] + weight < dist[v])
    {
      printf("Negative-weight cycle detected\n");
      return;
    }
  }

  printSolution(dist, pred, src);
}

int main()
{
  Edge edges[E] = {
      {0, 1, -1},
      {0, 2, 4},
      {1, 2, 3},
      {1, 3, 2},
      {1, 4, 2},
      {3, 2, 5},
      {3, 1, 1},
      {4, 3, -3}};

  bellmanFord(edges, 0);

  return 0;
}
