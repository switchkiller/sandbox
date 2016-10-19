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

const int N = 10010;
// int arr[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n, flag = 0, bucket = 0;
    cin >> n;
    int val;
    REP(i,0,n){
      cin >> val;
      if (val == 0){
        cout << "NO" << endl;
        exit(0);
      }
      val -= bucket;
      if (val % 2){
        bucket = 1;
      }
      else bucket = 0;
      // cout << bucket << " ";
    }
    if (bucket == 1) cout << "NO" << endl;
    else
    cout << "YES" << endl;
    return 0;
 }
