#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = a; i < b; i++)
char matrix[30+5][80+5];
bool visited[30+5][80+5];
int line;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char mark;
void dfs(int x, int y){
  if (matrix[x][y] == mark || matrix[x][y] == 'X') return;
  matrix[x][y] = mark;
  REP(i,0,4)
        dfs(x + dx[i],y + dy[i]);
}
int main(){
    while(gets(matrix[0])){
      line = 1;
      while (gets(matrix[line])){
        if (matrix[line][0] == '_') break;
        line++;
      }
      REP(i,0,line){
        REP(j,0,strlen(matrix[i])){
          if (matrix[i][j] != ' ' && matrix[i][j] != 'X'){
            mark = matrix[i][j];
            matrix[i][j] = ' ';
            dfs(i,j);
          }
        }
      }
      REP(i,0,line+1)
        cout << matrix[i] << endl;
    }
  return 0;
}
