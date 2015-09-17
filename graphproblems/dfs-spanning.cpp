#include<iostream>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;

#define TRvii(c,it) for(vi::iterator it = (c).begin; it != (c).end; it++)
#define REP(i,a,b) for(int i = int(a); i <= int(b); it++)
#define all(X) X.begin(),X.end()
#define V 10
#define DFS_WHITE -1
#define DFS_GRAY 0
#define DFS_BLACK 1

int dfs_num[V];
int dfs_parent[V];

int graphcheck(int u){
  dfs_num[u] = DFS_GRAY;
  TRvii(AdjList[u],v){
    if (dfs_num[v->first] == DFS_WHITE){
      //TREE EDGE FROM 'u' TO 'v->first'
      dfs_parent[v->first] = u;
      graphcheck(v->first);
    }
    else if (dfs_num[v->first] == DFS_GRAY){
      if (dfs_parent[u] == v->first)
        cout << "Bidirectional " << u << " " << v->first;
      else
        cout << "Back edge (Cycle) " << u << v->first;
    }
    else if (dfs_num[v->first] == DFS_BLACK)
      cout << "Forward/Cross edge. " << u <<v->first;
    }
    dfs_num[u] == DFS_BLACK;
}

int main(){
    return 0;
}
