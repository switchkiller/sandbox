/* Problem Description:
  Smallest Distinct Window
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

#define NMAX 256
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    string str;
    cin >> str;
    int map[NMAX];
    memset(map, -1, sizeof map);
    int idx = 0, maxLen = -inf, maxidx = -1;
    map[str[0]] = 0;
    for (int i = 1; i < str.length(); i++){
      if (map[str[i]] != -1 && map[str[i]] >= idx){
        // cout << i << endl;
        if (maxLen < (i-idx)){
          maxLen = i-idx;
          maxidx = idx;
        }
        idx = map[str[i]]+1;
      }
      map[str[i]] = i;
    }
    // cout << idx;
    // if (maxLen < str.length()-idx) maxLen = str.length()-idx;
    cout << maxLen <<  endl;
    REP(i,0,maxLen){
      cout << str[maxidx+i];
    }
    return 0;
 }

// lcpsklryvmcpjnbpbwllsrehfmxrkecwitrsglrexvtjmxypunbqfgxmuvgfajclfvenhyuhuorjosamibdn
