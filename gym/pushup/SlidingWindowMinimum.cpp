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

string minWindow(string s, string t) {
  int start = 0;
  int maxLen = INT_MAX, m = s.length(), n = t.length();
  int hash[256] = {0};
  if (m == 0 || m < n) return "";
  for (int i = 0; i < n; i++){
    hash[t[i]]++;
  }
  int count = 0, maxIdx = 0;
  for (int end = 0; end < m; end++){
      hash[s[end]]--;
      if (hash[s[end]] >= 0){
          count++;
      }
      while(count == n){
        if (maxLen > (end-start+1)){
          maxLen = end-start+1;
          maxIdx = start;
        }
        hash[s[start]]++;
        if (hash[s[start]] > 0) count--;
        start++;
      }
  }
  return (maxLen == INT_MAX) ? "" : s.substr(maxIdx, maxLen);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    return 0;
 }
