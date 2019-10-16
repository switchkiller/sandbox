// 01 Knapsack problem - Bottom Up
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, k;
    cin >> n >> k;
    int w[n+1], v[n+1];
    REP(i,1,n+1) cin >> v[i];
    REP(i,1,n+1) cin >> w[i];

    int dp[n+1][k+1];
    memset(dp, 0, sizeof dp);

    REP(i,1,n+1){
        REP(j,1,k+1){
            if (w[i] <= j){
                int rem = j-w[i];
                dp[i][j] = max(v[i]+dp[i-1][rem], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    // REP(i,0,n){
    //     cout << endl;
    //     REP(j,0,k+1)
    //         cout << dp[i][j] << " ";
    // }

    cout << dp[n][k];

  return 0;
}
