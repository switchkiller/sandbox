#include<iostream>
using namespace std;

#define N 10
int main(){
  int mat[N][N] =
  {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };
  int r = 4, c = 4 ;

  int rarr[N][N];

  for (int i = 0; i < r; i++ )
    for (int j = 0; j < c; j++ )
      rarr[j][r-i-1] = mat[i][j];

  for (int i = 0; i < r; i++ ){
    cout << endl;
    for (int j = 0; j < c; j++ )
      cout << rarr[i][j] << " ";
  }

  return 0;
}
