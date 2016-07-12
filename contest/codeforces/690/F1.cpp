// F1. Tree of Life (easy)

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
#define N 10000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, ans;
vi g[N];

int dfs(int cur, int p){
    int cnt = 0;
    for (int adj:g[cur])
        if (adj != p){
            cnt++;
            ans += dfs(adj,cur);
        }
    ans += (cnt * (cnt - 1)) / 2;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int a, b;
    cin >> n;
    REP(i,0,n-1){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,-1);
    cout << ans << endl;
    return 0;
}
