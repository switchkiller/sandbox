#include<bits/stdc++.h>
using namespace std;
#define MAX 9
#define REP(i,a,b) for(int i = a; i < b; i++)
char matrix[MAX][MAX];
bool visited[MAX][MAX];
int n;
char mark;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int cnt1, cnt2;
bool isValid(int x, int y){
  if (x < 0 || y < 0 || x == n || y == 9 || visited[x][y] || ) return false;
  return true;
}
void dfs(int x, int y){
  visited[x][y] = true;
  REP(i,0,4){
      int nx = x + dx[i];
      int ny = n + dy[i];
      if (isValid()){
        if (matrix[nx][ny] == mark && mark == 'O')
          cnt1++;
        else if ()
        else
          dfs(nx,ny);
      }

  }
}
int main(){
  cin >> n;
  REP(i,0,n)
    gets(matrix[i]);
  memset(visited,false,sizeof visited);
  REP(i,0,n){
    REP(j,0,9){
      if (matrix[i][j] != '.' ){
        mark = matrix[i][j];
        matrix[i][j] = ' ';
        dfs(i,j);
      }
    }
  }
  return 0;
}
