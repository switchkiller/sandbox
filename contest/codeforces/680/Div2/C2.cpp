// Using DP O(n) space for small m
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

const int INF = -1000000007;
typedef pair<int, int> ii;
int m;

ii ans;
int main(){
    cin >> m;
    int qrt, rem;
    vector<int> dp(m+1);
    REP(i,1,m+1){
        int temp = i;
        while (temp){
            qrt = cbrt(temp);
            if (dp[qrt] == 0){
                dp[i]++;
                temp -= pow(qrt,3);
            }
            else{
                dp[i]++;
                temp -= pow(qrt,3);
            }
            if (ans < ii(dp[i],i)) ans = ii(dp[i],i);
        }
    }

    // REP(i,1,m+1)
    //     cout << i << " " << dp[i] << endl;

    cout << ans.first << " " << ans.second;

    return 0;
}
