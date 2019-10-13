/* Problem Description:
    // some cases are to to be handled
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
    int arr[n];

    for (int i = 0; i < n; i++){
      cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int> > positiveNumberMinHeap;
    priority_queue<int> negativeNumberMinHeap;

    for (int i = 0; i < n; i++){
      if (arr[i] > 0){
        // positive Number case
        if (positiveNumberMinHeap.size() < 3){
          positiveNumberMinHeap.push(arr[i]);
          continue;
        }
          int top = positiveNumberMinHeap.top();
          if (top < arr[i]){
            positiveNumberMinHeap.pop();
            positiveNumberMinHeap.push(arr[i]);
          }
      } else{
        // Negative number case
        if (negativeNumberMinHeap.size() < 2){
          negativeNumberMinHeap.push(arr[i]);
          continue;
        }
          int top = negativeNumberMinHeap.top();
          if (top > arr[i]){
            negativeNumberMinHeap.pop();
            negativeNumberMinHeap.push(arr[i]);
          }
      }
    }

    int max1 = 1, max2 = 1;
    int last = 0;
    while(!positiveNumberMinHeap.empty()){
      last = positiveNumberMinHeap.top();
      positiveNumberMinHeap.pop();
      max1 *= last;
      cout << last << endl;
    }
    int last2;
    while(!negativeNumberMinHeap.empty()){
      last2 = negativeNumberMinHeap.top();
      negativeNumberMinHeap.pop();
      max2 *= last2;
      cout << last2 << endl;
    }
    max2 *= last;
    if (max1 < max2){
      cout << max2 << endl;
    } else {
      cout << max1 << endl;
    }
    return 0;
 }
