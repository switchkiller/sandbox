// E. Xenia and Tree - 342E
/*
Solved using centroid decomposition method. The centroid of the tree is supposed
to store the nearest Red node distance, hence for every update the centroid will
get updated. When query is performed, we have to calculate the distance between
given node to the nearest red node. We will traverse through the ancestor x of
node u in the centroid tree. If the nearest red node is on the path, then will
confirm to get the lowest distance at higher depth itself. Else we will traverse
maximum upto the the root of the centroid tree and we are confirm to get the
nearest red node to the root. If root of centroid tree is c, then ans[c] stores
the distance between the nearest red node to c (according to the original distance)
, and dist(c, u) gives us the distance between c and u in the original tree.

Remember that, decomposition is just a optimality to get better time and space
complexity.

Update and query takes O(logn)

We need to determine the LCA which takes <O(nlogn), O(logn)> and O(nlogn) space.

Constructing a centroid tree takes O(nlogn) and O(n) space.

*/

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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = (1e5)+10;
const int LN = 20;

int n, dp[LN][N], subsize[N], depth[N], par[N], ans[N], nn;
set<int> g[N];

/* ----------Pre-processing------------ */

void dfs(int u){
    for (int adj : g[u])
        if (adj != dp[0][u]){
            dp[0][adj] = u; // Used to find the LCA
            depth[adj] = depth[u]+1;
            dfs(adj);
        }
}

void preprocess(){
    depth[0] = 0;
    dp[0][0] = 0;
    dfs(0);
    REP(i,1,LN)
        REP(j,0,n)
            dp[i][j] = dp[i-1][dp[i-1][j]];
}

int lca(int u, int v){
    if (depth[u] > depth[v]) swap(u,v);
    int d = depth[v] - depth[u];
    REP(i,0,LN)
        if (d & (1 << i))
            v=dp[i][v];
    if (u == v) return u;
    RREP(i,LN-1,-1)
        if (dp[i][u] != dp[i][v])
            u = dp[i][u], v = dp[i][v];
    return dp[0][u];
}

int dist(int u, int v){
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

/* ----------Decomposition------------ */

// We require two dfs, one to calculate the size of subtree and one to find centroid.

void dfs0(int cur, int p){
    nn++;
    subsize[cur] = 1;
    for (int adj:g[cur])
        if (adj != p){
            dfs0(adj, cur);
            subsize[cur] += subsize[adj];
        }
}

int dfs1(int cur, int p){
    for (int adj:g[cur])
        if (adj != p && subsize[adj] > nn/2)
            return dfs1(adj, cur);
    return cur;
}

void decompose(int root, int p){
    nn = 0;
    dfs0(root,root);
    int centroid = dfs1(root,root);
    if (p == -1) p = centroid; // Parent of root of centroid tree set itelf.
    par[centroid] = p;
    for (int adj:g[centroid]){
        g[adj].erase(centroid);
        decompose(adj,centroid);
    }
    g[centroid].clear();
}

/* ----------Handle Queries------------ */

// O(logn)
void update(int v){
    int x = v;
    while(1){
        ans[x] = min(ans[x], dist(v,x));
        if (x == par[x]) // We are at the root of the centroid tree.
            break;
        x = par[x];
    }
}

int query(int v){
    int ret = inf;
    int x = v;
    while(1){
        ret = min(ret,ans[x]+dist(x,v));
        if (x == par[x])
            break;
        x = par[x];
    }
    return ret;
}

/* ----------driver------------ */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     freopen("342E-in.txt" , "r" , stdin);
     freopen("342E-out.txt" , "w" , stdout);
    #endif
    int k, a, b;
    cin >> n >> k;
    REP(i,1,n){
        cin >> a >> b;
        a--, b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    preprocess();
    decompose(0,-1);
    REP(i,0,n) ans[i] = inf;
    update(0);  // Given the root is red initially.
    // Perform other actions.
    REP(i,0,k){
        cin >> a >> b;
        b--;
        if (a == 1)
            update(b);
        else
            cout << query(b) << endl;
    }

    return 0;
}
