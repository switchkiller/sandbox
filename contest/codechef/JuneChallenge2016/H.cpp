// Chef and Sad Pairs
// Easy graph problem - basics is count via connected component....and do some basic mathematics.
// We will also use articulation points concept
//

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define TRvvi(it,v) for (vector<int>::iterator it = (v).begin(); it != (v).end(); it++)
#define MAX 100

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, e;
int gi[MAX];
vi g[MAX];
// bool visited[MAX];
int conn;

bool used[MAX];
int timer, tin[MAX], fup[MAX];
map<int, bool> mp;
vector< map<int, int> > pcomp, tcomp;
map<int, int> m;
map<int, int> bk;

void dfs (int v, int p = -1) {
    used[v] = true;
    m[gi[v]]++;
    bk[v] = conn;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1){
                //v is articulation point
                mp[v] = true;
                ++children;
            }
        }
    }
    if (p == -1 && children > 1)
        mp[v] = true;
        //v is articulation point
}

int main(){
    int a, b;
    cin >> n >> e;
    map<int, int> grp;
    FOR(i,1,n){
        cin >> gi[i];
        grp[gi[i]]++;
    }
    FOR(i,1,e){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    FOR(i,1,n)
        if (!used[i]){
            timer=0;
            memset(tin, 0, sizeof tin);
            memset(fup, 0, sizeof fup);
            dfs(i);
            pcomp.push_back(m);
            m.clear();
            conn++;
        }

    cout << pcomp[0][1] << " " << pcomp[0][3] << " " << pcomp[1][1] << " " << pcomp[1][3] << endl;

    // See vertex belongs to which component.
    // FOR(i,1,n)
    //     cout << bk[i] << " ";

    int ans[n];

    map<int, int> tot;
    REP(j,0,conn){
        for (map<int, int>::iterator it = pcomp[j].begin(); it != pcomp[j].end(); it++ ){
            if (it->second == 0)
                continue;
            // cout << it->first << " ";
            if (tot[it->first] == 0)
                tot[it->first] = 1;
            tot[it->first] *= it->second;
        }
    }
    int total=0;
    for(map<int, int>::iterator it = tot.begin(); it != tot.end(); it++)
        total += tot[it->first];

    // cout << total;
    FOR(i,1,n){
        if (!mp[n])
            ans[i] = total + pcomp[bk[i]][gi[i]] - 1;
        else ans[i] = 0; // solve for art point now
    }

    // See the total for the given team as component product.
    // for(map<int, int>::iterator it = tot.begin(); it != tot.end(); it++)
    //     cout << endl <<  it->first << " " << tot[it->first] ;


    FOR(i,1,n)
        cout << i << " " <<  ans[i] << endl;


    // FOR(i,1,n){
    //     if (used[i]) cout << i << " ";
    //     if (mp[i]) cout << "TRUE" << " ";}
    // cout << conn;






    return 0;
}
