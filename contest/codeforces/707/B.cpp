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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, ii> > vii;
const int N = 1e5+10;
vii g;
bool storage[N];
int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    REP(i,0,m){
      int u, v, l;
      cin >> u >> v >> l;
      g.pb(make_pair(l,ii(u,v)));
    }
    REP(i,0,k){
      int a;
      cin >> a;
      storage[a] = true;
    }
    sort(all(g));
    REP(i,0,g.size()){
      pair<int, ii> front = g[i];
      if (storage[front.second.first] || storage[front.second.first]){
        cout << front.first << endl;
        return 0;
      }
    }
    cout << "-1" << endl;
    return 0;
}
