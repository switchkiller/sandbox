#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define TRvii(c, it) for (vector< pair<int, int> >::iterator it = (c).begin(); it != (c).end(); it++)
int dp[MAX][MAX];
void compute(){
    REP(i,0,MAX){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    REP(i,1,MAX)
        REP(j,1,MAX)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
}
void findit(int c[], int size){
    vector< pair<int, int> > ans[size];
    int z[size];
    memset(z, 0, sizeof z);
    REP(i,0,MAX)
        REP(j,0, MAX)
            REP(k,0,size)
                if (dp[i][j] == c[k]){
                    z[k]++;
                    ans[k].push_back(make_pair(i,j));}
    REP(i,0,size){
        sort(ans[i].begin(),ans[i].end());
        if (z[i] == 0)
            cout << "The Grid is Too Big!\n";
        else{
            cout << z[i] << endl;
            TRvii(ans[i],it)
                cout << it->first+1 << " " << it->second+1 << endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    int *c, t;
    cin >> t;
    c = new int[t];
    compute();
    REP(i,0,t)
        cin >> c[i];
    findit(c,t);
    return 0;
}
