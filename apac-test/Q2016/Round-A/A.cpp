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
#define MAXN 20
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    map<char, int> mp;
    int t, n, mx;
    cin >> t;
    FOR(T,1,t){
      vector<char> str[100];
      vector<int> ans;
      char s[20];
      cin >> n;
      REP(i,0,n){
        cin.getline(s,20);
        str[i].push_back(s);
      }
      REP(i,0,n){
        mp.clear(); mx = 0;
        REP(j,0,strlen(str[i])){
          if (str[i][j] != ' ')
            mp[str[i][j]]++;
          ans.pb(mp.size());
        }
          mx = max(mx, (int)mp.size());
      }
    cout <<"Case #" << T << ": " <<  mx << endl;
  }
  return 0;
}
