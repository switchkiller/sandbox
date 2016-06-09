// B. Bear and Finding Criminals

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)

int main(){
    int n, a;
    cin >> n >> a;
    int arr[n];
    REP(i,1,n+1)
        cin >> arr[i];
    n -= 1, a-= 1;
    int dist = n - a, sure=0;
    while(dist+1){
        if (dist == 0 && arr[a] == 1){
            sure += 1;
            break;
        }
        if (arr[dist+a] || arr[a-dist]){
            if (a-dist >=0){
                if (arr[dist+a] == arr[dist-a])
                    sure += 2;}
            else
                sure += 1;
        }
        dist--;
    }
    cout << sure;
    return 0;
}
