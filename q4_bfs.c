#include <stdio.h>
#include <limits.h>

#define V 5
#define max 20

int visited[V];
int rear = -1, front = -1;
int queue[V];

void enqueue(int item)
{
  if (rear == max - 1)
    return;
  queue[++rear] = item;
}

int dequeue()
{
  if (front == rear)
    return INT_MIN;
  return queue[++front];
}

void bfs(int graph[V][V], int src)
{
  for (int i = 0; i < V; i++)
    visited[i] = 0;
  visited[src] = 1;

  enqueue(src);
  
  while (front < rear)
  {
    int u = dequeue();
    printf("%c  ", u + 'A');
    for (int w = 0; w < V; w++)
    {
      if (graph[u][w] == 1 && !visited[w])
      {
        visited[w] = 1;
        enqueue(w);
      }
    }
  }
  printf("\n");
}

int main()
{
  int graph[V][V] = {
      {0, 1, 1, 0, 0},
      {1, 0, 1, 1, 0},
      {1, 1, 0, 1, 1},
      {0, 1, 1, 0, 0},
      {0, 0, 1, 0, 0}};

  bfs(graph, 0);
}