//
// row col
// word
//
// ****

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

int row, col;
string mat[101];

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

bool visited[101][101];

bool dfs(string str, int i, int j, int pos){
  if ( i < 0 || j < 0 || i >= row || j >= col) return false;

  if (pos == str.length()) return true;

  if (pos <= str.length() && str[pos] != mat[i][j]) return false;

  visited[i][j] = true;

  bool ret = false;

  for (int x = 0; x < 4; x++){
    if (!visited[i+dx[x]][j+dy[x]]){
      ret |= dfs(str,i+dx[x],j+dy[x], pos+1);
    }
  }

  return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    cin >> row >> col;

    for (int i = 0; i < row; i++){
      cin >> mat[i];
    }

    string str;
    cin >> str;

    for (int i = 0; i < row; i++){
      for(int j = 0; j < mat[i].length(); j++){
        if (str[0] == mat[i][j]){
          if (dfs(str,i,j,0)){
            cout << "YES";
          }
          memset(visited, false, sizeof visited);
        }
      }
    }

    return 0;
 }
