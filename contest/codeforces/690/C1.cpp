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
#define DFS_WHITE 0
#define DFS_BLACK 1
#define DFS_GRAY -1

const int MAXN = 1000;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi g[MAXN];
int visited[MAXN];
void dfs(int cur, int p){
  visited[cur] = DFS_GRAY;
  for (auto adj:g[cur]){
    if (visited[adj] == DFS_WHITE)
      dfs(adj, cur);
    else if (visited[adj] == DFS_GRAY)
      if (adj != p){  // Back edge
        cout << "no" << endl;
        exit(0);
      }
    else if (visited[adj] == DFS_BLACK){  // Forward or Cross edge
      cout << "no" << endl;
      exit(0);
    }
    visited[adj] = DFS_BLACK;
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n, m, a, b;
    cin >> n >> m;
    REP(i,0,m){
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
    }
    if (n != m+1){  // n-1 in a tree
      cout << "no" << endl;
      exit(0);
    }
    dfs(1,-1);
    REP(i,1,n+1)
      if (visited[i] != DFS_BLACK){
        cout << "no" << endl;
        exit(0);
      }

    cout << "yes" << endl;

    return 0;
}
