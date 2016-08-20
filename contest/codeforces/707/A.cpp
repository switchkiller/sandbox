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

const int N = 100+10;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n, m;
    char str[N];
    cin >> n >> m;
    int flag = 0;
    for (int i = 0; i < n; i++ ){
      cin >> str;
      flag = 0;
      int l = strlen(str);
      for (int j = 0; j < l; j++)
        if (str[j] != 'B' && str[j] != 'W' && str[j] != 'G'){
          flag = 1;
          break;
        }
      if (flag == 1)
        break;
    }
    if (flag == 0)
      cout << "#Black&White" << endl;
    else
      cout << "#Color" << endl;
    return 0;
  }
