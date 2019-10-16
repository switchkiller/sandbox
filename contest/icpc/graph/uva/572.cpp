/*---------------------
| Author: switchkiller |
| Problem: UVa 572     |
| Tags: conn_comp, dfs |
----------------------*/

#include<iostream>
#include<cstdio>
#define DFS_WHITE -1
#define DFS_BLACK 1
#define NODES 102
using namespace std;
int dfs_matrix[NODES][NODES];
char matrix[NODES][NODES];
int row, col;
int dx[] = {-1,0,1,0,-1,-1,1,1}, dy[] = {0,1,0,-1,-1,1,1,-1};

void readgraph(){
  string str = "", temp;
  int index = 0;
  for (int i = 0; i < row; i++){
    cin >> temp;
    str += temp;
  }
  for (int x = 0; x < row; x++){
    for(int y = 0; y < col; y++, index++){
      matrix[x][y] = str[index];
      if (matrix[x][y] == '*')
        dfs_matrix[x][y] = 0;
        else
          dfs_matrix[x][y] = DFS_WHITE;
    }
  }
}

void dfs(int x, int y){
  if (x < 0 || x > row-1 || y < 0 || y > col-1 || dfs_matrix[x][y] != DFS_WHITE)
    return;
  dfs_matrix[x][y] = DFS_BLACK;
  for (int i = 0; i <= 8; i++)
    dfs(x+dx[i],y+dy[i]);
}

int main(){
  while(scanf("%d %d",&row,&col)){
    if (!row)
      break;
      int cc = 0;
      readgraph();
      for (int x = 0; x<row; x++){
        for (int y = 0; y < col; y++){
          if (matrix[x][y] == '@' && dfs_matrix[x][y] == DFS_WHITE){
            dfs(x,y);
            cc++;
          }
        }
      }
      printf("%d\n", cc);
  }
  return 0;
}
