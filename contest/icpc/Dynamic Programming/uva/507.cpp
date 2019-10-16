#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i = (a); i < (b); i++)
int main(){
    int T, S, curSM, curSI, MS, MAXSI, MAXEI;
    cin >> T;
    REP(x,1,T+1){
        cin >> S;
        int arr[20005];
        REP(i,1,S)
            cin >> arr[i];
        curSM = 0;
        curSI = 1;
        MS = INT_MIN;
        REP(curEI,1,S){
            curSM += arr[curEI];
            if (curSM < 0){
                curSM = 0;
                curSI = curEI + 1;
            }
            else if (curSM > MS || (curSM == MS && (MAXEI - MAXSI < curEI - curSI))){
                MS = curSM;
                MAXSI = curSI;
                MAXEI = curEI;
            }
        }
        if(MS > 0) printf("The nicest part of route %d is between stops %d and %d\n", x, MAXSI, MAXEI+1);
        else printf("Route %d has no nice parts\n", x);
    }
    return 0;
}