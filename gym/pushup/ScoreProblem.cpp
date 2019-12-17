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

vector<int> graph[MAX];

// ignore cycle in same graph
int score[MAX];
int dfs(int cur, int parent){
    int temp = INT_MIN;
    for (auto adj : graph[cur]){
      temp = max(temp, dfs(adj,cur));
    }
    if (temp == INT_MIN) temp = 0;
    return 1+temp;
}

int findMinimumScore (vector<int> A, int N) {
   // Write your code here

   for (int i = 0; i < N-1; i++){
       int x = A[i]-1;
       graph[x].push_back(i+1);
    //   cout << x << " " << i+1 << endl;
   }
   // begin from 0 as we are sure 1 always wins
   return dfs(0, -1)-1;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N-1);
    for(int i_A=0; i_A<N-1; i_A++)
    {
    	cin >> A[i_A];
    }

    int out_;
    out_ = findMinimumScore(A, N);
    cout << out_;
    return 0;
}
