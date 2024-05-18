#include<malloc.h>

struct MinHeapNode{
  int v;
  int dist;
};

struct MinHeap{
  int size;
  int capacity;
  int* pos;
  struct MinHeapNode** node;
};

struct MinHeap* createMinHeap(int capacity){
  struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  minHeap->node = (struct MinHeapNode**)malloc(sizeof(struct MinHeapNode*)*capacity);
  minHeap->capacity = capacity;
  minHeap->size = 0;
  minHeap->pos = (int*)malloc(sizeof(int)*capacity);
  // for(int i=0;i<capacity;++i){
  //   minHeap->pos[i] = i;
  // }
  return minHeap;
}

struct MinHeapNode* createMinHeapNode(int src, int dist){
  struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
  node->dist = dist;
  node->v = src;
  return node;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
  struct MinHeapNode* temp = *a;
  *a = *b;
  *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int curMinHeapNode){
  int left = 2*curMinHeapNode+1;
  int right = 2*curMinHeapNode+2;
  int smallest = curMinHeapNode;

  if(left < minHeap->size && minHeap->node[left]->dist < minHeap->node[smallest]->dist)
    smallest = left;

  if(right < minHeap->size && minHeap->node[right]->dist < minHeap->node[smallest]->dist)
    smallest = right;

  if(smallest != curMinHeapNode){

    int smallestvertex = minHeap->node[smallest]->v;
    int currentvertex = minHeap->node[curMinHeapNode]->v;

    minHeap->pos[smallestvertex] = curMinHeapNode;
    
    minHeap->pos[currentvertex] = smallest;

    swapMinHeapNode(&minHeap->node[smallest], &minHeap->node[curMinHeapNode]);

    minHeapify(minHeap, smallest);
  }
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap){
  if(minHeap->size == 0) return NULL;
  struct MinHeapNode* root = minHeap->node[0];
  struct MinHeapNode* lastNode = minHeap->node[minHeap->size-1];

  minHeap->node[0] = lastNode;

  minHeap->pos[root->v] = minHeap->size-1;
  minHeap->pos[lastNode->v] = 0;

  --minHeap->size;

  //swapMinHeapNode(&root, &lastNode);

  minHeapify(minHeap, 0);
  return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist){
    // Get the index of v in  heap array
    int i = minHeap->pos[v];
 
    // Get the node and update its dist value
    minHeap->node[i]->dist = dist;
 
    // Travel up while the complete 
    // tree is not heapified.
    // This is a O(Logn) loop
    while (i && minHeap->node[i]->dist < minHeap->node[(i - 1) / 2]->dist)
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->node[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->node[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->node[i], &minHeap->node[(i - 1) / 2]);
 
        // move to parent index
        i = (i - 1) / 2;
    }
}

bool isEmptyMinHeap(struct MinHeap* minHeap){
  return minHeap->size==0;
}

bool isInMinHeap(struct MinHeap* minHeap, int v){
  return minHeap->pos[v] < minHeap->size;
}