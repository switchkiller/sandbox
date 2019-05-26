#include<bits/stdc++.h>
using namespace std;

#define MOD 1e5+7;

const int N = 1e5;
vector< pair<int, int> > tree[N];

bool visited[N];

int dfs(int cur, int col){
	int cnt = 1;
	for(vector< pair<int, int> >::iterator it = tree[cur].begin(); it != tree[cur].end(); it++){
		if (!visited[it->first] && it->second == col){
			visited[it->first] = true;
			cnt += dfs(it->first, it->second);
		}
	}
	return cnt;
}

int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; i++){
		int u, v, col;
		cin >> u >> v >> col;
		u--, v--;
		tree[u].push_back(make_pair(v,col));
		tree[v].push_back(make_pair(u,col));
	}
	long islands = 0;
	for (int i = 0; i < n; i++){
		if (!visited[i]){
			visited[i] = true;
			int count = dfs(i,0);
			islands += count*(pow(count,k-1)-1);
		}
	}
	long ans = n*(pow(n,k-1)-1)-islands;
	cout << ans << endl;
	return 0;
}
