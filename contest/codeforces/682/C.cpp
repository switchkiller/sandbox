// C. Alyona and Tree
// #kadane #fav #dp #graphs #dfs

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

const int maxn = 100010;
ll a[maxn], children[maxn], mdist[maxn];
bool bad[maxn], visited[maxn];
map<ii, ll> w;
vector<int> AdjList[maxn];

ll dfs(int v)
{
	if (visited[v])
		return 0;

	visited[v] = true;

	int cnt = 1;
	for (int adj_v : AdjList[v])
		if (!visited[adj_v])
		{
			mdist[adj_v] = max(mdist[v] + w[{v, adj_v}], 0ll);
			if (mdist[v] + w[{v, adj_v}] > a[adj_v])
				bad[adj_v] = true;

			cnt += dfs(adj_v);
		}

	children[v] = cnt;

	return cnt;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif

    int n, a[maxn];
    cin >> n;
    memset(bad, false, sizeof bad);
    FOR (i,1,n) cin >> a[i];

    FOR(i,2,n){
        int p, c;
        cin >> p >> c;
        w[{i,p}] = w[{p,i}] = c;
        AdjList[i].pb(p);
        AdjList[p].pb(i);
    }

    dfs(1);

    queue<int> q;
    q.push(1);

    REP(i,0,n) debug(bad[i]);
    memset(visited, false, sizeof visited);

    int total = 0;
    while (!q.empty()){
        int v = q.front();
        visited[v] = true;
        q.pop();

        if (bad[v]){
            total += children[v];
            continue;
        }

        for(auto adj : AdjList[v])
            if (!visited[adj]){ q.push(adj);}
    }


    cout << total << endl;
    return 0;
}
