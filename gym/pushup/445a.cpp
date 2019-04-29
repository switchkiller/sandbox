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

bool visited[100][100];
char arr[100][100];
char ans[100][100];
int dx[] = {-1,0,0,1};
int dy[] = {0, -1, 1, 0};
int n, m;
void dfs(int i, int j, bool color)
{ if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j]) return; visited[i][j] = true; if (arr[i][j] == '-'){ ans[i][j] = '-'; } else{ if (color == true) ans[i][j] = 'B'; else ans[i][j] = 'W'; } for (int x = 0; x < 4; ++x) dfs(i+dx[x], j+dy[x], !(color)); }

int main(){ cin >> n >> m; for (int i = 0; i < n; ++i){ for (int j = 0; j < m; ++j){ cin >> arr[i][j]; } } dfs(0,0, true); for (int i = 0; i < n; ++i){ for (int j = 0; j < m; ++j){ cout << ans[i][j]; } cout << endl; } return 0; }
