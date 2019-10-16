// Graphs

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define TRvi(it, c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define inf 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;
#define maxn 50

#define DFS_WHITE 0
#define DFS_GRAY -1
#define DFS_BLACK 1

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int v, e;
vi adj[maxn];
bool visited[maxn];
int dfs_num[maxn], dfs_parent[maxn];
void dfs(int cur){
  visited[cur] = true;
  for (auto v : adj[cur])
    if (!visited[v])
      dfs(v);
}

void iscyclic(int cur){
  dfs_num[cur] = DFS_GRAY;
  for (auto v : adj[cur]){
    if (!dfs_num[v]){
      dfs_parent[v] = cur;
      iscyclic(v);
    }
    else if (dfs_num[v] == DFS_GRAY){
      if (dfs_parent[cur] == v)
        cout << "Bidirectional " << cur << " " << v << endl;
      else cout << "Back Edge (Cycle)" << cur << " " << v << endl;
    }
    else if (dfs_num[v] == DFS_BLACK )
      cout << "Forward Edge. " << cur << " " << v << endl;
  }
  dfs_num[v] = DFS_BLACK;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int a, b;
    cin >> v >> e;
    REP(i,0,e){
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    int s = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()){
      int v = q.front();
      visited[v] = true;
      q.pop();
      for (auto ad : adj[v])
        if (!visited[ad])  q.push(ad);
    }

    REP(i,0,v)
      cout << visited[i];

    iscyclic(1);
    return 0;
}
