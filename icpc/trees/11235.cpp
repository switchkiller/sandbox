// 11235 - Frequent values
// #segment-trees
// Easy

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define LL long long
#define MP make_pair
#define sqr(x) ((x)*(x))
#define maxn 100000

int a[maxn], n, q;
vector<int> x, st, f, l;

int left(int p) { return (p << 1); }
int right(int p) { return (p << 1) + 1; }

void buildtree(int p, int b, int e){
    if (b == e)
        st[p] = b;
    else{
        buildtree(left(p), b, (b+e)/2);
        buildtree(right(p), (b+e)/2+1, e);
        if (x[st[left(p)]] >= x[st[right(p)]])
            st[p] = st[left(p)];
        else
            st[p] = st[right(p)];
    }
}

int rmq(int p, int b, int e, int i, int j){
    if (i > e || j < b)
        return -1;
    if (i <= b && j >= e)
        return st[p];
    int p1 = rmq(left(p), b, (b+e)/2, i, j);
    int p2 = rmq(right(p), (b+e)/2+1, e, i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (x[p1] >= x[p2]) return st[p] = p1;
    return st[p] = p2;
}

int main(){

    // freopen("out-large.txt" , "w" , stdout);
    // freopen("in-large.txt" , "r" , stdin);

    while (cin >> n && n){
        int tmp=INF,pos,lst,cnt=-1;
        cin >> q;
        x.clear(); l.clear(); f.clear(); st.clear(); memset(a, -1, sizeof(a));
        REP(k,0,n){
            cin >> a[k];
            if (tmp != a[k]){
                REP(i,0,cnt){
                    x.push_back(cnt);
                    l.push_back(lst);
                }
                pos = lst = k;
                f.push_back(pos);
                tmp = a[k];
                cnt = 1;
            }
            else{
                cnt++; f.push_back(pos);
                lst = k;
            }
        }
        REP(i,0,cnt){
            x.push_back(cnt);
            l.push_back(lst);
        }
        st.assign(4*n,0);
        buildtree(1,0,n-1);
        while(q--){
            int i, j, val, ans;
            cin >> i >> j;
            i--, j--;
            if (a[i] == a[j])
                cout << j-i+1 << endl;
            else{
            val = max(l[i] - i + 1, j - f[j] + 1);
            ans = max(val, x[rmq(1,0,n-1,l[i]+1,f[j]-1)]);
            cout << ans << endl;}
        }
    }
    return 0;
}
