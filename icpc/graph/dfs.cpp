#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 0
vector<vii> AdjList;

vi dfs_num;
int numCC;
vi dfs_parent;

void dfs(int u){
  printf("%d",u);
  dfs_num[u] = DFS_BLACK;
  for (int j = 0; j < (int)AdjList[u].size(); j++){
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      dfs(v.first);
  }
}

void floodfill(int u, int color){
  dfs_num[u] = color;
  for (int j = 0; j < (int)AdjList.size(); j++){
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      floodfill(v.first, color);
  }
}

void graphCheck(int u){
  dfs_num[u] = DFS_GRAY;
  for (int j = 0; j < (int) AdjList[u].size(); j++){
    ii v  = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE){
      dfs_parent[v.first] = u;
      graphCheck(v.first);
    }
    else if(dfs_num[v.first] == DFS_GRAY){
      if (v.first == dfs_parent[u])
        printf("Bidirectional (%d, %d) - (%d, %d)\n", u, v.first, v.first, u);
      else
        printf("Back Edge (%d, %d) (Cycle)\n", u, v.first);
      }
      elseif(dfs_num[v.first] == DFS_BLACK)
        printf("Forward/Cross Edge (%d, %d)\n", u, v.first);
    }
    dfs_num[u] = DFS_BLACK;
  }
}
