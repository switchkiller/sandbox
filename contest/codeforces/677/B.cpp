// B. Vanya and Food Processor
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, h, k;
    cin >> n >> h >> k;
    int a[n], s=0, cnt=0, flag=0, temp;
    REP(i,0,n){
        cin >> a[i];
        if (flag == 0)
            temp = a[i];
        else
            temp += a[i];
        if (temp % k != 0){
            temp = (a[i] % k);
            cnt ++;
            flag = 1;
        }
        else
            flag = 0;
        s += a[i];
    }
    int x = (s % k);
    int ans = (s / k) + x + cnt;
    cout << ans;
    return 0;
}
