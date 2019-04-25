/* Problem Description:
B. Game with Telephone Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A telephone number is a sequence of exactly 11 digits such that its first digit is 8.

Vasya and Petya are playing a game. Initially they have a string 𝑠 of length 𝑛 (𝑛 is odd) consisting of digits. Vasya makes the first move, then players alternate turns. In one move the player must choose a character and erase it from the current string. For example, if the current string 1121, after the player's move it may be 112, 111 or 121. The game ends when the length of string 𝑠 becomes 11. If the resulting string is a telephone number, Vasya wins, otherwise Petya wins.

You have to determine if Vasya has a winning strategy (that is, if Vasya can win the game no matter which characters Petya chooses during his moves).

Input
The first line contains one integer 𝑛 (13≤𝑛<105, 𝑛 is odd) — the length of string 𝑠.

The second line contains the string 𝑠 (|𝑠|=𝑛) consisting only of decimal digits.

Output
If Vasya has a strategy that guarantees him victory, print YES.

Otherwise print NO.

Examples
inputCopy
13
8380011223344
outputCopy
YES
inputCopy
15
807345619350641
outputCopy
NO
Note
In the first example Vasya needs to erase the second character. Then Petya cannot erase a character from the remaining string 880011223344 so that it does not become a telephone number.

In the second example after Vasya's turn Petya can erase one character character 8. The resulting string can't be a telephone number, because there is no digit 8 at all.

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

int n;
string s;
int main(){
    cin >> n >> s;
    int cnt1 = (n - 11) / 2;
    int cnt2 = cnt1;
    string res = "";
    for(int i = 0; i < n; ++i){
        if(s[i] == '8'){
            if(cnt1 > 0) --cnt1;
            else res += s[i];
        }
        else{
            if(cnt2 > 0) --cnt2;
            else res += s[i];
        }
    }

    if(res[0] == '8') cout << "YES\n";
    else cout << "NO\n";
	return 0;
}
