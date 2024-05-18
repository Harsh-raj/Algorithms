#include<queue>
#include<malloc.h>

#include "creategraph.cpp"

void bfs(struct Graph* g, int source, bool* visited){
  std::queue<int> q;
  q.push(source);
  visited[source] = false;
  
  while(!q.empty()){
    int cur = q.front();
    q.pop();

    std::cout << "->" << cur;
    struct AdjListNode* curr = g->adjList[cur].next;
    while(curr!= NULL){
      if(!visited[curr->dest])
        q.push(curr->dest);
      curr = curr->next;
    }
  }

}

void bfsUtil(struct Graph* g, int source){
  std::queue <AdjListNode> nodes;
  bool* visited = (bool*)calloc(sizeof(bool)*g->V, false);

  bfs(g, source, visited);
}