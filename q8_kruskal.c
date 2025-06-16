#include <stdio.h>
#include <limits.h>

#define V 6
#define E 9

typedef struct
{
  int vertex1;
  int vertex2;
  int weight;
} Edge;

int parent[V];

int find(int i)
{
  while (parent[i] > 0)
    i = parent[i];
  return i;
}

void unionSet(int i, int j)
{
  int a = find(i);
  int b = find(j);
  parent[a] = b;
}

void merge(Edge edges[], int low, int mid, int high)
{
  Edge temp[100];
  int i = low, j = mid + 1, k = low;
  while (i <= mid && j <= high)
  {
    if (edges[i].weight <= edges[j].weight)
      temp[k++] = edges[i++];
    else
      temp[k++] = edges[j++];
  }

  while (i <= mid)
    temp[k++] = edges[i++];
  while (j <= high)
    temp[k++] = edges[j++];

  for (i = low; i <= high; i++)
    edges[i] = temp[i];
}

void mergeSort(Edge edges[], int low, int high)
{
  if (low < high)
  {
    int mid = low + (high - low) / 2;
    mergeSort(edges, low, mid);
    mergeSort(edges, mid + 1, high);
    merge(edges, low, mid, high);
  }
}

void makeSet(int i)
{
  parent[i] = -1;
}

void kruskal(Edge edges[])
{
  int i, minCost = 0;
  for (i = 0; i < V; i++)
    makeSet(i);
  mergeSort(edges, 0, E - 1);

  printf("Edge \tWeight\n");

  for (i = 0; i < E; i++)
  {
    int u = edges[i].vertex1;
    int v = edges[i].vertex2;
    int weight = edges[i].weight;

    if (find(u) != find(v))
    {
      printf("%c - %c \t%d\n", u + 'A', v + 'A', weight);
      minCost += weight;
      unionSet(u, v);
    }
  }
  printf("Minimum Cost: %d\n", minCost);
}

int main()
{
  Edge edges[E] = {
      {0, 1, 7}, {0, 3, 8}, {1, 2, 6}, {1, 3, 3}, {2, 3, 4}, {2, 4, 2}, {2, 5, 5}, {3, 4, 3}, {4, 5, 2}};

  kruskal(edges);
  return 0;
}