 // Given two arrays of numbers. The numbers are from 0-9 you have two maximize the first array by using the elements from the second array.

#include<stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high){
  int p = high;
  int pIndex = low;
  for (int i = low; i < high; i++)
    if (arr[i] < arr[p]){
      swap(&arr[i], &arr[pIndex]);
      pIndex++;
  }
  swap(&arr[p], &arr[pIndex]);
  return pIndex;
}

void quicksort(int arr[],int low, int high){
  if (low < high){
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
  }
}

int main(){
  int i, b, c;
  i = b = 0;
  int arr1[] = {5, 2, 3, 6, 7};
  int arr2[] = {9, 2, 8, 4, 5};
  int n1 = sizeof(arr1)/sizeof(arr1[0]) - 1;
  int n2 = sizeof(arr2)/sizeof(arr2[0]) - 1;
  c = n2 -1;
  quicksort(arr1,0,n1);
  quicksort(arr2,0,n2);
  for (i = 0; i < n1; i++)
    printf("%d ", arr1[i]);
  for (i = 0; i < n2; i++)
    printf("%d ", arr2[i]);
  // while (i < n1){
  //   if (arr1[b] < arr2[c]){
  //     arr1[b] = arr2[c];
  //     b++, c--;
  //   }
  //   else break;
  // }
  // for (i = 0; i < n1; i++)
  //   printf("%d", arr1[i]);
}
