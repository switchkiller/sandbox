/* Problem Description:
 O(26*(V+E)) approach :( 
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

const int N = 10000;

vector<int> graph[N];
string str;
int dp[N][26];

void dfs(int cur, int parent){
  for (auto adj : graph[cur]){
    if (adj != parent){
      dfs(adj, cur);
      for (int i = 0; i < 26; i++)
      dp[cur][i] += dp[adj][i];
    }
  }
  dp[cur][str[cur]-97] += 1;
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
    cin >> str;

    for (int i = 0; i < n-1; i++){
      int a, b;
      cin >> a >> b;
      a--, b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    dfs(0,-1);

    for (int i = 0; i < n; i++){
      cout << dp[i][str[i]-97] << endl;
    }
    return 0;
 }
