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

const int N = 125010;

int a[N];

int valA (int x, int y, int z, int n) {
  int tmp = (x-1)*n*n + (y-1)*n + z;
  return a[tmp-1];
}

bool subcubecheck(int x, int y, int z, int k, int n) {
  int max = 0;
  for (int tmx=0; tmx < k; tmx++) {
    for (int tmy=0; tmy < k; tmy++) {
      for (int tmz=0; tmz < k; tmz++) {
        if (valA(x+tmx, y+tmy, z+tmz, n) > max) {
          max = valA(x+tmx, y+tmy, z+tmz, n);
          if (max > k)
          return false;
        }
      }
    }
  }
  if (max == k)
  return true;
  else
  return false;
}

int cubetraverse (int n, int k) {
  int count = 0;
  for (int x=1; x <= (n-k+1); x++) {
    for (int y=1; y <= (n-k+1); y++) {
      for (int z=1; z <= (n-k+1); z++) {
        if (subcubecheck(x, y, z, k, n) == true)
          count++;
      }
    }
  }
  return count;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int query;
    cin >> query;
    if (query <= 5) {
      for (int q=0; q<query; q++) {
			    int n;
          cin >> n;
          if (n>=1 && n<=50) {
            int arrlen = n * n * n;
            memset(a, 0, sizeof(a));
			      for (int i=0; i<arrlen; i++)
				      cin >> a[i];
	          for (int k=1; k<=n; k++) {
				      int count = cubetraverse(n, k);
				      cout << count << " ";
			      }
			      cout << endl;
          }
		  }
    }
    return 0;
 }
