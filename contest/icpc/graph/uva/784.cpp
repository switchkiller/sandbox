#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = a; i < b; i++)
char matrix[30+5][80+5];
bool visited[30+5][80+5];
int line;
int dx[] = {-1,-1,-1,0,0,1,1,1}, dy[] = {-1,0,1,1,1,0,-1,-1};
void setup(){
  REP(i,0,35){
    REP(j,0,84){
      if (matrix[i][j] != 'X' && matrix[i][j] != '*' && matrix[i][j] != '_')
        matrix[i][j] = ' ';
    }
    matrix[i][84] = '\0';
  }
}
void dfs(int x, int y){
  if (x < 0 || y < 0 || x == line || matrix[x][y] == '\0' || matrix[x][y] == 'X' || visited[x][y]) return;
  visited[x][y] = true;
  matrix[x][y] = '#';
  REP(i,0,8)
        dfs(x + dx[i],y + dy[i]);
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
