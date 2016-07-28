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
#define N 100010

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
    int n, sum = 0;
    char s[N];
    cin >> n >> s;
    map<char,int> mp, mpcnt;
    REP(i,0,n){
      if (!mp.count(s[i]))
        sum++;
      mp[s[i]]++;
    }

    int j = 0, now = 0, len = 0, ans = inf;

    REP(i,0,n){
      if (mpcnt[s[i]] == 0)
        now++;
      mpcnt[s[i]]++;
      len++;
      if (now == sum){
        if (len < ans) ans = len;

        while (now == sum){
          mpcnt[s[j]]--;
          len--;
          if (mpcnt[s[j]] == 0)
            now--;
          j++;
          if (now == sum) if (len < ans) ans = len;
        }
      }
    }
    cout << ans;
    return 0;
}
