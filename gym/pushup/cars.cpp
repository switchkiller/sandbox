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


string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'carParkingRoof' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY cars
 *  2. INTEGER k
 */

 bool predicate(const vector<long>& cars, long mid, int n, int k){
     for (int i = 0; i <= n-k; i++){
         int sum = 0;
         sum = cars[i+k-1]-cars[i]+1;
         if (sum <= mid){
            return true;
         }
     }
     return false;
 }

long carParkingRoof(vector<long> cars, int k) {
    sort(cars.begin(),cars.end());
    int n = cars.size();
    long mx = -1;

    long low = 0, high = cars[n-1];

    while (low < high){
        long mid = (low+high)/2;
        if (predicate(cars,mid,n,k))
        {
          high = mid;
        }else {
            low = mid+1;
        }
    }
    return high;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<long> cars;
  for (int i = 0; i < n; i++){
    long x;
    cin >> x;
    cars.push_back(x);
  }

  cout << carParkingRoof(cars,k) << endl;
  return 0;

}
