// A. Vanya and Fence
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, k, s=0;
    cin >> n >> k;
    int a[n];
    REP(i,0,n){
        cin >> a[i];
        if (a[i] > k)
            s += 2;
        else
            s++;
    }
    cout << s << endl;
    return 0;
}
