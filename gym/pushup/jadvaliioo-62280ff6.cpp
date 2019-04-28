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
int n, m;
char arr[100+1][100+1];
int cnt;
int dx[] = {0, 1, 1, 1};
int dy[] = {1, 1, 0, -1};
int visited[100+1][100+1];
string s = "saba";
int solve(int i, int j, int pos, int x, int y){
  if (pos == s.length()) return 1;
  if (i < 0 || i >= n || j < 0 || j >= m) return 0;
  if (arr[i][j] != s[pos]) return 0;
  return solve(i+x, j+y, pos+1,x,y);
}

void solveUtils(){
  REP(i, 0, n)
    REP(j,0,m){
      REP(d,0,4)
      cnt += solve(i, j, 0, dy[d], dx[d]);}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    cin >> n >> m;

    REP(i, 0, n)
      REP(j,0,m)
        cin >> arr[i][j];

    solveUtils();
    cout << cnt << endl;
    return 0;
 }
