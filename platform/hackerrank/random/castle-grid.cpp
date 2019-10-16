/* Problem Description:
    Castle-Grid
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

#define up(x1,y1,x2,y2) (y1 == y2 && x2 < x1)
#define down(x1,y1,x2,y2) (y1 == y2 && x2 > x1)
#define left(x1,y1,x2,y2) (x1 == x2 && y2 < y1)
#define right(x1,y1,x2,y2) (x1 == x2 && y2 > y1)
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
int tag = 0;
bool visited[110][110];
char graph[110][110];
int ans = 0;
void bfs(int x, int y, int dx, int dy){
  pair<int, int> xy;
  xy = {x,y};
  queue< pair<int, int> > q;
  q.push(xy);
  visited[x][y] = true;
  int cnt = 0;
  while(!q.empty()){
    xy = q.front();
    q.pop();
    x = xy->first, y = xy->second;
    if (x >= 0 && y >= 0 && x < n && y < n && graph[x][y] != 'X'){
      if (x == dx && y == dy){ans = cnt; return;}
      // stuck in finding the steps
      q.push({x-1, y}); q.push({x+1, y}); q.push({x, y-1}); q.push({x, y+1});
    }
  }
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
    for (int i = 0; i < n; i++)
      cin >> graph[i];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1, y1, x2, y2);
    cout << cnt << endl;
    return 0;
 }
