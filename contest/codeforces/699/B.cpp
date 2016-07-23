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
#define N 1005

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n, m;
char arr[N][N];
int cnt[N][N];

int D[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

int Dfs(int i, int j, int dx, int dy){
  int cnt = 0;
  if (i < 0 || i > n || j < 0 || j > m) return 0;
  if (arr[i][j] == '*') cnt++;
  cnt += Dfs(i+dx,j+dy, dx, dy);

  return cnt;
}

int dfs(int i, int j){
  int res = 0;
  REP(k,0,4)
    res += Dfs(i+D[k][0], j+D[k][1], D[k][0], D[k][1]);
  if (arr[i][j] == '*') res += 1;
  return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    cin >> n >> m;
    int wall = 0;
    ii c = {0,0};
    int max = -inf;
    REP(i,1,n+1)
        cin >> arr[i];

    FOR(i,1,n)
      REP(j,0,m){
        if (arr[i][j] == '*') wall++;
        cnt[i][j] = dfs(i,j);
        if (max < cnt[i][j]){
          max = cnt[i][j];
          c = {i,j};
        }
      }
    // FOR(i,1,n){
    //   REP(j,0,m)
    //     cout << cnt[i][j] << " ";
    //   cout << endl;
    // }

    if (max == wall)
      cout << "YES" << endl << c.first << " " << c.second+1 << endl;
    else
      cout << "NO" << endl;
    return 0;
}
