// TODO - Seems a subset sum problem
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
#define N 501

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int a[N];
bool dp[N][N][N];

// Driver program to test above function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n, sum;
    cin >> n >> sum;
    FOR(i,1,n)
        cin >> a[i];

    dp[0][0][0] = 1;
    FOR(i,0,sum)
        FOR(j,0,sum)
            FOR(k,1,n){
                dp[i][j][k] = dp[i][j][k-1];
                if (j >= a[k]){
                    dp[i][j][k] = dp[i][j][k] || dp[i][j - a[k]][k-1];
                if (i >= a[k])
                    dp[i][j][k] = dp[i][j][k] || dp[i-a[k]][j-a[k]][k-1];
                }
            }
    int ans = 0;
    FOR(i,0,sum)
        ans += dp[i][sum][n];
    cout << ans << endl;
    FOR(i,0,sum)
        if (dp[i][sum][n] == 1) cout << i << " ";
    cout << endl;
    return 0;
}
