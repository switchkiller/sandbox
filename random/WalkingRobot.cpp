/* Problem Description:
D. Walking Robot
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output

There is a robot staying at 𝑋=0 on the 𝑂𝑥 axis. He has to walk to 𝑋=𝑛. You are controlling this robot and controlling how he goes. The robot has a battery and an accumulator with a solar panel.

The 𝑖-th segment of the path (from 𝑋=𝑖−1 to 𝑋=𝑖) can be exposed to sunlight or not. The array 𝑠 denotes which segments are exposed to sunlight: if segment 𝑖 is exposed, then 𝑠𝑖=1, otherwise 𝑠𝑖=0.

The robot has one battery of capacity 𝑏 and one accumulator of capacity 𝑎. For each segment, you should choose which type of energy storage robot will use to go to the next point (it can be either battery or accumulator). If the robot goes using the battery, the current charge of the battery is decreased by one (the robot can't use the battery if its charge is zero). And if the robot goes using the accumulator, the current charge of the accumulator is decreased by one (and the robot also can't use the accumulator if its charge is zero).

If the current segment is exposed to sunlight and the robot goes through it using the battery, the charge of the accumulator increases by one (of course, its charge can't become higher than it's maximum capacity).

If accumulator is used to pass some segment, its charge decreases by 1 no matter if the segment is exposed or not.

You understand that it is not always possible to walk to 𝑋=𝑛. You want your robot to go as far as possible. Find the maximum number of segments of distance the robot can pass if you control him optimally.

Input
The first line of the input contains three integers 𝑛,𝑏,𝑎 (1≤𝑛,𝑏,𝑎≤2⋅105) — the robot's destination point, the battery capacity and the accumulator capacity, respectively.

The second line of the input contains 𝑛 integers 𝑠1,𝑠2,…,𝑠𝑛 (0≤𝑠𝑖≤1), where 𝑠𝑖 is 1 if the 𝑖-th segment of distance is exposed to sunlight, and 0 otherwise.

Output
Print one integer — the maximum number of segments the robot can pass if you control him optimally.

Examples
inputCopy
5 2 1
0 1 0 1 0
outputCopy
5
inputCopy
6 2 1
1 0 0 1 0 1
outputCopy
3

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
    int n, b, a;
    cin >> n >> b >> a;
    int val[n];
    REP(i,0,n)
      cin >> val[i];
    int MAX_LIMIT = a, ans = 0;
    REP(i,0,n){
      if (a==0 && b==0) break;
      if (val[i] == 0){
        if (a > 0) a--;
        else if (b > 0) b--;
      }
      else{
        if (b > 0){ // or simply if (b > 0 && a < MAX_LIMIT) {a = min (a+1, MAX_LIMIT); b--;}
          if (a == MAX_LIMIT) a--;
          else{ a++; b--;}
        }
        else a--;
      }
      ans++;
    }
    cout << ans << endl;
    return 0;
 }
