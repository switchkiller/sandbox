/* Problem Description:
  Not even naive.
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
const int MAX = 101;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t;
    char str[MAX];
    cin >> t;
    while (t--){
      int map[26], sp = 0;
      memset(map, 0, sizeof map);
      int n;
      cin >> n;
      cin >> str;
      int allhappy = 1, unhappy = 0, cnt = 1;
      REP(i,0,n){
        if (str[i] == str[i+1]) cnt++;
        else if (cnt >= 2){
          allhappy = 1;
          cnt = 1;
        }
        else
          unhappy = 1;
        if (str[i] == '_')
          sp++;
        else
          map[str[i]-'A']++;
      }
      int flag = 1;
      // REP(i,0,26)
      //   cout << map[i] << " ";
      REP(i,0,26)
        if (map[i] == 1){
          flag = 0;
          break;
          // cout << i << endl;
        }
      // if (sp = 0)
      if (unhappy && !sp){
        cout << "NO\n";
        continue;
      }
      if (flag || (allhappy && !unhappy)) cout << "YES\n";
      else cout << "NO\n";
    }
    return 0;
 }
