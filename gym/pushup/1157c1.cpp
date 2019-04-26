/* Problem Description:
  C1 - Increasing Subsequence (easy version)
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
    int arr[n+10];
    bool vis[n+10];
    REP(i,0,n){
      cin >> arr[i];
    }
    int moves[n+10];
    int x = 0;
    int i = 0, j = n-1;
    REP(i,0,n+10)
      vis[i] = false;
    while (i <= j){
      if (vis[arr[i]] && vis[arr[j]]){ break;}
      if (vis[arr[i]]) {  i++; moves[x++] = 0; vis[arr[j]] = true; vis[arr[j] - 1] = true; j--; continue;}
      if (vis[arr[j]]) {  j--; moves[x++] = 1; vis[arr[i]] = true; vis[arr[i] - 1] = true; i++; continue;}
        if (arr[i] < arr[j]){
          vis[arr[i]] = true;
          vis[arr[i] - 1] = true;
          moves[x++] = 1;
          i++;
        }
        else{
          vis[arr[j]] = true;
          vis[arr[j] - 1] = true;
          moves[x++] = 0;
          j--;
        }
    }
    cout << x << endl;
    REP(i,0,x)
    if (moves[i] == 1)
      cout << "L";
    else cout << "R";
    cout << endl;
    return 0;
 }
