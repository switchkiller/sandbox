// D. Alyona and Strings
// Trivial LCS problem

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define TRvi(it, c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define inf 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;
#define N 1010
#define K 11

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, o, dp[N][N], dp3[N][N][K];
char a[N], b[N];

int d686(){
    FOR(i,1,n)
        FOR(j,1,m)
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1]+1;  // Starts increasing for the consequtive string match

    int ans=-inf;
    FOR(i,1,n)
        FOR(j,1,m){
            FOR(k,1,o){
                dp3[i][j][k] = max(dp3[i-1][j][k], dp3[i][j-1][k]);
                dp3[i][j][k] = max(dp3[i][j][k],dp[i][j] + dp3[i-dp[i][j]][j-dp[i][j]][k-1]);
            }
            ans = max(ans, dp3[i][j][o]);}

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    cin >> n >> m >> o;
    cin >> a >> b;
    cout << endl;
    cout << d686();
    return 0;
}
