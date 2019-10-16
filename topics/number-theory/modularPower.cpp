#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)

long long modularPower(long long n, long long k, long long m=LLONG_MAX){
    long long ret = 1;
    while (k){
        if (k & 1) ret = (ret * n) % m;
        n = (n * n) % m;
        k >>= 1;
    }
    return ret;
}

int main(){
    long long n, k;
    cin >> n >> k;
    cout << modularPower(n,k);
    return 0;
}
