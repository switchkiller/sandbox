// D. A Lot of Games - Trie and grundy numbers #gametheory


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

const int max_len = 100500, max_alpha = 26;

int x[max_len][max_alpha], root, sz;
bool win[max_len], lose[max_len];

void dfs(int v){
    win[v] = false;
    lose[v] = false;
    bool isLeaf = true;
    REP(i,0,max_alpha){
        int to = x[v][i];
        if (to){
            isLeaf = false;
            dfs(to);
            win[v] |= !win[to];
            lose[v] |= !lose[to];
        }
    }
    if (isLeaf)
        lose[v] = true;
}

void build_trie(char *s){
    int v = root;
    REP(i,0,strlen(s)){
        int c = s[i] - 'a';
        if (x[v][c] == 0) x[v][c] = ++sz;
        v = x[v][c];
    }
}

void answer(bool res){
    puts(res ? "First" : "Second");
    exit(0);
}

int n, k;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    root = ++sz;
    char s[max_len];
    while(n--){
        cin >> s;
        build_trie(s);
    }
    dfs(root);
    if (k == 1) answer(win[root]);
    else if (!win[root]) answer(win[root]);
    else if (lose[root]) answer(win[root]);
    else if (k % 2 == 1) answer(win[root]);
    else answer(!win[root]);
    return 0;
}
