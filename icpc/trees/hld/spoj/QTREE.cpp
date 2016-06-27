// http://www.spoj.com/problems/QTREE/
// #hld
// #interesting

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
#define root 0

const int maxn = 10100;
const int logmax = 14;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi adj[maxn], costs[maxn], indexx[maxn]; int n;
int baseArray[maxn], ptr;
int chainNo, chainHead[maxn], chainInd[maxn], posInBase[maxn], subsize[maxn];
int depth[maxn], pa[logmax][maxn], otherEnd[maxn];
int st[4*maxn], qt[4*maxn];

// helper function for seg tree
int left(int p){
    return (1 << p);
}

int right(int p){
    return (1 << p) + 1;
}
// Build the segment tree
void build(int p, int b, int e){
    if (b == e) return;
    if (b == e-1) {
        st[p] = baseArray[b];
        return;
    }
    build(left(p), b, (b+e)/2);
    build(right(p), (b+e)/2+1, e);

    st[p] = st[left(p)] > st[right(p)] ? st[left(p)] : st[right(p)] ;
}

// dfs to find the size of subtree, set parent of node, depth of a node

void dfs(int cur, int prev, int _depth=0){
    pa[0][cur] = prev;  // Store thee in the example is special, only 2 nodes had degree greater than 2. We did a simple decomposition an
    subsize[cur] = 1;
    depth[cur] = _depth;
    for(int i = 0; i < adj[cur].size(); i++){
        if (adj[cur][i] != prev){
            otherEnd[indexx[cur][i]] = adj[cur][i];
            dfs(adj[cur][i], cur, _depth+1);
            subsize[cur] += subsize[adj[cur][i]];
        }
    }
}

void hld(int cur, int prev, int cost){
    if (chainHead[chainNo] == -1) chainHead[chainNo] = cur;
    chainInd[cur] = chainNo;
    posInBase[cur] = ptr;
    baseArray[ptr++] = cost;

    int idx = -1, sz = -1, ncost;
    // Find the special child
    for(int i = 0; i < adj[cur].size(); i++) if (adj[cur][i] != prev){
        if (subsize[adj[cur][i]] > sz){
            sz = subsize[adj[cur][i]];
            idx = i;
            ncost = costs[cur][i];
        }
    }

    if (idx != -1) hld(adj[cur][idx], cur, ncost);

    for (int i = 0; i < adj[cur].size(); i++) if (adj[cur][i] != prev){
        if (i != idx){
            // For normal node
            chainNo++;
            hld(adj[cur][i], cur, costs[cur][i]);
        }
    }
}

int LCA(int u, int v){  // Get the LCA using dp table
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i=0; i<logmax; i++) if( (diff>>i)&1 ) u = pa[i][u];
    if(u == v) return u;
    for(int i=logmax-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
        u = pa[i][u];
        v = pa[i][v];
    }
    return pa[0][u];
}

void query_tree(int p, int b, int e, int i, int j){
    if (i >= e || j <= b){ // No overlap condition
        qt[p] = -1;
        return ;
    }
    // Total Overlap condtion
    if (i <= b && j >= e){
        qt[p] = st[p];
        return;
    }

    // Partial Overlap
    query_tree(left(p),b,(b+e)/2,i,j);
    query_tree(right(p),(b+e)/2,e,i,j);
    qt[p] = qt[left(p)] > qt[right(p)] ? qt[left(p)] : qt[right(p)];
}

int query_up(int u, int v){
    if (u == v) return 0;
    int uchain, vchain = chainInd[v], ans = -1;
    while(1){
        uchain = chainInd[u];
        if (uchain == vchain){
            if (u == v) break; // Because we are on the same chain and we are done.
            query_tree(1,0,ptr,posInBase[v]+1, posInBase[u]+1);
            // Query Segment tree query function
            if (qt[1] > ans)    ans = qt[1];
            break;
        }
        // Remember that chainHead is always at the top
        // And the lca is trivial to lie on the upper tree tree
        // u and v are always greater than the lca
        query_tree(1,0,ptr,posInBase[chainHead[uchain]], posInBase[u]+1);
        if (qt[1] > ans)    ans = qt[1];
        u = chainHead[uchain]; // Goto the head of the parent chain
        u = pa[0][u];   // And then change the chain easily
    }
    return ans;
}

int query(int a, int b){
    int lca = LCA(a,b);
    int ans1 = query_up(a, lca);
    int ans2 = query_up(b, lca);
    if (ans2 > ans1)    ans1 = ans2;
    cout << ans1 << endl;
    // cout << 1 << endl;
}

void addEdge(int u, int v, int c, int i){
    adj[u].pb(v);
    costs[u].pb(c);
    indexx[u].pb(i);
    adj[v].pb(u);
    costs[v].pb(c);
    indexx[v].pb(i);
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int t;
    cin  >> t;
    while(t--){
        cin >> n;
        REP(i,0,n){
            adj[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i] = -1;
            // deal with LCA fill it with -1. These remain for those nodes which
            //  dont have further ancestors
            REP(j,0,logmax) pa[j][i] = -1;
        }

        REP(i,0,n-1){
            // cout << "Enter\n";
            int u, v, c;
            cin >> u >> v >> c;
            u--; v--;
            addEdge(u,v,c,i);
        }
        chainNo = 0;
        dfs(root,-1);
        hld(root,-1,-1); // Build the baseArray for segtree.
        build(1,0,ptr);

        // TODO Learn LCA problem and implement here.
        // The jump array is already initialized with their first ancestor.
        for(int i = 1; i < logmax; i++)
            for (int j = 0; j < n; j++)
                if (pa[i][j] != -1)
                    pa[i][j] = pa[i-1][pa[i-1][j]];

        REP(i,0,n) debug(pa[0][i]);
        REP(i,0,n) debug(depth[i]);

        while(1){
            char s[100];
            cin >> s;
            if (s[0] == 'D')
                break;
            int a, b;
            cin >> a >> b;
            if (s[0] == 'Q')
                query(a-1,b-1);

                // change(a-1,b);
        }
    }
    return 0;
}
