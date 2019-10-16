/* Problem Description:
  Longest K Unique Chars
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    string str;
    int k;
    cin >> str;
    cin >> k;

    int map[26], start = 0, maxSize = -inf;
    memset(map, 0, sizeof map);
    int i = 0;
    for(i = 0; i < str.length(); ++i){
      if (k > 0 || map[str[i]-'a'] < 0){
        if (map[str[i]-'a'] == 0) k--;
        map[str[i]-'a']--;
      }
      else{
        cout << i;
        if (maxSize < (i-start)) maxSize = i-start;
        cout << maxSize;
        while(map[str[start]-'a'] < 0){
          map[str[start]-'a']++;
          if (map[str[start++]-'a'] == 0) break;
        }
        map[str[i]-'a']--;
      }
      REP(j,0,26) cout << map[j] <<" ";
      cout << endl;
    }
    if (maxSize < (i-start)) maxSize = i-start;
    cout << maxSize << endl;
    return 0;
 }
