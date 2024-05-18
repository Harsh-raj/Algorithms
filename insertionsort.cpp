
#include<iostream>

void insertionsort(int* arr, int size){
  int i=1,j;
  while(i<size){
    int min = arr[i];
    j=i-1;
    while(j>=0 && arr[j]>min){
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = min;
    ++i;
  }
}