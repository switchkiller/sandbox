
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define TRvi(it, c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define inf 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void addEdge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void dfs(int current, int parent)
{

        size[current] = 0;

        for(int i=0;i<adjacency_list[current].size();i++)

        {

                int next = adjacency_list[current][i];
                if(next == parent || deleted[next])continue;

                dfs(next, current);

                size[current] += size[next] + 1;

        }

        return ;

}

int findcenter(int current, int parent, int total){

    for(int i=0;i<(int)adjacency_list[current].size();i++)
    {
        int next = adjacency_list[current][i];

        if(next == parent || deleted[next])continue;

        if(total/2 < size[current] + 1)
            return findcenter(next, current, total);
    }

    return current;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif

        int n, m, v;

        cin >> n >> m;
        //
        FOR(i,2,n){
            cin >> v;
            if (i != v)
                addEdge(v,i);
        }

        FOR(i,1,m){
            cin >> v;
            cout << getCentroid(v) << endl;
        }
    return 0;
}
