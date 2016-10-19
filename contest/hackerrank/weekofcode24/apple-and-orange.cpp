/* Problem Description:

*/

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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool inrange(int x, int y, int val){
  return (x <= val && y >= val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int s, t, a, b, m, n;
    int cnt = 0, val;
    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;
    val = 0;
    REP(i,0,m){
      cin >> val;
      if (inrange(s,t,a+val))
        cnt++;
    }
    cout << cnt << endl;
    cnt = 0;
    REP(i,0,n){
      cin >> val;
      if (inrange(s,t,b+val))
        cnt++;
    }
    cout << cnt << endl;
    return 0;
 }
