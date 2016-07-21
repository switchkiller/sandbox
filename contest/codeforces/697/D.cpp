// Pending - refer http://www.codeforces.com/contest/697/submission/19169487

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

const int MAXN = 10e5;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi g[MAXN];
void dfs(int cur, int p){
  for (auto adj : g[cur])
    if (adj != p){
      dfs(adj, cur);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n, temp;
    cin >> n;
    FOR(i,2,n){
      cin >> temp;
      g[i].pb(temp);
      g[temp].pb(i);
    }

    dfs(1,0);


    return 0;
}
