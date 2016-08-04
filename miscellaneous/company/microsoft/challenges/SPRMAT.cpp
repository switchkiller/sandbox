#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i >= (b); i--)
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

const int N = 5;
int mat[N][N];

void printSpiral(int n){
  int m = n;
  int k = 0, l = 0;
  while(k < m && l < n){
    // Upper row
      REP(i,l,n)
        cout << mat[k][i] << " ";
      k++;

      REP(i,k,m)
        cout << mat[i][n-1] << " ";

      n--;

      RREP(i,n-1,l)
        cout << mat[m-1][i] << " ";

      m--;

      RREP(i,m-1,k)
        cout << mat[i][l] << " ";

      l++;
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n;
    int t ;
    cin >> t;
    while(t--){
        n = 4;
        REP(i,0,n)
          REP(j,0,n)
            cin >> mat[i][j];

        printSpiral(n);
    }
    return 0;
}
