#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define REP(i,a,b) for (int i = (a); i < (b); i++ )
#define MAX 50
#define Trvvi(a,itr) for (vector< vector<int> >::iterator itr = (a).begin(); itr != (a).end(); itr++ )

int V, E;
int visited[MAX];
int conn;

int dfs(int s){
	visited[s] = 1;
	Trvvi(AdjList[s], itr){
		if (visited[*itr] == 0)
			dfs(*itr);
	}
}

int floodfill(int s, int color){
	// Flood fill problems are really fun <3
	// Use dx, dy to pixate with a custom color and iterate thoughout.
	// Use simple dfs(_) maybe many times depending upon the grid for 'grid' based problems :p
	visited[s] = color;
	Trvvi(AdjList[s], itr){
		if (visited[*itr] == 0)
			floodfill(*itr, color);
	}
}

void edgeDirections(int u){ // Refer iitd lecture - Data Structure course.
	visited[u] = 2;
	Trvvi(AdjList[u], itr){
		if (visited[*itr] == 0)
			edgeDirections(*itr);
		else if (visited[*itr] == 2)
			if (dfs_parent[u] == *itr)
				cout << "Bidirectional!" << endl;
			else 
				cout << "Cycle! Back edge exist." << endl;
		else if (visited[*itr] == 1)
			cout << "Cross/Forward Edge! " << endl;
	}
	visited[u] = 1; // Mark completely visited once scanning complete.
}

int main(){
	vector< vi > AdjList;
	memset(visited, 0, sizeof visited);
	int a, b;
	cin >> V >> E;
	REP(i,0,E){
		cin >> a >> b;
		// Assuming that the graph is undirected graph.
		AdjList[a].push_back(b);
		AdjList[b].push_back(a);
	}

	REP(i,0,V){
		if (visited[i] == 0){
			dfs(i);
			++conn;
		}
		// Perform other calls
		// ...
	}

	return 0;
}