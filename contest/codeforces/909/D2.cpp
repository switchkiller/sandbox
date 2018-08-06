#include <bits/stdc++.h>
using namespace std;

#define make_pair mp
#define X first
#define Y second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<db, db> pdd;
typedef vector<pii> vii;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

template<typename T> T sqr(const T &x) {
    return x * x;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin >> s;
    int n = sz(s);
    if(n==1)
        return !printf("0\n");
    vector<char> v;
    int op = 1;
    int pis = 0;
    if(n > 1)
    {
        if(s[0] == s[1])
            v.pb(s[0]);
        else
            pis++;
    }
    for(int i = 1;i < n-1;i++){
        if(s[i] == s[i-1] && s[i] == s[i+1])
            v.pb(s[i]);
        else
            pis++;
    }
    if(s[n-1] == s[n-2])
        v.pb(s[n-1]);
    else
        pis++;
    if(pis == 0)
        return !printf("0\n");

    while(true)
    {
        pis = 0;
        string p(v.begin(), v.end());
        auto i = v.begin();
        int k = 0;
        if(v.size() > 1){if(p[k] != p[k+1])v.erase(i);
        else pis++;i++;}
        else return !printf("%d\n", op);
        for(k = 1;k < (int)p.size()-1 && i != v.end();k++)
        {
            if(p[k] == p[k-1] && p[k] == p[k+1]){
                pis++;i++;
            }
            else
                v.erase(i);
        }
        if(k == (int)p.size()-1 && i != v.end())
        {
            if(p[k] == p[k-1]){
                pis++;i++;
            }
            else
                v.erase(i);
        }
        if(pis)
        {
            if(pis == (int)p.size())
                return !printf("%d\n", op);
            op++;
        }
        else
        {
            if(v.size() == 1 || v.size() == 0) return !printf("%d\n", ++op);
            return !printf("%d\n", op);
        }
    }
}
