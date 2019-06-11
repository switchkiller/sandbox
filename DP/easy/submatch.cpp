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

int subsequenceCount(string S, string T);
//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;

		cout<<subsequenceCount(s,tt)<<endl;


	}

}


/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
//banana ban
//if S and T current character match -> move to next character
// if no match between S and T current character -> move S to next pointer
// Base case T == '\0' return 1;




int subs(string S, string T, int i=0, int j=0)
{
  //Your code here
 if (S[i] == '\0' && T[j] != '\0') return 0;
 if (T[j] == '\0') return 1;
 int val1 = 0, val2 = 0;
 if (S[i] == S[j])
  val1 = subs(S,T,i+1,j+1);
  val2 = subs(S,T,i+1,j);
  return val1+val2;
}

int subsequenceCount(string S, string T)
{
  //Your code here
    return subs(S,T,0,0);
}
