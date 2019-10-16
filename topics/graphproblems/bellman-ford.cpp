#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define REP(i,a,b) for(int i = (a); i < (b); i++)

int main(){
    int v, e, s, a, b, w;
    cin >> v >> e >> s;
    vector<vii> AdjList;
    AdjList.assign(v, vii());
    REP(i,0,e){
        cin >> a >> b >> w;
        AdjList[a].push_back(ii(b,w));}

    vi dist(v, INF); dist[s] = 0;
    REP(i,0,v-1)  // tricky step because inner two loops are not sufficient to calculate the shortest path.
        REP(j,0,v)
            REP(k,0,AdjList[j].size()){
                ii V = AdjList[j][k];
                dist[V.first] = min(dist[V.first], dist[j]+V.second);
            }
    bool negativecycle = false;

    REP(i,0,v)
        REP(j,0,AdjList[i].size()){
            ii val = AdjList[i][j];
            if (dist[val.first] > dist[i] +val.second)
                negativecycle = true;
        }

    cout << "Negative Cycle Exist? \n" << negativecycle ? "Yes" : "No";

    if (!negativecycle)
        REP(i,0,v)
          printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
    return 0;
}
