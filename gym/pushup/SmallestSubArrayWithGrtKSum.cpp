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
#define INT_MAX 0x3f3f3f3f
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t, n, k;
    cin >> t;
    while(t--){
        cin >>n >> k;
        int arr[n];
        for(int i = 0; i < n; i++){
          cin >> arr[i];
        }

        int start = 0, minLength = INT_MAX;
        int curr_sum = 0;
        for (int end = 0; end < n; end++){
          curr_sum += arr[end];
          if (curr_sum > k){
            int temp_curr_sum = curr_sum, prev_start = start;
            while(prev_start < end){
              temp_curr_sum -= arr[prev_start];
              prev_start++;
              if (temp_curr_sum > k){
                minLength = min(minLength,end-prev_start+1);
                start = prev_start;
              }
            }
            minLength = min(minLength,end-start+1);
          }
        }

        if (minLength == INT_MAX)
            cout << "Not possible";
        else
            cout << minLength << endl;
    }
    return 0;
 }
