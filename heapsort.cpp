void heapify(int* arr, int size, int i){
  int left = 2*i+1;
  int right = 2*i+2;
  int largest = i;

  if(left < size && arr[largest] < arr[left])
    largest = left;
  
  if(right < size && arr[largest] < arr[right])
    largest = right;

  if(largest!=i){
    int temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;

    heapify(arr, size, largest);
  }
}

void heapsort(int* arr, int size){
  for(int i=size/2-1; i>=0; --i){
    heapify(arr, size, i);
  }

  for(int i=size-1; i>=0; --i){
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;

    heapify(arr, i, 0);
  }
}