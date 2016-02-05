#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (long i = (a); i <= (b); i += 2)
queue<long> Q;
void operate(){
    long val;
    while (!Q.empty()){
        val = Q.front(); Q.pop();
        Q.push(Q.front()); Q.pop();}
    cout << val << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    long T;
    long N;
    cin >> T;
    while(T--){
        cin >> N;
        if (N % 2 == 0){
            REP(i,2,N)
                Q.push(i);
            operate();}
        else{
            REP(i,2,N-1)
                Q.push(i);
            Q.push(Q.front()); Q.pop();
            operate();
        }
    }
    return 0;
}
