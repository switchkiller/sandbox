//Subset Sum Problem - Dynamic Programming
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, t;
    cin >> n >> t;
    int a[n];
    REP(i,0,n) cin >> a[i];
    bool dp[n+1][t+1];

    REP(i,0,n+1) dp[i][0] = true;

    REP(i,1,n+1){
        REP(j,1,t+1){
            if (j >= a[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    REP(i,0,n+1){
        cout << endl;
        REP(j,0,t+1)
            cout << dp[i][j] << " ";
    }

    cout << dp[n][t];


  return 0;
}
