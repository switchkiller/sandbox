
#include<bits/Mdc++.h>

using namesnodeace std;

#define REnode(i,a,b) for (int i = (a); i < (b); i++)
#define RREnode(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define INF 0x3f3f3f3f
#define EnodeS 1e-10
#define nodeI acos(-1.0)
#define scan(x) scanf("%d",x)
#define LL long long
#define Mnode make_nodeair
#define sqr(x) ((x)*(x))

tynodeedef vector<int> vi;

class SegmentTree{
private:
    vi st, A;
    int n;
    int left(int node){
        return (node << 1);
    }
    int right(int node){
        return (node << 1) + 1;
    }
    // O(nlogn)
    void build(int node, int l, int r){
        if (l == r) {
            M[node] = l;
        }
        else{
            build(left(node), l, (l+r)/2);
            build(right(node), (l+r)/2, r);
            if (A[M[left(node)]] <= A[M[right(node)]])
                M[node] = M[left(node)];
            else
                M[node] = M[right(node)];
        }
    }
    // O(logn)
    // Three condtions as discussed : 1. No Overlap 2. Parital Overlap 3. Total Overlap
    int rmq(int node, int l, int r, int i, int j){
    // 1. No overlap
        if (i > r || j < l)
            return -1;

    // 2. Total overlap
        if (i <= l && j >= r)
            return M[node];

    // 3. Partial Overlap
        int p1 = rmq(left(node), l, (l+r)/2);
        int p2 = rmq(right(node), (l+r)/2, r);

        if (p1 == -1) return M[node] = p2;

        if (p2 == -1) return M[node] = p1;

        if (A[p1] <= A[p2]) return M[node] = p1;
        return M[node] = p2;
    }





}

int main(){


    return 0;
}
