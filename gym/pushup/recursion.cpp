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

int cnt = 0;

void recur(vector<int> &arr, int pos, int remain, int g, int sum, int n){
  // if (pos < g &&  == 0) return;
  if (pos > g || (sum >= n && pos < g)){
    return;
  } else {
    if (sum == n){
      for (int i = 0; i < g; i++){
        cout << arr[i] << " ";
      }
      cout << endl;
      cnt++;
      return;
    }
  }
  for (int i = remain; i >= 1; i--){
    arr[pos] = i;
    recur(arr, pos+1, i, g,sum+i,n);
  }
}

int dp[200][200];

int f(int n, int k){
  dp[0][0] = 1;
  for (int i=1; i<=n; i++)
    for (int j=1; j<= min(i, k); j++)
      dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];

  return dp[n][k];
}

void count(){
  vector<int> arr(201);
  recur(arr, 0, 200,200,0,200);
  cout << cnt << endl;
  // cout << f(8,4) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    count();
    return 0;
 }
