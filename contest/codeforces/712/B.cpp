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

const int MAX = 1e5+10;
char str[MAX];

#define R(x,y) x += 1;
#define L(x,y) x -= 1;
#define U(x,y) y += 1;
#define D(x,y) y -= 1;


char inverse(char s){
  if (s == 'L') return 'R';
  else if (s == 'R') return 'L';
  else if (s == 'U') return 'D';
  else return 'U';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    cin >> str;
    int l = strlen(str)-1 , f = 0;
    if ((l+1) % 2){
      cout << "-1" << endl;
      return 0;
    }
    int x = 0, y = 0;
    FOR(i,0,l){
      if (str[i] == 'L') L(x,y);
      if (str[i] == 'R') R(x,y);
      if (str[i] == 'U') U(x,y);
      if (str[i] == 'D') D(x,y);
    }
    if (x == 0 && y == 0){
      cout << "0" << endl;
      return 0;
    }

    int edit = 0;

    while (f < l){
      if (str[f] != inverse(str[l]))
        edit++;
      f++; l--;
    }
    cout << edit << endl;
    return 0;
 }
