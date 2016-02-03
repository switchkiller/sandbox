#include<bits/stdc++.h>
typedef vector<long> vll;
typedef vector< vll > vvll;
#define REP(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
int main(){
  int n,k,m;
  vvll arr;
  cin >> n >> k >> m;
  REP(i,0,n)
    arr[i][0] = m;
  REP(i,0,k)
    arr[0][i] = m;
  REP(i,0,n)
    REP(j,0,k)
      arr[i][j] = arr[i-1][j] + arr[i-1][j-1] + arr[i][j-1];
  cout << arr[m][n];
  return 0;
}
