#include<iostream>
#include<stdio.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
  int *harr;
  int capacity;
  int heap_size;
public:
  MinHeap(int capacity);
  void MinHeapify(int);
  int parent(int i) {return (i-2)/2;}
  int left(int i) {return 2*i+1;}
  int right(int i) {return 2*i+2;}
  int extractMin();
  void decreaseKey(int i,int new_val);
  int getMin() {return harr[0];}
  void deleteKey(int i);
  void insertKey(int k);
};

MinHeap::MinHeap(int cap){
  heap_size=0;
  capacity=cap;
  harr=new int[cap];
}

void MinHeap::insertKey(int k)
{
  if (heap_size==capacity)
  {
    cout<<"\n Overflow: Could not resolve insertKey \n";
    return;
  }
  heap_size++;
  int i=heap_size-1;
  harr[i]=k;
  while (i!=0 && harr[parent(i)]>harr[i])
  {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
  }
}

void MinHeap::extractMin()
{
    if (heap_size<=0)
      return INT_MAZX;
    if (heap_size==1)
    {
      heap_size--;
      return harr[0];
    }

    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i)
{
  int l=left(i);
  int r=right(i);
  int smallest=i;
  if (l<heap_size && harr[l]<harr[i])
    smallest=l;
  if (r<heap_size && harr[r]<harr[i])
    smallest=r;
  if (smallest!=i)
  {
    swap(&harr[smallest],&harr[i]);
    MinHeapify(smallest);
  }
}
