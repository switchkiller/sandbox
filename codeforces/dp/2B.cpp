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

const int N = 1000+10;

int dp[N][N];

int numPF(ll n, int p){
  int ans = 0;
  while(n % p == 0) {n /= p; ans++;}
  return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int arr[N][N];
    int n;
    memset(dp, 1, sizeof dp);
    cin >> n;
    FOR(i,1,n){
      FOR(j,1,n){
        cin >> arr[i][j];
      }
    }
    FOR(i,1,n){
      FOR(j,1,n){
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) * pow(2,numPF(arr[i][j], 2)) * pow(5, numPF(arr[i][j], 5));
        cout <<pow(2,numPF(arr[i][j], 2)) << " " << pow(5,numPF(arr[i][j], 5));
      }
      cout << endl;
    }

    // FOR(i,1,n){
    //   FOR(j,1,n){
    //   cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    // cout << dp[n][n];

    return 0;
 }
