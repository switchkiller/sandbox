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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    cin >> n;
    vector<int> population(n,0);
    vector<int> milkConsumption(n,0);

    for (int i = 0; i < n; i++)
      cin >> population[i];

    int max_milk_consumption = 0;
    for (int i = 0; i < n; i++){
      cin >> milkConsumption[i];
      max_milk_consumption += milkConsumption[i];
    }

    vector< vector<int> > dp(max_milk_consumption+1, vector<int> (n+1, inf));

    for (int i = 0; i <= n; i++){
      dp[0][i] = 0;
    }

    for (int consumption = 1; consumption <= max_milk_consumption; consumption++ ){
      for (int iterate = 1; iterate <= n; iterate++){
        if (consumption-milkConsumption[iterate-1] >= 0)
          dp[consumption][iterate] = min(dp[consumption][iterate-1], population[iterate-1] + dp[consumption-milkConsumption[iterate-1]][iterate-1]);
        else
          dp[consumption][iterate] = dp[consumption][iterate-1];
      }
    }

    // Here dp[i][n] gives desired population size.
    // we are looking for max_ratio = i / dp[i][n] 


    return 0;
 }
