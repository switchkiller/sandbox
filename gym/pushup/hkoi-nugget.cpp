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



//https://assets.hkoi.org/training2018/J181.pdf


void subtask_1(){
	int w2, w4, k2, k4, x, cost = 0, ans = 0x3f3f3f3f;
	cin >> w2 >> w4;
	cin >> x;
	for (k4 = 0; k4 < x/4; k4++){
		k2 = (x-k4*4)/2;
    cout << k2 << endl;
		cost = k2*w2+k4*w4;
		ans = min (ans, cost);
	}
	cout << ans << endl;
}

int main(){
	int x;
	cin >> x;
	switch(x){
		case 1:
			subtask_1();
			break;
		default:
			break;
	}
	return 0;
}
