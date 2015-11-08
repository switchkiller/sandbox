//Find the articulation vertex.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define REP(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
vii AdjList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vi art_ver;
int dfsNum, dfsRoot, rootChild;

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
}
