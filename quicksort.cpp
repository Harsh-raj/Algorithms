int partition(int* arr, int l, int r){
  int pivot = arr[l];
  int i=l+1, j=r;
  while(i<=j){
    if(arr[i] > pivot && arr[j] < pivot){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      ++i;
      --j;
    }
    else if(arr[i] < pivot){
      ++i;
    }else if(arr[j] > pivot){
      --j;
    }
  }

  arr[l] = arr[j];
  arr[j] = pivot;
  return j;
}

void quicksort(int* arr, int l, int r){
  if(l<r){
    int pivot = partition(arr, l, r);
    quicksort(arr, l, pivot-1);
    quicksort(arr, pivot+1, r);
  }
}