#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

int n;
char cmd[5050][3];
ll dp[5050][5050][2];

ll f(int in, int cnt, int con) {
    if(cnt < 0 || in > n) return 0;
    if(in == n && !cnt) return 1;
    if(dp[in][cnt][con] != -1) return dp[in][cnt][con];
    int ans = 0;

    if(cmd[in][0] == 'f') ans += f(in+1, cnt+1, 1);
    else ans += f(in+1, cnt, 0);
    if(!con) ans += f(in, cnt-1, 0);

    return dp[in][cnt][con] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
//        getchar();
        scanf("%s", &cmd[i]);
    }

    cout << f(0,0,0) << endl;

//    printf("%lld\n", f(0, 0, 0));
}
