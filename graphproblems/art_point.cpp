//MAXN = maximum points in the graph
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

void dfs (int v, int p = -1) {
    used[v] = true;
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
            if (fup[to] >= tin[v] && p != -1)
                //v is articulation point
                ++children;
        }
    }
    if (p == -1 && children > 1)
        //v is articulation point
        }

int main() {
    int n;
    // read n and g
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    dfs (0);
}
