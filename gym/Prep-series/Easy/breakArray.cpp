/* Problem Description:
    Break an array into maximum number of sub-arrays such that their averages are same
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
int beg,end,sum,avg;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int n, temp,  arr[100];
    cin >> n;
    REP(i,0,n)
      cin >> arr[i];

    REP(i,0,n)
      sum += arr[i];
    avg = sum / n;
    sum = 0;
    pair<int, int> il[n]; int x = 0;
    REP(i,0,n){
      sum += arr[i];
      temp = sum / (end - beg + 1);
      if (temp == avg){
        il[x] = ii(beg,end);
        sum = 0;
        beg = end + 1;
        x++;
      }
      end++;
    }
    if (sum != 0)
      cout << "Not possible" << endl;
    else
      REP(i,0,x)
        cout << il[i].first << " " << il[i].second << endl;
    return 0;
 }
