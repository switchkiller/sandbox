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

long barn[100005];

bool satisfy(long x, int c, int n){
  int count = 1, pos = barn[0];
  for (int i = 1; i < n; i++){
    if (barn[i]-pos >= x){
      count++;
      pos = barn[i];
      if (count == c) return true;
    }
  }
  return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
      int n, c;
      cin >> n >> c;
      for (int i = 0; i < n; i++){
        cin >> barn[i];
      }

      sort(barn,barn+n);

      long low = 0, high = LONG_MAX;
      long ans = INT_MIN;
      while (low < high){
        long mid = low + (high-low)/2;
        if (satisfy(mid, c, n)){
          ans = max(ans, low);
          low = mid+1;
        } else {
          high = mid;
        }
      }

      cout << ans << endl;
    }
    return 0;
 }
