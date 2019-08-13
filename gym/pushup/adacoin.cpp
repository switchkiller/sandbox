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

const int MAX = 1e5+10;
int arr[10001], n, q;
bool dp[10005][1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("ACACOIN-IN.txt" , "r" , stdin);
    freopen("ACACOIN-OUT.txt" , "w" , stdout);
    #endif
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
      cin >> arr[i];
    }
    for (int i = 0; i < 10005; i++)
      dp[0][i] = true;

    for (int i = 1 ; i < 10005; i++){
      for (int j = 1; j <= n; j++){
        if (i-arr[j] >= 0)
          dp[i][j] = dp[i][j-1] || dp[i-arr[j]][j-1];
        else dp[i][j] = dp[i][j-1];
      }
    }

    for (int i = 0; i < q; i++){
      int x, y;
        cin >> x >> y;
        int count = 0;
        for (int i = x; i <= y; i++){
          if (dp[i][n] == true) count++;
        }
        cout << count << endl;
    }
    return 0;
 }
