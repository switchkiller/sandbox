/* Problem Description:

*/

#include<bits/stdc++.h>
#include<iostream>
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

const int MAX  = 1e5+10;

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
    int n, k, cap;
    ll ans = 0, sum = 0;
    int cost[MAX];
    bool capital[MAX];
    cin >> n >> k;

    REP(i,0,n){
      cin >> cost[i];
      sum += cost[i];
    }

    REP(i,0,k){
      cin >> cap;
      cap--;
      capital[cap] = true;
    }

    REP(i,0,n-1){
      if (capital[i]){
        ans += cost[i]*(sum-cost[i]);
        sum -= cost[i];
      }
      else if (!capital[i+1])
        ans += cost[i]*cost[i+1];
      // cout << i << " " << ans << endl;
    }

    if (capital[n-1])
      ans += cost[n-1]*(sum-cost[n-1]);
    else if (!capital[0])
      ans += cost[0]*cost[n-1];

    cout << ans << endl;
    return 0;
 }
