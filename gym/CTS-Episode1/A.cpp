/* Problem Description:
BAPC 2010
A Gene Shuffle
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

const int N = 1e5+10;

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int t;
    cin >> t;
    while (t--){
      int n, a[N], b[N];
      cin >> n;
      REP(i,0,n)
        cin >> a[i];
      REP(i,0,n)
        cin >> b[i];
      int sum = 0, start = 1, end = 1;
      REP(i,0,n){
        if (sum == 0 && i != 0){
          cout << start << "-" << end-1 << " ";
          start = end;
        }
        sum += a[i] - b[i];
        end++;
      }
      if (sum == 0){
        cout << start << "-" << end-1 << " ";
        start = end;
      }
    }
    return 0;
 }
