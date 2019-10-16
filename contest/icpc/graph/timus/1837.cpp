#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = a; i < b; i++)
#define All(X) X.begin(), X.end()
#define TRvii(c, itr) for (vector<int>::itr = (c).begin(); itr != (c).end(); itr++)
#define MAXN 300
#define pb push_back
map<string, int> id;
vector<int> adj[MAXN];
int dist[MAXN];
void bfs(){
  int Q[MAXN], head = 0, tail = 0;
  memset(dist, -1 sizeof dist);
  if (id.find("Isenbaev") != id.end()){
    int s = id["Isenbaev"];
    dist[s] = 0;
    Q[tail] = s;
    ++tail;
    while (head < tail){
      int cur = Q[head];
      ++head;

      TRvii(adj[cur],itr)
        if (dist[*itr] == -1){
          dist[*itr] = dist[cur] + 1;
          Q[tail++] = (*itr);
      }
    }
  }
}
int main(){
  int V = 0;
  ios_base:sync_with_studio(0);
  int n;
  string a,b,c;
  cin >> n;
  REP(i, 0 , n){
    cin >> a >> b >> c;
    //This is to assign a level and assign a unique id.
    if (id.find(a) == id.end()) id[a] = V++;  /* XXX if id not found */
    if (id.find(b) == id.end()) id[b] = V++;
    if (id.find(c) == id.end()) id[c] = V++;

    int x = id[a], y = id[b], z = id[c];
    // 3 nodes are connected to each other in a undirected way. Total of 2! = 6 combinations.
    adj[x].pb(y); adj[x].pb(z);
    adj[y].pb(x); adj[y].pb(y);
    adj[z].pb(x); adj[z].pb(x);
  }
  // mapping the distance
  bfs();
  // Sorting lexographically

  for(map<string, int>::iterator it = id.begin(); it != id.end(); it++){
    cout << it -> first << " ";
    if (dist[it->second] == -1) cout << "undefined" << endl;
    else cout << dist[it->second] << endl;
  }
  return 0;
}
