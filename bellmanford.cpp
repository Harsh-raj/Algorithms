#include "creategraph.cpp"

void printArr(int dist[], int n)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src
// to all other vertices using Bellman-Ford algorithm.  The
// function also detects negative weight cycle
void BellmanFord(struct Graph *graph, int src)
{
  int V = graph->V;
  // int E = Edges;
  int dist[V];

  // Step 1: Initialize distances from src to all other
  // vertices as INFINITE
  for (int i = 0; i < V; i++)
    dist[i] = 9999;
  dist[src] = 0;

  // Step 2: Relax all edges |V| - 1 times. A simple
  // shortest path from src to any other vertex can have
  // at-most |V| - 1 edges
  for (int i = 1; i <= V - 1; i++)
  {
    // for (int j = 0; j < E; j++) {
    //     int u = graph->edge[j].src;
    //     int v = graph->edge[j].dest;
    //     int weight = graph->edge[j].weight;
    //     if (dist[u] != INT_MAX
    //         && dist[u] + weight < dist[v])
    //         dist[v] = dist[u] + weight;
    // }
    for (int j = 0; j <= V - 1; ++j)
    {
      int u = j;
      struct AdjListNode *curnode = graph->adjList[u].next;
      while (curnode != NULL)
      {
        int v = curnode->dest;
        int w = curnode->dist;
        if (dist[u] != 9999 && (dist[u] + w < dist[v]))
          dist[v] = dist[u] + w;
        curnode = curnode->next;
      }
    }
  }

  // Step 3: check for negative-weight cycles.  The above
  // step guarantees shortest distances if graph doesn't
  // contain negative weight cycle.  If we get a shorter
  // path, then there is a cycle.
  for (int j = 0; j <= V - 1; ++j)
  {
    int u = j;
    struct AdjListNode *curnode = graph->adjList[u].next;
    while (curnode != NULL)
    {
      int v = curnode->dest;
      int w = curnode->dist;
      if (dist[u] != 9999 && (dist[u] + w < dist[v]))
        dist[v] = dist[u] + w;
      curnode = curnode->next;
    }
  }

  printArr(dist, V);

  return;
}