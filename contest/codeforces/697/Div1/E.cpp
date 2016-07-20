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
#define all(X) X.begin(), X.end()
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define maxn 10e5 + 10
#define logmax 19
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

/*-------------------------------------------------------
                      <Methodology>
Use:
1. Segment Tree
2. Lazy Propagation
3. Least Common Ancestor
4. Heavy Light Decomposition
#dfs complimentory
---------------------------------------------------------*/

int dp[maxn][logmax];
int subsize[maxn], depth[maxn];

ii girl(inf, -1);
vi adj[maxn];
set<int> S[maxn]; int tmp[maxn];
pair<ll, int> st[maxn*4];
ll lazy[maxn*4];
int chainNo[maxn], chainHead[maxn], posInBase[maxn], finish[maxn], ptr = 0, chainCnt = 0; // hld
int n;

// Calculate the subsize
void DFS(int cur, int p, int _depth = 0){
  subsize[cur] = 1;
  depth[cur] = _depth;
  dp[cur][0] = p;
  for (auto u : adj[cur])   if (u != p){
      DFS(u, cur, _depth+1);
      subsize[cur] += subsize[u];
    }
}
void hld(int cur, int p){
  posInBase[cur] = ++ptr; // Start interval
  if (chainNo[cur] == -1){
    chainNo[cur] = ++chainCnt;
    chainHead[chainCnt] = cur;
  }

  int bestChild = 0;  // Because indexing for vertex begins from 1

  for (auto v : adj[cur]) if (v != p){
    if (subsize[v] > subsize[bestChild]) bestChild = v;
  }

  if (bestChild != 0){
  // Special Child
    chainNo[bestChild] = chainNo[cur];
    hld(v, cur);
  }

  for (auto v : adj[cur]) if (v != p && v != bestChild){
    // Normal Child
    hld(v, cur);
  }
  finish[cur] = ptr;  // Ending interval
}
void push_lazy(int root, int l, int r){
  if (!lazy[root]) return;
  st[root].first += lazy[root];
  if (l != r){
    lazy[L(root)] += lazy[root];
    lazy[R(root)] += lazy[root];
  }
  lazy[root] = 0;
}
pair<ll, int> combine(pair<ll, int> a, pair<ll, int> b){
  if (a.second == -1) return b;
  if (b.second == -1) return a;
  // Create a pair of {sum, index}. sum is the sum on the interval
  if (make_pair(a.first + a.second , tmp[a.second]) < make_pair(b.first + b.second, tmp[b.second]))) return a;
  return b;
}
void point_update(int root, int l, int r, int pos, int idx){
  push_lazy(root,l,r);
  if ( l > pos || r < pos )  return;
  if (l == r){
    if (S[idx].empty())
      st[root] = {0,-1};
    else
      st[root] = {st[root].first, *S[idx].begin()};
  }
  else{
    int mid = (l + r) / 2;
    point_update(L(root), l, mid, pos, idx);
    point_update(R(root), mid+1, r, pos, idx);
    st[root] = combine(st[L(root)], st[R(root)]);
  }
}
void LCA(int u, int v){
  if (depth[u] < depth[v]) swap(u,v);
  int diff = depth[u] - depth[v];
  REP(i,0,logmax) if (diff & (1 << i))
    v = dp[v][i];
  if (u == v) return u;
  RREP(i,logmax-1,-1)
    if (dp[u][i] != dp[v][i])
      u = dp[u][i], v = dp[v][i];
  return dp[u][0];
}
pair<ll, int> query_segtree(int root,int l, int r, int x, int y){
  push_lazy(root,l,r);
  if (l > x || r < x) return {0, -1};
  else if (l <= x && r >= y)
    return st[root];
  else{
    int mid = (l + r) / 2;
    return combine(query_segtree(2*root,l,mid,x,y), query_segtree(2*root+1,mid+1,r,x,y));}
}
pair<ll, int> query_path(int u, int p){
  pair<ll, int> ans = {0, -1};
  while (chainNo[u] != chainNo[p]){
    ans = combine(ans, query_segtree(1,1,n,posInBase[chainHead[chainNo[u]]],posInBase[u]));
    u = dp[chainHead[chainNo[u]]][0];
  }
  ans = combine(ans, query_segtree(1,1,n,posInBase[p],posInBase[u]));
  return ans;
}
int query(int u, int v){
  int lca = LCA(u,v);
  pair<ll, int> best = combine(query_path(u, lca), query_path(v, lca));
  if (best.second == -1) return best.second;
  S[temp[best.second]].erase(best.second);
  point_update(1,1,n,posInBase[temp[best.second]],temp[best.second]);
  return best.second;
}
void range_update(int root, int l, int r, int x, int y, int val){
  push_lazy(root,l,r);
  if (l < y || r > x) return;
  if (l >= x || r <= y){
    lazy[root] += val;
    push_lazy(root, l, r);
  }
  else{
    int mid = (l + r) / 2;
    range_update(L(root),l,mid,x,y,val); range_update(R(root),mid,r,x,y,val);
    st[root] = combine(st[L(root)], st[R(root)]);  }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int m, q, type;
    cin >> n >> m >> q;
    memset(chainHead, -1, sizeof chainHead);
    memset(dp, -1, sizeof dp);
    FOR(i,1,n){
      int v, u;
      cin >> v >> u;
      adj[v].pb(u); adj.pb(v);
    }

    FOR(i,1,m){
      int v;
      cin >> v;
      temp[i] = v;
      S[v].pb(i);
    }

    DFS(1, 0);
    hld(1, 0);
    FOR(i,1,n) point_update(1, 1, n, posInBase[i], i);

    // LCA
    FOR(i,1,n)
      FOR(j,1,logmax)
          dp[i][j] = dp[dp[i][j-1]][j-1];

    while(q--){
      int k;
      cin >> type;
      if (type == 1){
        cin >> v >> u >> k;
        vector<int> V;
        while(k--){
          int ans = query(u,v);
          if (ans == -1) break;
          V.pb(ans);
        }
        cout << V.size() << " ";
        for (auto v : V) cout << v << " ";
        cout << endl;
      }
      else{
        cin >> v >> k;
        range_update(1,1,n,posInBase[v],finish[v],k);
      }
    }

    return 0;
}
