
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt" , "r" , stdin);
    // freopen("out.txt" , "w" , stdout);
    ll n, m, cnt, res=0;
    cin >> n >> m;
    ll c1 = n/5, c2 = m/5, mod1 = n % 5, mod2 = m % 5;

    FOR(i,0,4){
        cnt = c1 + (mod1 >= i && i);
        cnt *= (c2 + (mod2 >= (5-i) && i));
        res += cnt;
    }

    cout << res << endl;
    return 0;
}
