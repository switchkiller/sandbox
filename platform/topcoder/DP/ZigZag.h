#include<bits/stdc++.h>
#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define N 50
using namespace std;
class ZigZag{
public:
     int longestZigZag(vector <int> sequence){
        int n = sequence.size();
        int dp[N]={1}, signs[N]={0};
        REP(i,1,n){
            RREP(j,i-1,-1){
                int sign = signs[j];
                if ((sign == 0) || ((sign < 0) && (sequence[i] - sequence[j] > 0)) ||
                        ((sign > 0) && (sequence[i] - sequence[j] < 0))){
                            dp[i] = dp[j] + 1;
                            signs[i] = sequence[i] - sequence[j];
                            break;
                }

            }
        }
        return dp[n-1];
    }
};
