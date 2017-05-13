/* Problem Description:

*/

#include<bits/stdc++.h>

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

#define N 1000

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t, n, sum;
    cin >> t;
    REP(i,0,t){
      cin >> n >> sum;
      int arr[n];
      REP(j,0,n)
        cin >> arr[j];
      int start = 0, curr_sum = arr[0];
      REP(j,1,n+1){
        // when should we add the new element?
        // while curr_sum already exceed sum, we increase start pointer
        while (curr_sum > sum && start < j-1){
          curr_sum -= arr[start];
          start++;
        }
        // debug(start);
        // if curr_sum is equal to sum print range
        if (curr_sum == sum)
          cout << start << " " <<  j-1 << endl;
        if (j < n) // keep in mind the extra iteration
        curr_sum += arr[j];
        // debug(curr_sum);
      }
    }
    return 0;
 }
