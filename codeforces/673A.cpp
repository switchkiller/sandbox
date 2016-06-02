// A. Bear and Game
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (i = (a); i < (b); i++)
#define RREP(i,a,b) for (i = (a); i > (b); i--)

int main(){
    int n;
    cin >> n;
    int a[n+1], i; a[0] = 0;
    for (i = (1); i <= (n); i++){
         cin >> a[i];
         if (a[i] - a[i-1] > 15 )
             break;
    }
    cout << min(a[i-1]+15, 90);
    return 0;
}
