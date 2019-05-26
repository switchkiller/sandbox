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
const int N = 1e5;
vector< pair<int, long> > grp[N];

bool col[N];
void dfs(int cur, int p){
  for (vector< pair<int, long> >::iterator adj = grp[cur].begin(); adj != grp[cur].end(); adj++){
    if (adj->first != p){
        if (adj->second % 2 == 1)
          col[adj->first] = !(col[cur]);
        else col[adj->first] = col[cur];
        dfs(adj->first, cur);
    }
  }
  return;
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
      int u,v; long w;
      cin >> u >> v >> w;
      u--, v--;
      grp[u].pb(mp(v,w));
      grp[v].pb(mp(u,w));
    }
    int cur = 0;
    col[0] = true;
    dfs(0,-1);
    REP(i,0,n){
      if (col[i]) cout << "0"<<endl;
      else cout << "1" << endl;
    }
    return 0;
 }
