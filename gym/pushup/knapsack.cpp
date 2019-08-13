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


int dp[1001][1001];
int n, w;
int arr[1001], val[1001];

int knapsack(){

  for (int i = 1; i <= w; i++){
    for (int j = 1; j <= n; j++){
      if (arr[j] <= i)
        dp[i][j] = max(val[j] + dp[i-arr[j]][j-1], dp[i][j-1]);
      else
        dp[i][j] = dp[i][j-1];
    }
  }
  return dp[w][n];
}


int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    cin >> n >> w;
	   for (int i = 1; i <= n; i++){
	        cin >> val[i];
	    }
      for (int i = 1; i <= n; i++){
          cin >> arr[i];
      }

	    for (int i = 1; i <= w; i++)
	        for (int j = 1; j <= n; j++) dp[i][j] = -0x3f3f3f3f;

      cout << knapsack() << endl;
	}
	return 0;
}
