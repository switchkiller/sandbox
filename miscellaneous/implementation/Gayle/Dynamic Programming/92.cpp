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

#define MAX 100

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int dp[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif

    int x, y;
    cin >> x >> y;
    memset(dp, -1, sizeof dp);

    FOR(i,0,x)
      dp[0][i] = 1;
    FOR(i,0,y)
      dp[i][0] = 1;

    int t;
    cin >> t;
    while (t--){
      int a, b;
      cin >> a >> b;
      dp[b][a] = 0;
    }

    FOR(i,1,y)
      FOR(j,1,x)
        if (dp[i][j] == -1)
          dp[i][j] = dp[i-1][j] + dp[i][j-1];

    FOR(i,0,x){
      FOR(j,0,y)
        cout << dp[j][i] << " ";
      cout << endl;
    }

    cout << dp[y][x];


    return 0;
}
