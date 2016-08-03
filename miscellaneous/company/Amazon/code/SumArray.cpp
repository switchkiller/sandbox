// Sum of a given range of an array
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

#define maxn 100

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi a, st;

int left(int p) {return (p << 1);}
int right(int p) {return (p << 1) + 1;}

void build_tree(int p, int b, int e){
    if (b > e) return;
    if (b == e)
        st[p] = a[b];
    else{
        build_tree(left(p), b, (b+e)/2);
        build_tree(right(p), (b+e)/2+1, e);
        st[p] = st[left(p)] + st[right(p)];
    }
}

int query_tree(int p, int b, int e, int i, int j){
    if (b > e)
        return 0;
    if (i > e || j < b)
        return 0;
    if (i <= b && j >= e)
        return st[p];
    int p1 = query_tree(left(p), b, (b+e)/2, i, j);
    int p2 = query_tree(right(p), (b+e)/2+1, e, i, j);

    return p1+p2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    int n,x,y;
    cin >> n;
    REP(i,0,n){
      cin >> x;
      a.pb(x);
    }

    st.assign(4*n, 0);
    build_tree(1,0,n-1);

    // for (int i = 0; i <= n; i++)
    // cout << a[i] << " ";
    // cout << endl;
    // for (int i = 0; i <= 4*n; i++)
    // cout << st[i] << " ";
    cin >> x >> y;

    cout << query_tree(1,0,n,x,y);

    return 0;
}
