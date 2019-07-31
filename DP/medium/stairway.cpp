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

const int N = 1000;

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
      int dp[N][2], n, k, penalty;
      cin >> n >> k >> penalty;
      int arr[n], brr[n];
      for(int i = 0; i <= n; i++){
        dp[i][0] = inf;
        dp[i][1] = inf;
      }

      for(int i = 0; i < n; i++){
        cin >> arr[i];
      }

      for(int i = 0; i < n; i++){
        cin >> brr[i];
      }

      dp[0][0] = 0, dp[0][1] = 0;
      dp[1][0] = min(arr[0],brr[0]+penalty);
      dp[1][1] = min(brr[0],arr[0]+penalty);
      for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
          int cost1, cost2;
          if (i+j-1 < n){
            cost1 = min(dp[i][0]+arr[i+j-1], dp[i][1]+brr[i+j-1]+penalty);
            cost2 = min(dp[i][1] + brr[i+j-1], dp[i][0]+arr[i+j-1]+penalty);
            dp[i+j][0] = min(dp[i+j][0], cost1);
            dp[i+j][1] = min(dp[i+j][1], cost2);
          }
        }
      }

      cout << min(dp[n][0],dp[n][1]) << endl;
    }

    return 0;
 }
