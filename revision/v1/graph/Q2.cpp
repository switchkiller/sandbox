#include<bits/stdc++.h>
using namespace std;
#define MAX 20
#define DFS_WHITE 0
#define DFS_BLACK -1
typedef vector<int> vi;
#define REP(i,a,b) for (int i = a; i < b; i++)
#define TRvii(a,itr) for (vi::iterator itr = (a).begin(); itr  != (a).end(); ++itr)
#define pb push_back
vi AdjList[MAX];
int dfs_num[MAX];
int v,e;
void dfs(int u){
  cout << u << " ";
  dfs_num[u] = DFS_BLACK;
  TRvii(AdjList[u],itr)
    if (dfs_num[*itr] == DFS_WHITE)
      dfs(*itr);
}
int main(){
  ios_base::sync_with_stdio(false);
  int n,x,y;
  cin >> n;
  REP(i,0,n){
    AdjList[MAX].clear();
    cin >> v;       // Number of vertex
    cin >> e;       //Number of edges
    //vector can be resized.
    //memset(dfs_num,DFS_WHITE,sizeof(dfs_num)); // XXX memset can only set the values -1, 0 to array of integers.
    REP(j,0,e){
      cin >> x >> y;
      AdjList[x].pb(y);
      AdjList[y].pb(x);
    }
    REP(j,0,v)
      if (dfs_num[j] == DFS_WHITE)
        dfs(j);
  }
  return 0;
}
