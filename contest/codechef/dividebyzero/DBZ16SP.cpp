//Not complete
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef vector<int> vi;
typedef vector<ic> vii;
#define INF 100000000
#define REP(i,a,b) for (int i = (int) a; i < (int) b; i++)
#define TRvic(c,it) for (vic::iterator it = (c).begin(); it != (c).end(); it++)
vi AdjList;
int main(){
  int N, M, K;
  int u, v;
  char c;
  string str="";
  cin >> N >> M >> K;
  AdjList.assign(N, vii());
  REP(i,1,M+1){
    cin >> u >> v >> c;
    AdjList[u].pb(ic(v, c));
  }
  queue<int> q; multiset<string, int> dist;
  q.push(1); dist[1] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    TRvic(AdjList[u], v)
      if (!dist.count(v->first)){
        dist[v->first] = dist[u] + 1;
        q.push(v->first);
      }
  }

  return 0;
}
