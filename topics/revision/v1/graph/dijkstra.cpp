#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 100000000
#define pb push_back
int main(){
  int V, E, s, u, v, w;
  vector<vii> AdjList;
  scanf("%d %d %d",&V, &E, &s);
  AdjList.assign(V, vii());
  for (int i = 0; i < E; i++){
    scanf("%d %d %d",&u, &v, &w);
    AdjList[u].pb(ii(v, w));
  }
  vi dist(V, INF); dist[s] = 0;
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,s));
  while (!pq.empty()) {
    /* code */
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      /* code */
      ii v = AdjList[u][j];
      if (dist[u] + v.second < dist[v.first]){
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
  for (int i = 0; i < V; i++)
    printf("SSSP(%d %d) = %d\n", s, i, dist[i]);
  return 0;
}
