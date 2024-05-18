#include <malloc.h>
#include "creategraph.cpp"
#include <iostream>

void dfs(struct Graph* g, int source, bool* visited){
  std::cout << "->" << source;
  visited[source] = true;

  struct AdjListNode* lis = g->adjList[source].next;

  while(lis!=NULL){
    if(!visited[lis->dest]){
      dfs(g, lis->dest, visited);
    }
    lis = lis->next;
  }
}

void dfsUtil(struct Graph* g, int source){
  bool* visited = (bool*)calloc(sizeof(bool)*(g->V), false);

  struct AdjListNode* curNode = g->adjList[source].next;
  
  dfs(g, source, visited);
}