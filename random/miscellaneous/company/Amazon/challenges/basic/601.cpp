// Kth largest element using max-heap
#include<iostream>
#include<stdio.h>
using namespace std;

#define INT_MAX 0x3f3f3f3f
void swap(int *x, int *y);

class MaxHeap
{
  int *harr;
  int capacity;
  int heap_size;
public:
  MaxHeap(int capacity);
  void MaxHeapify(int);
  int parent(int i) {return (i-1)/2;}
  int left(int i) {return 2*i+1;}
  int right(int i) {return 2*i+2;}
  int getMax() {return harr[0];}
  int extractMax();
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
    return;

  heap_size++;
  int i=heap_size-1;
  harr[i]=k;
  while (i!=0 && harr[parent(i)]<harr[i])
  {
    swap(&harr[parent(i)],&harr[i]);
    i=parent(i);
  }
}

int MaxHeap::extractMax()
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
  if (r<heap_size && harr[r]>harr[largest])
    largest=r;
  if (largest!=i)
  {
    swap(&harr[largest],&harr[i]);
    MaxHeapify(largest);
  }
}

void swap(int *x, int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}


int main()
{
  //
  // int t;
  // cin >> t;
  // while (t--){
    int n, k, temp;
    cin >> n >> k;
    MaxHeap h(n);
    while (n--){
      cin >> temp;
      h.insertKey(temp);
    }
    while (k--)
      cout << h.extractMax() << endl;
  // }
  return 0;
}
