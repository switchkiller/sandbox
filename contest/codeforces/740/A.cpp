/* Problem Description:

*/
// Pending

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
long a[3];

long func(int i,int rem){
  long S = a[i-1] * (rem/i);
  rem -= i;
  cout << S << "-" << rem;
  if (rem == 0) return S;
  long mn = inf, temp;
  for (int i = 1; i <=3; i++){
    temp = 0;
    if (rem >= i)
    temp = S+func(i,rem);
    mn = min (mn, temp);
  }
  return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    cin >> n >> a[0] >> a[1] >> a[2];
    int rem; long mn = inf;
    // cout << rem;
    if (n <= 3)
      rem = rem - n;
    else
      rem = rem % n;
    for (int i = 1; i <= 3; i++)
      if (rem >= i){
        mn = min(mn, func(i,rem));
        cout << mn;
      }
    return 0;
 }
