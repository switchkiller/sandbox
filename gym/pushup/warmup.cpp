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

int func(int n, int pw, int init){
    if (n < 0) return 0;
    if (n == 0) return 1;
    int ways = 0;
    for (int x = init+1; pow(x,pw) <= n; x++){
        ways += func(n-pow(x,pw),pw,x);
    }
    return ways;
}

int main() {
	//code
	int t, n, pw;
	cin >> t;
	while(t--){
    	cin >> n >> pw;
    	cout << func(n,pw,0) << endl;
	}
	return 0;
}
/*
int dp[10000+10][100+10];
int func(int n, int pw, int init){
    if (n < 0) return 0;
    if (dp[n][init+1] != 0) return dp[n][init+1];
    int x;
    for (x = init+1; pow(x,pw) <= n; x++){
        dp[n][x] = dp[n][x-1] + func(n-pow(x,pw),pw,x);
    }
    return dp[n][x-1];
}

int main() {
	//code
	int t, n, pw;
	cin >> t;
	while(t--){
    	cin >> n >> pw;
    	memset(dp, 0, sizeof dp);
    	for (int i = 0; i <= 100; i++)
    	    dp[0][i] = 1;
    	for (int i = 0; i <= 10000; i++)
    	    dp[i][0] = 0;
    	cout << func(n,pw,0) << endl;
	}
	return 0;
}
*/
