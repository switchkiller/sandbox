/* Problem Description:
  NA 
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
#define MAXN 300

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int mat[MAXN+10][MAXN+10] = {0}, visited[MAXN+10][MAXN+10] = {0};
int n;

void ff(int x, int y, int w){
  if (x > n-1 || y > n-1 || x < 0 || y < 0 || (w == 0) || visited[x][y]) return;
  visited[x][y] = 1;
  mat[x][y] += 1;
  REP(i,0,8)
    ff(x+dx[i],y+dy[i],w);
}

int floodfill(int x, int y, int w){
  RREP(i,w,0)
    ff(x,y,i);
  int res = 0;
  REP(i,0,n)
    REP(j,0,n)
      if (mat[i][j] > res) res = mat[i][j];
  return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    cin >> n;
    int m;
    cin >> m;
    int maxno = -inf;
    REP(i,0,m){
      int x, y, w;
      cin >> x >> y >> w;
      memset(visited, 0, sizeof visited);
      maxno = max(maxno, floodfill(x,y,w));
    }
    REP(i,0,n){
      REP(j,0,n){
        cout << mat[i][j] << " ";}
      cout << endl;
    }

    cout << maxno << endl;
    return 0;
 }
