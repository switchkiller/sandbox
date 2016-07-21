// 11402 - Ahoy, Pirates!
// #segment-trees #lazy-updates
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

typedef vector<int> vi;

const int SET = 1, RESET = 2, INVERT = 3;
const int maxn = 1024010;

vi a, st, imlazy;

int left(int p) { return (p << 1);}
int right(int p) { return (p << 1)+1;}

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

int inverter(int x){
    if (x == SET) return RESET;
    if (x == RESET) return SET;
    if (x == INVERT) return 0;
    return INVERT;
}

void propagate(int p, int b, int e){
    if (imlazy[p] == SET)
        st[p] = e-b+1;
    else if (imlazy[p] == RESET)
        st[p] = 0;
    else if (imlazy[p] == INVERT)
        st[p] = (e-b+1) - st[p];

    if (b != e){
        if (imlazy[p] == SET || imlazy[p] == RESET)
            imlazy[left(p)] = imlazy[right(p)] = imlazy[p];
        else if (imlazy[p] == INVERT){
            imlazy[left(p)] = inverter(imlazy[left(p)]);
            imlazy[right(p)] = inverter(imlazy[right(p)]);
        }
    }
    imlazy[p] = 0;
}

void update_tree(int p, int b, int e, int i, int j, int type){
    if (b > e)
        return;
    propagate(p,b,e); // propagate when some propagation needed on the way.
    if (i > e || j < b)
        return;
        propagate(p,b,e);
        return;
    }

    update_tree(left(p), b, (b+e)/2, i, j, type);
    update_tree(right(p), (b+e)/2+1, e, i, j, type);
    st[p] = st[left(p)] + st[right(p)];
}

int query(int p, int b, int e, int i, int j){
    if (b > e)
        return 0;
    propagate(p,b,e);
    if (i > e || j < b)
        return 0;
    if (i <= b && j >= e)
        return st[p];
    int p1 = query(left(p), b, (b+e)/2, i, j);
    int p2 = query(right(p), (b+e)/2+1, e, i, j);

    return p1+p2;
}

int main(){

    // freopen("11402-in.txt" , "r" , stdin);
    // freopen("11402-out.txt" , "w" , stdout);

    int t;
    cin >> t;
    REP(tc,0,t){
        int n, q, m, c=INF;
        string s;
        cin >> n;
        a.assign(maxn,0);
        int idx = 0;
        REP(ii,0,n){
            cin >> m >> s;
            int k = s.size();
            REP(i,0,m*k)
                a[idx++] = s[i%k] - '0';
        }
        n = idx;
        st.assign(4*n, 0);
        imlazy.assign(4*n, 0);
        build_tree(1,0,n-1);

        cin >> q;
        int v=0;
        cout << "Case " << tc+1 << ":\n";
        while(q--){
            char str[2]; int a, b;
            cin >> str >> a >> b;
            switch (str[0]){
            case 'F': update_tree(1,0,n-1,a,b,SET); break;
            case 'E': update_tree(1,0,n-1,a,b,RESET); break;
            case 'I': update_tree(1,0,n-1,a,b,INVERT); break;
            case 'S': cout <<"Q" << ++v <<": " << query(1,0,n-1,a,b) << endl; break;
            }
        }
    }
    return 0;
}
