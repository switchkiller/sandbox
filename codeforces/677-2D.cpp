// D. Vasya and Treasure
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define MAX 300

typedef pair<int, int> ii;

int n, m, p, fx, fy;
int arr[MAX][MAX], dp[MAX][MAX];
vector<ii> g;
int main(){
    cin >> n >> m >> p;
    REP(i,0,n)
        REP(j,0,m){
            cin >> arr[i][j];
            g[arr[i][j]].push_back(ii(i,j));
            if (arr[i][j] == 1)
                dp[i][j] = i+j;
            if (arr[i][j] == p)
                fx=i, fy=j;
        }

    //Contd.



    return 0;
}
