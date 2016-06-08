// Cursed Query

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, q;
    cin >> n >> q;
    int a[n+1]; long long s[n+1]; s[0] = 0;
    REP(i,1,n+1){
        cin >> a[i];
        s[i] = 1LL * (s[i-1] + a[i]);
    }
    long long t;
    while(q--){
        cin >> t;
        t %= s[n];
        cout << lower_bound(s, s+n+1, t+1LL) - s<< endl;
    }
    return 0;
}
