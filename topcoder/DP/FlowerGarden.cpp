// Problem   : FlowerGarden
// Division  : One
// Level     : hard
// Tags      : #greedy #graphs #dp
// Platform  : topcoder
// Solved by : switchkiller
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

class FlowerGarden{
  public:
      vector<int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt);
};

vector<int> FlowerGarden::getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt){
    int n = height.size();
    vector<bool> used(n);
    vector<int> res(n);
    REP(i,0,n){
        int maxm = 0;
        int pos = -1;
        REP(j,0,n){
            if (used[j]) continue;
            bool found = true;
            REP(k,0,n){
                if (used[k]) continue;
                bool block = !(wilt[j] < bloom[k] || bloom[j] > wilt[k]);
                if (height[j] > height[k] && block){
                    found = false; break;
                }
            }
            if (found && maxm < height[j]){
                maxm = height[j];
                pos = j;
            }
        }
        res.pb(maxm);
        used[pos] = true;
    }
    return res;
}
