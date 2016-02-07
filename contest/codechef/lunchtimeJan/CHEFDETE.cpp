
#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define TRv(c, val, it) (map<int, int>::iterator it = c.find(val)
int main(){
    int N, start;
    map<int, int> mp;
    cin >> N;
    REP(i,1,N+1){
        cin >> mp[i];
        if (mp[i] == 0) start = i;}
    while(1){
        TRv(mp,start,it);

    }
    return 0;
}
