/* Problem Description: A. Diverse Strings


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
    for (int i = 0; i < n; i++){
      char inputStr[101];
      int cnt[26+1];
      memset(cnt, 0, sizeof cnt);
      cin >> inputStr;
      if (strlen(inputStr) == 1) { cout << "YES" << endl; continue;}
      if (strlen(inputStr) > 26) {cout << "NO" << endl; continue;}
      for (int j = 0; j < strlen(inputStr); j++){
        cnt[inputStr[j] - 95]++;
      }
      int flag = 0;
      for (int j = 0; j < strlen(inputStr); j++){
        if ((cnt[inputStr[j] - 95 + 1] == 1) || (cnt[inputStr[j] - 95 -1] == 1)) flag = 1;
        else {
          flag = 0;
          break;
        }
      }
      if (flag == 1) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    return 0;
 }
