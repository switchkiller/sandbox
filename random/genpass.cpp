//Generate N number of Password of length M each
#include<iostream>
#include<stdlib.h>

using namespace std;

void permute(int*,int,int);

int main(int argc, char **argv){
  // m is length
  int m;
  cin >> m;
  int *a = (int *) malloc(m*sizeof(int));
  for (int i = 0; i < m; i++){
    a[i] = rand() % 10;
  }
  for (int i = 0; i < m; i++){
    cout << a[i] << ", ";
  }
  cout << "The Password are: ";
  permute(a, 0, m);
  return 0;
}

void permute(int* a,int k ,int size){
  if (k == size){
    for (int i = 0; i < size; i++){
      cout << *(a + i);
    }
    cout << endl;
  }
  else{
    for (int i = k; i < size ; i++){
      int temp = a[k];
      a[k] = a[i];
      a[i] = temp;

      permute(a, k+1, size);

      temp = a[k];
      a[k] = a[i];
      a[i] = temp;
    }
  }
}
