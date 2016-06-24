#include <bits/stdc++.h>
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
#define MAXN 3000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<int> tree[MAXN];
vector<int> centroidTree[MAXN];
bool centroidMarked[MAXN];

void addEdge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

/* method to setup subtree sizes and nodes in current tree */
void DFS(int src, bool visited[], int subtree_size[], int* n)
{
    visited[src] = true;
    *n += 1;
    /* initialize subtree size for current node*/
    subtree_size[src] = 1;
    vector<int>::iterator it;

    /* recur on non-visited and non-centroid neighbours */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (!visited[*it] && !centroidMarked[*it])
        {
            DFS(*it, visited, subtree_size, n);
            subtree_size[src]+=subtree_size[*it];
        }
}

int getCentroid(int src, bool visited[], int subtree_size[], int n)
{
    /* assume the current node to be centroid */
    bool is_centroid = true;

    /* mark it as visited */
    visited[src] = true;

    /* track heaviest child of node, to use in case node is
       not centroid */
    int heaviest_child = 0;

    vector<int>::iterator it;

    /* iterate over all adjacent nodes which are children
       (not visited) and not marked as centroid to some
       subtree */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (!visited[*it] && !centroidMarked[*it])
        {
            /* If any adjacent node has more than n/2 nodes,
             * current node cannot be centroid */
            if (subtree_size[*it]>n/2)
                is_centroid=false;

            /* update heaviest child */
            if (heaviest_child==0 ||
                subtree_size[*it]>subtree_size[heaviest_child])
                heaviest_child = *it;
        }

    /* if current node is a centroid */
    if (is_centroid && n-subtree_size[src]<=n/2)
        return src;

    /* else recur on heaviest child */
    return getCentroid(heaviest_child, visited, subtree_size, n);
}

/* function to get the centroid of tree rooted at src.
 * tree may be the original one or may belong to the forest */
int getCentroid(int src)
{
    bool visited[MAXN];

    int subtree_size[MAXN];

    /* initialize auxiliary arrays */
    memset(visited, false, sizeof visited);
    memset(subtree_size, 0, sizeof subtree_size);

    /* variable to hold number of nodes in the current tree */
    int n = 0;

    /* DFS to set up subtree sizes and nodes in current tree */
    DFS(src, visited, subtree_size, &n);

    for (int i=1; i<MAXN; i++)
        visited[i] = false;

    int centroid = getCentroid(src, visited, subtree_size, n);

    centroidMarked[centroid]=true;

    return centroid;
}

// driver function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif

    int n, m, v;

    cin >> n >> m;
    //
    FOR(i,2,n){
        cin >> v;
        if (i != v)
            addEdge(v,i);
    }

    FOR(i,1,m){
        cin >> v;
        cout << getCentroid(v) << endl;
    }
    return 0;
}
