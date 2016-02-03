#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 100000000
#define pb push_back
#define REP(i,a,b) for (int i = (a); i < (b); i++)
int main(){
  int N, E, u, v,s;
  vector<vii> AdjList;
  cin >> N;
  int Q;
  int *fares = new int[N];
  REP (i,0,N)
    cin >> fares[i];
  AdjList.assign(N, vii());
  for (int i = 0; i < N-1; i++){
    cin >> u >> v;
    AdjList[u].pb(ii(v, 1));
  }
   cin >> Q;
    REP(i,0,Q){
      cin >> s >> v;
    vi dist(N, INF); dist[u] = 0;
    vi val(N, 0);
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,s));
    while (!pq.empty()){
    /* code */
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      /* code */
      ii v = AdjList[u][j];
      if (dist[u] + v.second < dist[v.first]){
      //  val[v.first] += val[u];
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
  cout << dist[v];
  }
  return 0;
}
