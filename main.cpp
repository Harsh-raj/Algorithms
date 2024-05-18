#include <iostream>
#include "bellmanford.cpp"

int main(){
  // std::cout << "Mergesort" << std::endl;
  // std::cout << "Enter the number of elements here: ";
  // int size;
  // std::cin >> size;
  // std::cout << "Enter the elements in the array: ";
  // int* input = (int*)malloc(sizeof(int)*size);
  // for(int i=0;i<size;++i)
  //   std::cin >> input[i];
  // heapsort(input, size);
  // for(int i=0;i<size;++i){
  //   std::cout << input[i] << " ";
  // }

  Graph* g = populateGraph();
  BellmanFord(g, 0); 
  //printGraph(g);
  return 0;
}