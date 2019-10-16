// Propagating trees
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

const int N = 2000000;
int a[N];
vi g[N];

int lazy[N];

void propagate(int cur, int p){
if (lazy[cur] != 0)
  a[cur] += lazy[cur];
  for (auto adj : g[cur]){
    if (adj != p)
      if (lazy[cur] != 0){
        lazy[adj] -= lazy[cur];
        propagate(adj, cur);
      }
    }
  lazy[cur] = 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n, m;
    cin >> n >> m;

    FOR(i,1,n)
      cin >> a[i];

    REP(i,0,n-1){
      int a, b;
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
    }

    int type, x, val;
    REP(i,0,m){
      cin >> type;
      if (type == 1){
        cin >> x >> val;
        lazy[x] += val;
        propagate(1,0);
      }
      else{
        cin >> x;
        cout << a[x] << endl;
      }
    }
    return 0;
}
