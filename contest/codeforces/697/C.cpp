// C. Lorenzo Von Matterhorn
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
#define MAXN 1050

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct val{
  ll v, u, w;
};

vector<val> prop;
set<ll> ans;
int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    ll n, b, x, v, u, w;
    val a;
    cin >> n;
    REP(i,0,n){
      cin >> x;
      if (x == 1){
        cin >> a.v >> a.u >> a.w;
        prop.pb(a);
      }
      else{
        ans.clear();
        cin >> v >> u;
        while (v != u){
          if (v > u){
            ans.insert(v);
            v /= 2;
          }
          else{
            ans.insert(u);
            u /= 2;
          }
        }
        b = 0;
        REP(i,0,prop.size()){
          v = prop[i].v;
          u = prop[i].u;
          w = prop[i].w;

          while (v != u){
            if (v > u){
              if (ans.find(v) != ans.end())
                b += w;
              v /= 2;
            }
            else{
              if (ans.find(u) != ans.end())
                b += w;
              u /= 2;
            }
          }
        }
        cout << b << endl;
      }
    }
    return 0;
}
