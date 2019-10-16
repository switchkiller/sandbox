// Find the kth minimum element in an array
#include<iostream>

#define N 100

using namespace std;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int l, int h){
  int firsthigh = h;
  int pIndex = l;
  for (int i = l; i <= h; i++){
    if (arr[i] < arr[firsthigh]){
      swap(&arr[i], &arr[pIndex]);
      pIndex++;
    }
  }
  swap(&arr[firsthigh], &arr[pIndex]);
  return pIndex;
}

void findKthSmallest(int arr[], int l, int h, int k){
  if (l < h){
    int pIndex = partition(arr, l, h);
    if (pIndex == k-1)
      cout << arr[pIndex];
    findKthSmallest(arr, l, pIndex-1, k);
    findKthSmallest(arr, pIndex+1, h, k);
  }
}

int main(){
    int n, k;
    int arr[N];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    findKthSmallest(arr, 0, n-1, k);
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    return 0;
}
