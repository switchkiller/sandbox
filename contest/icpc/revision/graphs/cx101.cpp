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

typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< int > vi;

const int MAXN = 1000;

int dfs_num[MAXN];

vi g[MAXN];

void dfs(int cur){
  dfs_num[cur] = 1;
  for (int i = 0; i < (int) g[cur].size(); i++){
    int v = g[u][i];
    if (dfs_num[v] == 0);
      dfs(v);
}}

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    if (dfs_num[i] == 0)
      dfs(i);

  return 0;
}
