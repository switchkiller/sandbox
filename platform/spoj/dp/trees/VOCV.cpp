/* Problem Description:
VOCV - Con-Junctions
#graph-theory
TODO
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

const int M = 100012;

vi g[M];

int h[M], l[M];

int dfs(int cur, int p){
  int sum1 = 1, sum2 = 0;
  for (auto it : g[cur]){
    if (it == p)
      continue;
    dfs(it, cur);
    sum1 += min(h[it],l[it]);
    sum2 += h[it];
  }
  h[cur] = sum1;
  l[cur] = sum2;
  return min(h[cur], l[cur]);
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int t;
    cin >> t;
    while (t--){
      int n;
      cin >> n;
      for (auto& v : g) {
         v.clear();
      }
      REP(i,0,n-1){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
      }
      memset(h,0,sizeof(h));
      memset(l,0,sizeof(l));
      cout << dfs(1, -1) << endl;
    }
    return 0;
 }
