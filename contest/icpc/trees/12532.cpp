// 12532 - Interval Product
// #use of range tree #tricky

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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int maxn = 1000002;
int zero[maxn], neg[maxn], x[maxn], n;

void adjust(int *tree, int k, int val){
    for (; k <= n+1; k += LSOne(k))
        tree[k] += val;
}

int query(int *tree, int i){
    int sum=0;
    for (; i; i -= LSOne(i)) sum += tree[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("12532-in.txt", "r", stdin);
    // freopen("12532-out.txt", "w", stdout);

    int q, val; char cmd;
    while (cin >> n >> q){
        memset(zero, 0, sizeof(zero));
        memset(neg, 0, sizeof(neg));
        FOR(i,1,n){
            cin >> val;
            if (val < 0)
                adjust(neg,i,1);
            else if (val == 0)
                adjust(zero,i,1);
            x[i] = val;
        }

        while (q--){
            int a, b;
            cin >> cmd >> a >> b;
            if (cmd == 'C'){ // Point update
                if (b < 0){
                    if (x[a] >= 0) adjust(neg,a,1);
                    if (x[a] == 0) adjust(zero,a,-1);
                }
                else if (b == 0){
                    if (x[a] != 0) adjust(zero,a,1);
                    if (x[a] < 0) adjust(neg,a,-1);
                }
                else{
                    if (x[a] == 0) adjust(zero,a,-1);
                    if (x[a] < 0) adjust(neg,a,-1);
                }
                x[a] = b;
            }
            else{
                int z = query(zero,b) - query(zero,a-1);
                int n = query(neg,b) - query(neg,a-1);
                if (z > 0) cout << "0";
                else if (n & 1) cout << "-";
                else cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}
