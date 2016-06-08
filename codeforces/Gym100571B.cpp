// Amazing question - Pending
// This question is variant to A. Both are based on partial sum.
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

const int mod = 1e9+7;

int main(){
    int n, q, x, y, a, b;
    cin >> n >> q; int f[n+1];
    cin >> f[1] >> f[2];
    cin >> a >> b;
    REP(i,3,n+1)
        f[i] = a*f[i-2] + b*f[i-1];
    int v[n+1];
    REP(i,1,n) cin >> v[i];
    int l, r;
    while (q--){
        cin >> l > r;

        REP()


    }




    return 0;
}
