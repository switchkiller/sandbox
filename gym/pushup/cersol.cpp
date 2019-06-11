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
const int N = 2500;
vi gr[N];
bool visited[N];
int cl[N];
void dfs(int cur, int parent){
  for(auto adj:gr[cur]){
    if (adj != parent){
      dfs(adj,cur);
    }
  }
  visited[cl[cur-1]] = true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t;
    cin >> t;
    while (t--){
      for (int i = 0; i < N; i++) {
          gr[i].clear();
          visited[i] = false;
          cl[i] = 0;
      }
      int n, m, k;
      cin >> n >> m >> k;
      REP(i,0,n) cin >> cl[i];
      REP(i,0,m){
        int a, b;
        cin >> a >> b;
        gr[a].pb(b);
        gr[b].pb(a);
      }
      dfs(1,-1);
      int cnt = 0;
      for (int i = 0; i <= k; i++){
        if (visited[i]) cnt++;
      }
      if (cnt == k) cout << cnt << endl;
      else cout << "-1" << endl;
    }
    return 0;
 }
