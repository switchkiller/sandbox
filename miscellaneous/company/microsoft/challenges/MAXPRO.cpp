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

const int N = 10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int t, n;
    cin >> t;
    int arr[N];
    while (t--){
      cin >> n;
      REP(i,0,n)
        cin >> arr[i];

      int maxe = 1, mine = 1, maxsf = 1;
      // Learnt from gfg. #imp subarray technique.
      REP(i,0,n){
        if (arr[i] > 0){
          maxe = maxe*arr[i];
          mine = min(mine*arr[i],1);
        }

        else if (arr[i] == 0){ // Cant go beyond
          maxe = 1;
          mine = 1;
        }

        else {
          int temp = maxe;
          maxe = max(mine*arr[i], 1);
          mine = temp * arr[i];
        }
        if (maxsf < maxe)
          maxsf = maxe;
      }
      cout << maxsf << endl;
    }
    return 0;
}
