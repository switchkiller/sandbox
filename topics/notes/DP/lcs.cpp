// LCS using DP - Bottom Up
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, m;
    string a,b;
    cin >> n >> m >> a >> b;

    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);

    REP(i,1,n+1){
        REP(j,1,m+1){
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    // REP(i,0,n+1){
    //     cout << endl;
    //     REP(j,0,m+1)
    //         cout << dp[i][j] << " ";
    // }

    cout << dp[n][m];
    
    return 0;
}
