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

#define MAX 100000
long long int n, m;
long long int lcm , mi;

long long int gcd(long long int a,long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void findlcm(long long int n, long long int m, int i){
  lcm = ((n+i) * (m+i)) / gcd(n+i,m+i);
}

int calculate(){
  int k = 1;
  REP(i,1,MAX)
  {
    findlcm(n,m,i);
    if(lcm < mi)
    {
      mi = lcm;
      k = i;
    }
  }
  return k;
}

int main()
{
	cin >> n >> m;
  findlcm(n,m,0);
	if(lcm == n || lcm == m)
		cout << "0" << endl;
  else{
    mi = lcm;
    int ans = calculate();
    cout << ans << endl;
  }
  return 0;
}
