/* Problem Description:

*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

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

#define MAXN 200000
int visited[MAXN];
vector<int> g0[MAXN], g1[MAXN];
vector<int> comm;
int cnt0[MAXN], cnt1[MAXN];
void dfs0(int cur){
  visited[cur] = true;
  comm.pb(cur);
  for (int it: g0[cur])
    if (!visited[it] )
      dfs0(it);
}
void dfs1(int cur){
  visited[cur] = true;
  comm.pb(cur);
  for (int it: g1[cur])
    if (!visited[it])
      dfs1(it);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    cin >> n;
    REP(i,0,n-1){
      int u, v, w;
      cin >> u >> v >> w;
      if (w == 1){
        g1[u-1].pb(v-1);
        g1[v-1].pb(u-1);
      } else {
        g0[u-1].pb(v-1);
        g0[v-1].pb(u-1);
      }
    }

    ll ans = 0;
    REP(i,0,n) visited[i] = false;
    REP(i,0,n){
      if (!visited[i]){
        comm.clear();
        dfs0(i);
        ans += 1LL * ((int)comm.size() * ((int)comm.size()-1));
        for(int it: comm)
          cnt0[it] = (int)comm.size();
      }
    }
    REP(i,0,n) visited[i] = false;
    REP(i,0,n){
      if (!visited[i]){
        comm.clear();
        dfs1(i);
        ans += 1LL * ((int)comm.size() * ((int)comm.size()-1));
        for(int it: comm)
          cnt1[it] = (int)comm.size();
      }
    }

    REP(i,0,n)
      ans += 1LL * (cnt1[i] - 1) * (cnt0[i] - 1);

    cout << ans << endl;
    return 0;
 }
