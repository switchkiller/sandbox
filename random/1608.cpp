// Binary Tree Travesal - #tricky
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

const int MAXN = 100;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int arr[MAXN];
map<int, vi> ans;

void diagonal(int r, int dist,int val){
  if (val == 0) return;
  ans[dist].pb(val);
  diagonal(2*r+1, dist, arr[2*r+1]);
  diagonal(2*r, dist+1, arr[2*r]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n;
    cin >> n;
    REP(i,1,n+1)
      cin >> arr[i];
    diagonal(1,0,arr[1]);
    REP(i,0,ans.size()){
      vi temp = ans[i];
      REP(j,0,temp.size())
        cout << temp[j] << " ";
      }
    return 0;
}
