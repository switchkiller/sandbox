// Sometimes going for optimised solutions sucks. Some naive got accepted -- EASY goin
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)

int main(){
    int P[] = {1234, 123456, 1234567};
    long n; int flag=0;
    cin >> n;
    if (n < 1359257){
        cout << "NO";
        return 0;
    }
    else{
        int a = (n - P[1] - P[0]) / P[2];
        int b = (n - a*P[2] - P[0]) / P[1];
        int c = (n - a*P[2] - b*P[1]) / P[0];

        if (!(a || b || c )) {
            cout << "NO" << endl; return 0;
        }

        FOR(i, 1, a)
            FOR(j, 1, b)
                FOR(k, 1, c)
                    if (i*P[2] + j*P[1] + k*P[0] == n){
                        cout << "YES" << endl; flag = 1; break; }
    }
    if (flag == 0)
        cout << "NO" << endl;
    return 0;
}
