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
    int n, k;
    cin >> n >> k;
    stack<ii> sii;
    int num = 0, den = 1, cnt = 1, dval = 1, nval = n;
    sii.push(mp(dval,nval));
    if (n == 1 && k == 2){ cout << "1/2" << endl; return 0;}
    while(nval > 1){
      while(!sii.empty()){
        if (cnt == k){
          cout << num << "/" << den << endl;
          return 0;
        }
        while (sii.top().second + den <= n)
          sii.push(mp(num+sii.top().first, den+sii.top().second));
        ii temp = sii.top(); sii.pop();
        num = temp.first, den = temp.second;
        cnt++;
      }
      nval--;
      sii.push(mp(dval, nval));
    }
    if (cnt == k)
      cout << num << "/" << den << endl;
    return 0;
 }
