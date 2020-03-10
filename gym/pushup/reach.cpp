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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    cin >> n;
    vector<int> graph[n];
    for (int i = 0; i < n; i++){
      int a, b;
      cin >> a >> b;
      a--, b--;
      graph[a].push_back(b);
    }
    int host;
    cin >> host;
    vector<int> res;
    priority_queue<int, vector<int>, greater<int> > a;
    priority_queue<int, vector<int>, greater<int> > b;
    a.push(host-1);
    int sz = 1;
    while(!a.empty()){
      int top = a.top();
      a.pop();
      sz--;
      res.push_back(top);
      for (auto x : graph[top]){
        b.push(x);
      }
      if (sz == 0){
        a = b;
        while(!b.empty()){
          b.pop();
        }
        sz = a.size();
      }
    }
    for (int i = 1; i < res.size(); i++){
      cout << res[i]+1 << endl;
    }
    return 0;
 }
