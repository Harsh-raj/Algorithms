#include<malloc.h>

void merge(int* arr, int l, int m, int r){
  int i=0, j=0, k=l;
  
  int sizea = m-l+1;
  int sizeb = r-m;
  int* a = (int*)malloc(sizeof(int)*sizea);
  int* b = (int*)malloc(sizeof(int)*sizeb);

  for(int i=0;i<sizea;++i)
    a[i] = arr[i+l];

  for(int i=0;i<sizeb;++i)
    b[i] = arr[i+m+1];

  while(i<sizea && j<sizeb){
    if(a[i] < b[j]){
      arr[k++] = a[i++];
    }else{
      arr[k++] = b[j++];
    }
  }

  while(i<sizea){
    arr[k++] = a[i++];
  }

  while(j<sizeb){
    arr[k++] = b[j++];
  }
}

void mergesort(int* arr, int l, int r){
  if(l<r){
    int m = l+(r-l)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}