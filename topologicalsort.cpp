#include<stack>
#include "creategraph.cpp"

void topologicalsort(Graph* g, int source, std::stack<int>& stk, bool* visited){
  struct AdjListNode* adjlist = g->adjList[source].next;
  visited[source] = true;

  while(adjlist!=NULL){
    if(!visited[adjlist->dest]){
      topologicalsort(g, adjlist->dest, stk, visited);
    }
    adjlist = adjlist->next;
  }

  stk.push(source);
}

void topologicalsortUtil(struct Graph* g){
  std::stack <int> stk;

  bool* visited = (bool*)calloc(sizeof(int)*(g->V), false);

  for(int i=0;i<g->V;++i)
    if(!visited[i])
      topologicalsort(g, i, stk, visited);

  while(!stk.empty()){
    int temp = stk.top();
    stk.pop();
    std::cout << "->" << temp;
  }
  std::cout << "\n";
}