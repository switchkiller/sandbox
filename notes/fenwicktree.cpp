// A fenwick tree walkthrough / BIT


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
#define LSOne(x) x&(-x)

typedef vector<int> vi;

class FenwickTree{
    private:
        vi ft;
    public:
        FenwickTree(int n) { ft.assign(n+1,0); }
        int rsq(int b){
            int sum=0;
            for (; b; b -= LSOne(b)) sum += ft[b];
            return sum;
        }

        int rsq(int a, int b){
            return rsq(b) - (a == 1 ? 0 : rsq(a-1));
        }

        void adjust(int k, int v){ // Each adjust takes O(logn) time
            for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; // For each v
        }
};

int main(){
    int m[] = {1,2,3,4,5,6,7,8};
    FenwickTree ft(8);
    REP(i,0,8)
        ft.adjust(m[i],1);

    // Perform queries

    cout << ft.rsq(1,1) << endl;
    cout << ft.rsq(1,2) << endl;
    cout << ft.rsq(3,7) << endl;
    cout << ft.rsq(1,8) << endl;
    return 0;
}
