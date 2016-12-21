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
const int N = 1e6+10;
int arr[N], brr[N];
vi lst[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n, k;
    cin >> n;
    REP(i,0,n)
      cin >> arr[i];
    cin >> k;
    REP(i,0,k)
      cin >> brr[i];
    if (k >= n){
      cout << "NO" << endl;
      return 0;
    }
    int j = 0, sum = 0;
    REP(i,0,k){
      for (; j < n; j++){
        sum += arr[j];
        lst[i].pb(arr[j]);
        // cout << arr[j] << " ";
        if (sum == brr[i]){
          j++;
          sum = 0;
          break;
        }
      }
      // cout << endl;
    }
    if (j < n || sum != 0){
      cout << "NO" << endl;
      // exit();
      return 0;
    }
    REP(i,0,k){
      int flag = 0, mx = -inf, sz = lst[i].size();
      for (int it = 0; it < sz;it++){
        if (mx < lst[i][it]){
          mx = lst[i][it];
          flag = 1;
        }
        else if (mx == lst[i][it]) flag++;
      }
      // cout << mxidx << endl;
      if (flag == sz){
        cout << "NO" << endl;
        return 0;
      }
    }
    int reg = 1;
    cout << "YES" << endl;
    REP(i,0,k){
      int flag = 0, mx = -inf, mxidx = -1, sz = lst[i].size();
      for (int it = 0; it < sz;it++){
        if (mx < lst[i][it]){
          mx = lst[i][it];
          mxidx = it;
          flag = 1;
        }
        else if (mx == lst[i][it]) flag++;
      }
      // cout << mxidx << endl;
      if (flag == sz){
        cout << "NO" << endl;
        return 0;
      }
      RREP(j,mxidx,0)
      cout << j+reg << " L" << endl;
      REP(j,0,sz-mxidx-1)
      cout << j+reg<< " R" << endl;
      reg++;
    }
    return 0;
 }
