// Print the kth element of a spiral matrix

#include<iostream>
using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

const int N = 100;

int spiralkth(int arr[][N], int r, int c, int k){
  int x = 0, y = 0;

  while (x < r && y < c){

    for(int i = y; i < c; i++)
      cout << arr[x][i] << " ";
    x++;

    for (int i = x; i < r; i++)
      cout << arr[i][c-1] << " ";

    c--;

    // if (x < r){
    for (int i = c-1; i >= y; i--)
      cout << arr[r-1][i] << " ";
    r--;
    // }
    // if (y < c){
    for (int i = r-1; i >= x; i--)
      cout << arr[i][y] << " ";

    y++;
    // }
  }
}

int main(){
  int MAT[N][N];
  int r, c;
  cin >> r >> c;

  REP(i,0,r)
    REP(j,0,c)
      cin >> MAT[i][j];

  int k;
  cin >> k;
  spiralkth(MAT, r, c, k);

  return 0;
}
