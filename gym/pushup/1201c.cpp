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

ll n, k;
vector<ll> arr;

bool check(ll x){
  int moves = 0;
  for(int i = n/2; i < n; i++){
    if (x - arr[i] > 0) moves += x-arr[i];
    if (moves > k) return false;
  }
  if (moves <= k) return true;
  else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    // arr[] = {1,2,3,4,5}
    // arr[] = {1,2,3,4,5,6,7,8,9}

    // use binary search and check that specific value doesnt exceed k

    cin >> n >> k;
    for (int i = 0; i < n; i++){
      ll x;
      cin >> x;
      arr.pb(x);
    }

    ll low = 1, high = 2000000000;
    sort(arr.begin(),arr.end());

    while (low < high){
      ll mid = (low + high+1)/2;
      if (check(mid)){
        low = mid;
      }
      else {
        high = mid-1;
      }
    }
    cout << low << endl;

    return 0;
 }
