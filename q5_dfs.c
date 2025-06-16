#include <stdio.h>
#include <limits.h>

#define V 5
#define max 20

int visited[V];
int top = -1;
int stack[V];

void push(int item)
{
  if (top == max - 1)
    return;
  stack[++top] = item;
}

int pop()
{
  if (top == -1)
    return INT_MIN;
  return stack[top--];
}

void bfs(int graph[V][V], int src)
{
  for (int i = 0; i < V; i++)
    visited[i] = 0;
  visited[src] = 1;

  push(src);
  
  while (top > -1)
  {
    int u = pop();
    printf("%c  ", u + 'A');
    for (int w = 0; w < V; w++)
    {
      if (graph[u][w] == 1 && !visited[w])
      {
        visited[w] = 1;
        push(w);
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