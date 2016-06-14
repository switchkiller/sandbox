
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define inf 0x3f3f3f3f

int n;
int main(){
    cin >> n;
    char sname[10];
    int x, y, flag = 0;
    FOR(i,1,n){
        cin >> sname >> x >> y;
        if (x >= 2400 && y - x > 0 && flag != 1)
            flag = 1;
    }

    if (flag == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
