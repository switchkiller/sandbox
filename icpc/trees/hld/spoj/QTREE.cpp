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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi adj[maxn], costs[N], indexx[N];
int baseArray[maxn], ptr;
int chainNo, chainHead[maxn], chainInd[maxn], posInBase[maxn], subsize[maxn];
int depth[maxn], otherEnd[maxn];
int st[4*maxn];

// helper function for seg tree
int left(int p){
    return (1 << p);
}

int right(int p){
    return (1 << p) + 1;
}
// Build the segment tree
void build(int p, int b, int e){
    if (b > e) return;
    if (b == e-1) {
        st[p] = baseArray[b];
        return;
    }
    int p1 = build(left(p), b, (b+e) >> 1);
    int p2 = build(right(p), (b+e) >> 1, e);

    st[p] = p1 > p2 ? p1 : p2 ;
}


// dfs to find the size of subtree, set parent of node, depth of a node

void dfs(int cur, int prev, int _depth=0){
    int cnt = 0;
    depth[cur] = _depth;
    subsize[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        if (adj[cur][i] != prev){
            otherEnd[indexx[cur][i]] = adj[cur][i];
            dfs(adj[cur][i], cur, _depth+1);
            subtree[cur] += subtree[adj[cur][i]];
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

void addEdge(int u, int v, int c, int i){
    adj[u].pb(v);
    costs[u].pb(c);
    indexx[u].pb(i);
    adj[v].pb(u);
    costs[v].pb(c);
    indexx[v].pb(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int t, n;
    cin  >> t;
    while(t--){
        cin >> n;
        ptr=0;
        REP(i,0,n){
            tree[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i] = -1;
            // deal with LCA
        }

        FOR(i,0,n-1){
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

        while(1){
            char s[100];
            cin >> s;
            if (s[0] == 'D')
                break;
            int a, b;
            cin >> a >> b;
            if (s[0] == 'Q')
                query(a-1,b-1);
            else
                change(a-1,b);
        }
    }
    return 0;
}
