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


const int N = 110;

int dp[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("Bin.txt" , "r" , stdin);
    //  freopen("Bout.txt" , "w" , stdout);
    #endif
    int t;
    cin >> t;
    REP(i,0,t){
      int r, c;
      cin >> r >> c;
      int cnt = 0;
      memset(dp, -1, sizeof dp);      // cout << dp[1][1];
      FOR(x,1,r){
        FOR(y,1,c){
          if (dp[x][y] == 0) continue;
          if (dp[x][y] == -1){
            dp[x][y] = 1;
            cnt++;
          }
          if (dp[x][y-1] == 1) dp[x][y+1] = 0;
          if (dp[x-1][y] == 1) dp[x+1][y] = 0;
        }
      }
      // FOR(x,0,r){
      //   FOR(y,0,c){
      //     cout << dp[x][y] << " ";
      //   }
      //   cout << endl;
      // }


      cout << "Case #" << i+1 << ": " << cnt << endl;
    }

    return 0;
 }
