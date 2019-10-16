#include<bits/stdc++.h>
using namespace std;
#define MAX 31
#define REP(i,a,b) for (int i = (a); i < (b); i++)
typedef vector<int> vi;
typedef map<int, vi> mp;
map<int, int> visited;
void bfs(int s, mp gh){
	queue<int> q;
	q.push(s);
	visited.clear();
	visited[s] = 0;
	int val;
	while(!q.empty()){
		val = q.front(); q.pop();
		int size = gh[val].size();
		for (int i = 0; i < size; i++){
			int n = gh[val][i];
			if (!visited.count(n)){			// Check if key n is present in the map utility (if a value has been assigned.)
				visited[n]=visited[val]+1; 
				q.push(n);
			}
		}
	}
}
int main(){
	int v, a, b, cases = 1;
	mp gh;
	while (scanf("%d", &v) && v){
		//gh.clear();
		REP(i,0,v){
			// Edges
			cin >> a >> b;
			gh[a].push_back(b);
			gh[b].push_back(a);
		}
		int start, ttl, result;
		while (scanf("%d %d", &start, &ttl) && start && ttl){
			result = 0;
			bfs(start, gh);
			for (map<int, int>::iterator itr = visited.begin(); itr != visited.end(); itr++)
				if ((*itr).second > ttl) ++result;

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases,result,start,ttl); 
			cases++; 
		}
	}
	return 0;
}