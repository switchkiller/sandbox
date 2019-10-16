/* Problem Description:
  Can be solved using 1D DP too. Only 12/20 passed :o
  TODO
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n, w;
    cin >> n >> w;
    long weight[n+1]; int value[n+1];

    for (int i = 1; i <= n; i++){
      cin >> weight[i] >> value[i];
    }

    vector< vector<long> > dp(n*1001, vector<long>(n+1, inf));
    int ans = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n*1000; i++){
      for (int j = 1; j <= n; j++){
        if (i-value[j] >= 0){
          dp[i][j] = min(dp[i][j-1], weight[j] + dp[i-value[j]][j-1]);
        }
        else
        dp[i][j] = dp[i][j-1];
        if (dp[i][j] <= w) ans = max(ans, i);
      }
    }

    cout << ans << endl;

    return 0;
 }
