#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define REP(a,b,i) for (int i = (a); i < (b); i++)
#define NODE 15
#define white -1
#define black 1
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define all(x) x.rbegin(), x.rend()
char matrix[NODE][NODE];
int sol_matrix[NODE][NODE];
int n, m;
void readgraph(int n, int m){
  int ind=0;
  string str = "", temp;
  REP(0,n,i){
    cin >> temp;
    str += temp;
  }
  REP(0,n,i){
    REP(0,m,j){
      matrix[i][j] = str[ind++];
      if (matrix[i][j] == 'G')
        sol_matrix[i][j] = white;
      else
        sol_matrix[i][j] = black;
    }
  }
}
int sol(int x, int y){
  int cnt = 1, max;
  if (x < 0 || x > n-1 || y < 0 || y > m-1 || sol_matrix[x][y] != white)
    return 1;
  max = n > m ? m : n;
  REP(1,max,i){
    //if (x-i>=0 && y-i>=0 && x+i<n && y+i<m){
      if (sol_matrix[x-i][y] == white && sol_matrix[x][y-i] == white && sol_matrix[x][y+i] == white && sol_matrix[x+i][y] == white ){
       sol_matrix[x-i][y] = black;
       sol_matrix[x][y-i] = black;
       sol_matrix[x][y+i] = black;
       sol_matrix[x+i][y] = black;
       sol_matrix[x][y] = black;
       cnt=cnt+4;
    }
    else
      break;
   }
  return cnt;
}

int main(){
  int max = 1;
  vector<int> v(30);
  int i = 0;
  cin >> n >> m;
  readgraph(n,m);
  for (int x = 0; x<n; x++){
    for (int y = 0; y < m; y++){
      if (matrix[x][y] == 'G' && sol_matrix[x][y] == white)
        v.push_back(sol(x,y));
    }
  }
  sort(all(v));
  max *= v[0];
  max *= v[1];
  cout << max;
  return 0;
}
