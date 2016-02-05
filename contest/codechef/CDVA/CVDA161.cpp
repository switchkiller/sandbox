#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (long i = (a); i <= (b); i += 2)
vector<long> vl;
int ind=0;
int operate(long N){
    if (N == 1)
        return
    if (N % 2 == 0)
        operate(N/2);
    else



}
int main(){
    ios_base::sync_with_stdio(0);
    int T;
    long N;
    cin >> T;
    while(T--){
        cin >> N;
        operate(N);  }
    return 0;
}
