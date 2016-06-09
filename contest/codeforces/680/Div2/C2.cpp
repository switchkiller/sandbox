// Using DP O(n) space
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

const int INF = -1000000007;
typedef long long ll;
typedef pair<ll, ll> ii;
ll m;
ii ans;
int main(){
    cin >> m;
    ll qrt;
    int dp[m+1]; memset(dp, 0, sizeof dp);
    for (ll i=1; i<=m; i++){
        ll temp = i;
        qrt = cbrt(temp);
        if (dp[qrt] == 0){
            dp[i]++;
            temp -= pow(qrt,3);
        }
        temp -= pow(qrt,3);
        dp[i] = 1 + dp[temp];
        if (ans < ii(dp[i],i)) ans = ii(dp[i],i);
    }
    cout << ans.first << " " << ans.second;
    return 0;
}
