/* Problem Description:
You are an avid rock collector who lives in southern California. Some rare and desirable rocks just became available in New York, so you are planning a cross-country road trip. There are several other rare rocks that you could pick up along the way. You have been given a grid filled with numbers, representing the number of rare rocks available in various cities across the country. Your objective is to find the optimal path from So_Cal to New_York that would allow you to accumulate the most rocks along the way.
Note: You can only travel either north (up) or east (right). b) Consider adding some additional tests in doTestsPass(). c) Implement optimalPath() correctly. d) Here is an example: ^ {{0, 0, 0, 0, 5}, New_York (finish) N {0, 1, 1, 1, 0}, So_Cal (start) {2, 0, 0, 0, 0}} S v The total for this example would be 10 (2+0+1+1+1+0+5)
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

int findMax(int matrix[][5],int n, int m){
  int dp[n+1][m+1];
  memset(dp, 0, sizeof dp);
  for (int col = 1; col <= m; col++){
    for (int row = n-1; row >= 0; row--){
      dp[row][col] = max(dp[row+1][col],dp[row][col-1])+matrix[row][col-1];
    }
  }

  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= m; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int matrix[][5] = {{0, 0, 0, 1, 5},
                      {0, 1, 0, -1, 0},
                      {2, 0, 11, -11, 0}};
    int n = 3, m = 5;

    cout << findMax(matrix,n,m);

    return 0;
 }
