#include<iostream>

#define INT_MAX 0x3f3f3f3f
using namespace std;

class MaxHeap{
  int *arr;
  int count;
  int size;

public:
  MaxHeap(int n);
  void insertKey(int n);
  void MaxHeapify(int h);
  int extractMax();
  int left(int i){return (2*i+1);}
  int right(int i){return (2*i+2);}
  int parent(int i){return (i-1)/2;}
};

MaxHeap::MaxHeap(int n){
  arr = new int[n];
  int size = n;
  int count = 0;
}

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void MaxHeap::insertKey(int n){
  if (count == size)
    return;
  count++;
  int i = count - 1;
  arr[i] = n;
  while (i != 0 && arr[parent(i)] < arr[i]){
    swap(&arr[parent(i)], &arr[i]);
    i = parent(i);
  }
}


void MaxHeap::MaxHeapify(int n){
  int l = left(n);
  int r = right(n);
  int largest = n;
  if (l < size && arr[l] > arr[largest])
    largest = l;
  if (r < size && arr[r] > arr[largest])
    largest = r;
  if (n != largest){
    swap(&arr[largest], &arr[n]);
    MaxHeapify(largest);
  }
}

int MaxHeap::extractMax(){
  if (size <= 0)
    return INT_MAX;

  if (size == 1){
    size--;
    return arr[0];
  }

  int root = arr[0];
  arr[0] = arr[size-1];
  size--;
  MaxHeap(0);
  return root;
}




int main(){
  int n, x, k;
  cin >> n;
  MaxHeap h(n);
  for (int i = 0; i < n; i++){
    cin >> x;
    h.insertKey(x);
  }
  cin >> k;
  for (int i = 0; i < k; i++)
    cout<<h.extractMax() <<" ";

  return 0;
}
