/* Problem Description:
  Improvement can be done, Current implementation has run time complexity O(N*N). With binary search, it can be reduced to O(NlogN).
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
    int n;
    cin >> n;
    vector< pair<int,int> > timestamp(n+1);
    int dp[n+10];
    timestamp[0] = make_pair(-inf,-inf);
    for (int i = 1; i <= n; i++){
      int x, y;
      cin >> x >> y;
      timestamp[i] = make_pair(y,x);
      dp[i] = 1;
    }
    dp[0] = 0;

    sort(timestamp.begin(),timestamp.end());

    for (int i = 1; i <= n; i++){
      for (int j = i-1; j >= 1; j--){
        if (timestamp[j].first <= timestamp[i].second){
          dp[i] = dp[j] + 1;
          break;
        }
      }
      dp[i] += dp[i-1];
    }
    cout << dp[n] << endl;
    return 0;
 }
