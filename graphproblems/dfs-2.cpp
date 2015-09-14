#include<iostream>
#include<vector>
using namespace std;

#define V 10
#define DFS_WHITE -1
#define DFS_BLACK 1
#define REP(i,a,b) for (int i = a, i <= b; i++)
#define TRvii (c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

typedef pair<int, int> ii;
typedef vector< ii > vii;

int dfs_num[V];

void dfs(int u){
  cout << u;
  dfs_num[u] = DFS_BLACK;
  TRvii (AdjList[u], v)
    if (dfs_num[v->first] == DFS_WHITE)
      dfs(v->first);
}

int main(){
  return 0;
}
