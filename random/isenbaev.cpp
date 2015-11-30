#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = a; i < b; i++)
#define All(X) X.begin(), X.end()
#define TRvii(c, itr) for (vector<int>::itr =  (c).begin(); itr != (c).end(); itr++)
#define MAXN 300
#define pb push_back
map<string, int> id;
vector<int> adj[MAXN];
int dist[MAXN];
void bfs(){


}
int main(){
  int V = 0;
  ios_base:sync_with_studio(0);
  int n;
  string a, b, c;
  cin >> n;
  REP(i, 0 , n){
    cin >> a >> b >> c;

    if (id.find(a) == id.end()) id[a] = V++;
    if (id.find(b) == id.end()) id[b] = V++;
    if (id.find(c) == id.end()) id[c] = V++;

    int x = id[a], y = id[b], z = id[c];
    // Combinations..
    adj[x].pb(y); adj[y].pb(x);
    adj[y].pb(z); adj[z].pb(y);
    adj[z].pb(x); adj[x].pb(z);

  }
  return 0;
}
