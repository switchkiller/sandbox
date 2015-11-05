#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = a; i < b; i++)
char matrix[30+5][80+5];
bool visited[30+5][80+5];
int line;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void setup(){
  REP(i,0,35){
    REP(j,0,84){
      if (matrix[i][j] != 'X' && matrix[i][j] != '*' && matrix[i][j] != '_')
        matrix[i][j] = ' ';
    }
    matrix[i][84] = '\0';
  }
}
bool isValid(int x, int y){
  if (x < 0 || y < 0 || x == line || matrix[x][y] == '\0' || matrix[x][y] == '#' || visited[x][y]) return false;
  return true;
}
void dfs(int x, int y){
  visited[x][y] = true;
  REP(i,0,4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (isValid(nx,ny)){
      if (matrix[nx][ny] == 'X')
        matrix[x][y] = '#';
      else
        dfs(nx,ny);
    }
  }
}
void reverseSetup() {
    for ( int i = 34; i >= 0; i-- ) {
        bool foundLine = false;
        for ( int j = 83; j >= 0; j-- ) {
            if (matrix [i] [j] == 'X' || matrix [i] [j] == '#' || matrix [i] [j] == '_') {
                matrix [i] [j + 1] = '\0';
                foundLine = true;
                break;
            }
        }
        if (!foundLine) matrix [i] [0] = '\0';
    }
}
void cleanup() {
    for ( int i = 0; i < 35; i++ ) {
        for ( int j = 0; j < 85; j++ ) {
            matrix [i] [j] = '\0';
        }
    }
}
int main(){

  int testcases;
  scanf ("%d", &testcases);
  getchar();
  while (testcases--){
    while(gets(matrix[0])){
      line = 1;
      while (gets(matrix[line])){
        if (matrix[line][0] == '_') break;
        line++;
      }
      setup();
      REP(i,0,line){
        REP(j,0,strlen(matrix[i])){
          if (matrix[i][j] == '*'){
            matrix[i][j] = ' ';
            memset(visited,false,sizeof visited);
            dfs(i,j);
          }
        }
      }
      reverseSetup();
      REP(i,0,line+1)
        cout << matrix[i] << endl;
      }
      cleanup();
    }
  return 0;
}
