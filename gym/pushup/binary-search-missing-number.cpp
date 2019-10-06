/* Problem Description:
  Wrong manipulation somewhere..
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


int binary_search(int arr[], int low, int high){
  if (low < high){
    int mid = (low+high)/2;

    if (arr[mid] == mid+1){
      // we have not found missing number yet, move right
      return binary_search(arr, mid-1, high);
    } else if (arr[mid] > mid+1){
      // we have reached to index where there is imbalance, move left
      if ((mid-1 && (arr[mid-1] == mid)) || (mid == 0)){
        // this is the case we stop
        return mid;
      }
      return binary_search(arr,low,mid+1);
    } else{
      // do nothing - impossible case
    }
  }
  return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
      cin >> arr[i];
    }
    int ans = binary_search(arr,0,n-1);
    if (ans == -1)
      cout << "Not possible" << endl;
    else cout << ans+1 << endl;
    return 0;
 }
