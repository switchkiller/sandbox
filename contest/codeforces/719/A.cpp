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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    cin >> n;
    int sft = -1, flag = -1;
    while(n--){
      int val;
      cin >> val;
      if (sft == -1)
        sft = val;
      else{
        if (sft - val < 0) flag = 1;
        else if (sft - val > 0) flag = 0;
        // if (sft - val == 0)flag = -1;
        sft = val;
        // debug(flag)
      }
      if (val == 15 && (flag == 1 || flag == -1)) flag = 0;
      if (val == 0 && (flag == 0 || flag == -1)) flag = 1;
    }
    if (flag == 1) cout << "UP\n";
    else if (flag == 0) cout << "DOWN\n";
    else cout << -1 << endl;
    return 0;
 }
