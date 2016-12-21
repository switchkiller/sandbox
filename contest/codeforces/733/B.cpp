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

const int N = 1e5+10;
// I messed it !
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n, maxl = 0, maxr = 0, mx;
    int l[N], r[N];
    cin >> n;
    REP(i,0,n){
      cin >> l[i] >> r[i];
      maxl += l[i];
      maxr += r[i];
    }
    mx = abs(maxl - maxr);
    int temp = -inf, idx = -1;
    REP(i,0,n)
      if (temp < abs(maxl - l[i] + r[i] - (maxr - r[i] + l[i]))){
        idx = i;
        temp = abs(maxl - l[i] + r[i] - (maxr - r[i] + l[i]));
      }
    // cout << temp;
    if (temp > mx)
      cout << idx + 1 << endl;
    else
      cout << 0 << endl;
    return 0;
 }
