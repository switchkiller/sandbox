// Alternative solution for B
// Intuitive
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
#define N 1005
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n, m;
int a[N], b[N]; char arr[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    cin >> n >> m;
    int wall = 0;
    REP(i,0,n)
      REP(j,0,m){
        cin >> arr[i][j];
        if (arr[i][j] == '*'){
          wall++;
          a[i]++;
          b[j]++;
        }
      }
    REP(i,0,n)
      REP(j,0,m){
        int s = a[i] + b[j];
        if (arr[i][j] == '*') s--;
        if (s == wall){
          cout << "YES" << endl << i + 1 << " " << j + 1 << endl;
          return 0;
        }
      }
    cout << "NO" << endl;
    return 0;
}
