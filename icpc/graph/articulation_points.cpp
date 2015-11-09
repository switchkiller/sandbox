//Find the articulation vertex.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define REP(i,a,b) for (int i = a; i < (int) b; i++)
#define pb push_back
vii AdjList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vi art_ver;
int dfsNum, dfsRoot, rootChild;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNum++;
    for (int itr = 0; itr != AdjList[u].size(); itr++){
      ii v = AdjList[u][itr];
      if (dfs_num[v.first] == DFS_WHITE){
        dfs_parent[v.first] = u;
        if (u == dfsRoot) rootChild++;
        articulationPointAndBridge(v.first);  // XXX after you start backtracking
        if (dfs_low[v.first] >= dfs_num[u])
          art_ver[u] = true;
        if (dfs_low[v.first] > dfs_num[u])
          cout << u << "-" << v.first << " is a bridge.";
        dfs_low[u] = min(dfs_low[u],dfs_low[v.first]); //Backedge the ancestor will get updated automatically as a result of backtrack
      }
      else if (v.first != dfs_parent[u])
        dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}

int main(){
  int V, neighbour, id, weight;
  cin >> V;
  REP(i,0,V){
    cin >> neighbour;
    REP(J,0,neighbour){
      cin >> id >> weight;
      AdjList[i].pb(ii(id,weight));
    }
  }
  dfsNum = 0;
  dfs_num.assign(V,DFS_WHITE);
  dfs_low.assign(V,0);
  dfs_parent.assign(V,-1);
  art_ver.assign(V,0);

  cout << "Bridges: ";
  REP(i,0,V){
    if (dfs_num[i] == DFS_WHITE){
      dfsRoot = i; rootChild = 0;
      articulationPointAndBridge(i);
      art_ver[dfsRoot] == (rootChild > 1);
    }
  }

  cout << "Articulation Vertex: ";
  REP(i,0,V){
    if (art_ver[i]){
      cout << i;
    }
  }
  return 0;
}
