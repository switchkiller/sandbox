/* Problem Description: Messed up

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
int n, sq, temp;
int arr[100];
bool check(int mid){
  int sq, rem = mid, cnt = 0;
  for (int i = 0; i < n; i++){
    sq = sqrt(arr[i]);
    cout << sq << endl;
    cout <<arr[i] << " " <<  rem << " " << ((sq+1)*(sq+1) - arr[i]) << " " << arr[i] - (sq)*(sq) << endl;
    if (arr[i] = (sq)*(sq)){ cnt++; cout << cnt << endl; continue;}
    int mn = min((sq+1)*(sq+1) - arr[i],arr[i] - (sq)*(sq));
    if (rem >= mn){ rem -= mn; cnt++;}
    }
    cout << cnt << endl;
  }
  if (cnt >= (n/2)) return true;
  return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    cin >> n;
    REP(i,0,n){
      cin >> arr[i];
      sq = sqrt(arr[i]);
    }
    sort(arr,arr+n);
    int l = 0, r = 100;
    while (l < r){
      int mid = (l+r+1)/2;
      if (check(mid)) l = mid;
      else r = mid-1;
      cout << l << " " << r << endl;
    }
    cout << l << endl;
    return 0;
 }
