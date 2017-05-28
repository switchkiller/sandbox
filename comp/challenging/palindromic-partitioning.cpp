/* Problem Description:
   Create minimum number of palindromic partitions.
   #tricky #tough
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

#define MAX 100

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
      int dp[MAX][MAX];
      char str[MAX];

      cin >> str;
      int n = strlen(str);
      // For length 1
      for (int i = 0; i < n; ++i)
        dp[i][i] = 1;
      // For length greater than 2
      for(int len = 2; len <= n; ++len){
        for (int i = 0; i < n-len+1; ++i){
          int j = i+len-1;
          if (len == 2)
            dp[i][j] = (str[i] == str[j]);
          else
            dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]);
        }
      }

      // for (int i = 0; i < n; i++){
      //   for (int j = 0; j < n; j++)
      //     cout << dp[i][j] << " ";
      //   cout << endl;
      // }

      int ans[MAX];
      for (int i = 0; i < n; ++i){
        if (dp[0][i])
          ans[i] = 0;
        else{
          ans[i] = inf;
          for (int j = 0; j < i; ++j)
            if (dp[j+1][i] && 1 + ans[j] < ans[i])
              ans[i] = 1 + ans[j];
        }
      }
      cout << ans[n-1] << endl;
    }
    return 0;
 }
