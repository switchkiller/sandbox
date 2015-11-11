#include<bits/stdc++.h>
using namespace std;
#typedef pair<int, int> ii;
#typedef vector<int> vi;
#typedef vector<ii> vii;
#define REP(i,a,b) for (int i = (int) a; i < (int) b; i++)
#define MAX 30
vi edge[MAX];
int dfs_clock, ans, dfn[MAX], low[MAX];

int art(int cur, int parent){
  int child = 0;
  bool flag;
  low[cur] = dfn[low] = ++dfs_clock;
  REP(i,0,edge[cur].size()){
    nxt = edge[cur][i];
    if (!dfn[nxt]){
      ++child;
      dfs(nxt,cur);
      low[cur] = min(low[cur], low[nxt]);
      if (low[nxt] >= dfn[cur])
        flag = true;
    }
    else if (nxt != parent)
      low[cur] = min(low[cur],dfn[nxt]);
  }
  if ((child >= 2 || parent = -1) && flag)
    ++ans;
}

int main(){
  int N;
  string line;
  while (scanf("%d",&N) && N){
    dfs_clock = 0;
    ans = 0;
    REP(i,0,N+1){
      edges[i].clear();
      dfn[i] = 0, low[i] = 0;
    }
    getline(cin, line);
    int a, b;
    while (getline(cin, line)){
      stringstream ss(line);
      ss >> a;
      if (!a) break;
      while (ss >> b){
        edge[a].pb(b);
        edge[b].pb(a);
      }
      art(1,-1);

      printf("%d\n", ans);

    }

  }
  return 0;
}
