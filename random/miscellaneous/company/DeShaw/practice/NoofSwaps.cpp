/* Problem Description: TODO

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

int minSwap(int arr[], int n){
  ii arrPos[n];
  REP(i,0,n){
    arrPos[i].first = arr[i];
    arrPos[i].second = i;
  }
  sort(arrPos, arrPos+n);
  vector<bool> vis(n, false);
  int ans = 0;
  REP(i,0,n){
    if (vis[i] || arrPos[i].second == i) // Position did not change
      continue;
    int count = 0;
    int j = i;
    while(!vis[j]){
      vis[j] = 1;
      j = arrPos[j].second;
      count++;
    }
    ans += (count-1);
  }
  return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    // int arr[] = {1,5,4,3,2};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout << minSwap(arr, n) << endl;
    return 0;
 }
