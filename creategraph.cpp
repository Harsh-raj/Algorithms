#include<stdlib.h>
#include<iostream>

struct Graph{
  int V;
  struct AdjList* adjList;
};

struct AdjList{
  struct AdjListNode* next;
};

struct AdjListNode{
  int dest;
  int dist;
  struct AdjListNode* next;
};

struct AdjListNode* createAdjListNode(int dest, int dist){
  struct AdjListNode* temp = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
  temp->dist = dist;
  temp->dest = dest;
  temp->next = nullptr;
  return temp;
}

struct Graph* createGraph(int V){
  struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
  g->V = V;
  g->adjList = (struct AdjList*)malloc(sizeof(struct AdjList)*V);
  for (int i = 0; i < V; ++i) {
    g->adjList[i].next = nullptr;
  }
  return g;
}

struct Graph* populateGraph(){
  std::cout << "Creating Graph...\n";
  std::cout << "Number of Vertices: ";
  int V;
  std::cin >> V;
  
  Graph* g = createGraph(V);
  
  int E;
  std::cout << "Enter the number of Edges here: ";
  std::cin >> E;
  std::cout << "Enter all the edges of graph in following format: source vertex, destination vertex, weight\n";
  while(E--){
    int source, destination, weight;
    std::cin >> source >> destination >> weight;
    struct AdjListNode* newNode = createAdjListNode(destination, weight);
    newNode->next = g->adjList[source].next;
    g->adjList[source].next = newNode;
  }
  return g;
}

void printGraph(struct Graph* g){
  int i=0;
  while(i<g->V){
    struct AdjListNode* cur = g->adjList[i].next;
    std::cout << "Vertex "<<i<< ": ";
    while(cur!=NULL){
      std::cout << cur->dest<<": "<<cur->dist<<", ";
      cur = cur->next;
    }
    std::cout << "\n";
    ++i;
  }
}