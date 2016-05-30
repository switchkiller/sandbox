// Bears and Colors - Tricky
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int n, num[5010];

int main(){
    cin >> n;
    REP(i,1,n+1) cin >> num[i];
    int ans[n+10], cnt[n+10];
    memset(ans, 0, sizeof ans);
    REP(i,1,n+1){
        int sum=0, ptr=0;
        memset(cnt, 0, sizeof cnt);
        REP(j,i,n+1){
            cnt[num[j]]++;
            if (sum < cnt[num[j]] || (ptr > num[j] && sum == cnt[num[j]])){
                sum = cnt[num[j]];
                ptr = num[j];
            }
            ans[ptr]++;
        }
    }

    REP(i,1,n+1){
        if (i) cout << " ";
        cout << ans[i];
    }
  return 0;
}
