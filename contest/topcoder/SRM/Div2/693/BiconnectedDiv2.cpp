// Problem: BiconnectedDiv2
// Level: Two
// Tags: #graphs
// Platform: topcoder
// Solved by: switchkiller
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define inf 0x3f3f3f3f
#define ll long long
#define mp make_pair
#define pb push_back
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class BiconnectedDiv2{
    public:
        int minimize(vector <int> w1, vector <int> w2){
            int n = w1.size();
            int res = w1[0]+w1[n-1]; // Both are necessary to remain connected.
            REP(i,0,n-1) res += w2[i];
            REP(i,0,n-2) if (w1[i+1] < 0) res += w1[i+1];
            return res;
        }
};
