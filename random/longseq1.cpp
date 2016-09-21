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

int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}


unsigned int bd(unsigned int n) /* Function to convert binary to decimal.*/
{
    unsigned int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in" , "r" , stdin);
    //  freopen("out" , "w" , stdout);
    #endif

    int t;
    unsigned int n;
    int len = 0;
    cin >> t;

    while (t--){
      cin >> n;
      len = (int) floor(1 + log10((double)n));
      int cnt = countSetBits(bd(n));
      cout << len << " " << cnt << endl;
      if (cnt == len-1 || cnt == 1)
        cout << "YES" << endl;
      else  cout << "NO" << endl;
    }
    return 0;
 }
