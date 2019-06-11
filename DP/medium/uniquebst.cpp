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

// recursive

// int func2(int n, int N);

int func1(int n){
  if (n == 0 || n == 1) return 1;
  int ans = 0;
  for (int x = 1; x <= n; x++){
    ans += func1(x-1)*func1(n-x);
    // ans += func2(x,n);
  }
  return ans;
}

// int func2(int n, int N){
//   return func1(n-1)*func1(N-n);
// }

// Dp approach
int dp[12];
int numTrees(int n){
  if (dp[n] != 0) return dp[n];
  for (int x = 1; x <= n; x++){
    dp[n] += numTrees(x-1)*numTrees(n-x);
  }
  return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    dp[0] = 1, dp[1] = 1;
    cin >> n;
    cout << numTrees(n) << endl;
    return 0;
 }
