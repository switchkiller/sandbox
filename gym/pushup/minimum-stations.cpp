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

const int N = 1e5+10;

bool compare(ii a, ii b){
  return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    vector< pair<int,int> > arr(N,0);

    int t,n;
    cin >> t;
    while (t--){
      cin >> n;
      int start[n], end[n];
      for (int i = 0; i < n; i++){
        cin >> start[i];
      }
      for (int i = 0; i < n; i++){
        cin >> end[i];
      }

      for (int i = 0; i < n; i++){
        arr[i].push_back({start[i],end[i]});
      }

      sort(arr.begin(),arr.end(),compare);

      int maxVal = -1;
      for (auto itr = arr.begin(); itr != arr.end(); itr++){
        int curMax = 1;
        int tp = itr->second;
        for (auto it = itr+1; it != arr.end(); it++){
          if (it->first <= tp){
            curMax++;
            arr.erase(it);
          }
        }
        maxVal = max(maxVal,curMax);
      }
      cout << maxVal << endl;
    }
    return 0;
 }
