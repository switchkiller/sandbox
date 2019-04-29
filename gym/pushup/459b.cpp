/* Problem Description:
B. Pashmak and Flowers
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
    ll n; ll ans = 0;
    bool flag = true;
    cin >> n;
    ll arr[n];
    REP(i,0,n) cin >> arr[i];
    REP(i,0,n-1) if (arr[i] != arr[i+1]) flag = false;
    if (flag == true){
      ans = n * (n-1) / 2;
      cout << "0" << " " << ans << endl;
      return 0;
    } else {
      ll cnt1, cnt2;
      ll mn = INT_MAX, mx = INT_MIN;
      REP(i,0,n){
        if (mn >= arr[i]){
          if (mn == arr[i]) cnt1++;
          else{
            cnt1 = 1;
            mn = arr[i];
          }
        }
        if (mx <= arr[i]){
          if (mx == arr[i]) cnt2++;
          else{
            cnt2 = 1;
            mx = arr[i];
          }
        }
      }
      ans = cnt1 * cnt2;
      cout << mx - mn << " " << ans << endl;
    }
    return 0;
 }
