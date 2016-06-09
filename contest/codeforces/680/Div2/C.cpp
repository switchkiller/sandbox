// Naive
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

const int INF = -1000000007;

int m,maxn=INF, maxv=-INF;

void process(int val){
    int temp=0, tvol=val;
    while(val){
        int qroot = cbrt(val);
        val -= pow(qroot,3);
        temp++;
    }
    if (maxn < temp){
        maxn = temp;
        if (maxv > tvol)
            maxv = tvol;
    }
}

int main(){
    cin >> m;
    while(m){
        process(m);
        m--;
    }
    cout << maxn << " "  << maxv << endl;
    return 0;
}
