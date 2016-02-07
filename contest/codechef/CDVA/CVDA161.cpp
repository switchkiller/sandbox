#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (long i = (a); i <= (b); i += 2)
queue<long> Q;
int ind=1;
int operate(long N){
    if (N == 1)
        return
    if (N % 2 == 0){
        ind*=2;
        operate(N/2);
    }
    else{
        operate(N/2);



    }
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
