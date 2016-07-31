// Kth largest element using max-heap
#include<iostream>
#include<stdio.h>
using namespace std;

void swap(int *x, int *y);

class MaxHeap
{
  int *harr;
  int capacity;
  int heap_size;
public:
  MaxHeap(int capacity);
  void MaxHeapify(int);
  int parent(int i) {return (i-2)/2;}
  int left(int i) {return 2*i+1;}
  int right(int i) {return 2*i+2;}
  int getMax() {return harr[0];}
  int extractMax();
  void deleteKey(int i);
  void insertKey(int k);
};

MaxHeap::MaxHeap(int cap){
  heap_size=0;
  capacity=cap;
  harr=new int[cap];
}

void MaxHeap::insertKey(int k)
{
  if (heap_size==capacity)
  {
    cout<<"\n Overflow: Could not resolve insertKey \n";
    return;
  }
  heap_size++;
  int i=heap_size-1;
  harr[i]=k;
  while (i!=0 && harr[parent(i)]<harr[i])
  {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
  }
}

void MaxHeap::extractMax()
{
    if (heap_size<=0)
      return INT_MAX;
    if (heap_size==1)
    {
      heap_size--;
      return harr[0];
    }

    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);
    return root;
}

void MaxHeap::MaxHeapify(int i)
{
  int l=left(i);
  int r=right(i);
  int largest=i;
  if (l<heap_size && harr[l]>harr[i])
    largest=l;
  if (r<heap_size && harr[r]>harr[i])
    largest=r;
  if (largest!=i)
  {
    swap(&harr[largest],&harr[i]);
    MaxHeapify(largest);
  }
}

// void MaxHeap::deleteKey(int i){
//   decreaseKey(i,INT_Max);
//   extract();
// }

void swap(int *x, int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}
//
int main()
{
  MaxHeap h(11);
  h.insertKey(3);
  h.insertKey(3);
  h.deleteKey(1);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  cout<<h.extractMax()<<" ";
  cout<<h.getMax()<< " ";
  cout<<h.getMax();
  return 0;
}
