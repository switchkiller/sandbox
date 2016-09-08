/* Problem Description: ODDDIV
  Number of divisor at a given range.
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

const int MAX = 1e9;

int msqrt = sqrt(MAX);

vector<bool> primes;

void sieve(){
  primes.assign(MAX,1);
  primes[0] = primes[1] = 0;

  FOR(i,2,msqrt){
    if (primes[i])
      for (int j = i*i; j <= msqrt; j += i)
        if (primes[j])
          primes[j] = 0;
  }
}

int cntDiv(int k, ll m, ll n){
  int cnt = 0;
  FOR(x,m,n){
    int kx = 0, i = 0;
    ll ind = 1, tx = x;
    ll pf = primes[i];
    while (pf * pf <= tx){
        while (tx % pf == 0){ tx /= pf; kx++; }
        ind *= (kx + 1);
        pf = primes[++i];
    }
    if (tx != 1) ind *= 2;
    if (ind == k)
      cnt++;
      // cout << ind << endl;
  }
  return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    sieve();
    int t;
    cin >> t;
    while (t--){
      int k;
      ll low, high;
      cin >> k >> low >> high;
      cout << cntDiv(k, low, high) << endl;
    }
    return 0;
 }
