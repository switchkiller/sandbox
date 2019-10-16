// Basic problem of minimum spanning tree. String used instead of indexing of vertex.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define REP(i,a,b) for(int (i) = (a); i < (b); i++)

vector<int> pset;

int findit(int a){
    if (pset[a] == a) return pset[a];
    return pset[a] = findit(pset[a]);
}
void unionSet(int a, int b){
    pset[findit(a)] = findit(b);
}
int isSameSet(int a, int b){
    return findit(pset[a]) == findit(pset[b]);
}
void init(int n){
    pset.assign(n,0);
    REP(i,0,n) pset[i] = i;}
int main(){
    int T, N, E, w, mst;
    string a, b;
    vector< pair<int, ii> > Edgelist;
    map<string, int> mp;
    cin >> T;
    while(T--){
        int counter = 0;
        cin >> N >> E;
        init(N);
        Edgelist.clear();
        mp.clear();
        REP(j,0,E){
            cin >> a >> b >> w;
            if (!mp.count(a)) mp[a] = counter++;
            if (!mp.count(b)) mp[b] = counter++;
            Edgelist.push_back(make_pair(w, ii(mp[a], mp[b])));
        }
        sort(Edgelist.begin(), Edgelist.end());
        //Kruskal();
        int mst = 0;

        REP(i,0,Edgelist.size()){
            if (!isSameSet(Edgelist[i].second.first, Edgelist[i].second.second))
                mst += Edgelist[i].first;
                unionSet(Edgelist[i].second.first, Edgelist[i].second.second);
        }
    cout << mst << endl;
    if (T) cout << endl;
    }
    return 0;
}
