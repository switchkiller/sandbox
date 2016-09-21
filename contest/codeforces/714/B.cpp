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

const int mx = 1e5+10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n;
    ll arr[mx];
    cin >> n;
    REP(i,0,n)
      cin >> arr[i];
    int max, min;

    REP(i,0,n){
      if (arr[i] < min) min = arr[i];
      if (arr[i] > max) max = arr[i];
    }

    ll x = (max - min) / 2;
    ll match = max - x;
    REP(i,0,n){
      if (arr[i]+x == match || arr[i]-x == match || arr[i] == match) continue;
      else{
        cout << "NO" << endl;
        return 0;
      }
    }
    cout << "YES" << endl;
    return 0;
 }
