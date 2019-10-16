#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<list>
using namespace std;
#define REP(a,itr) for(list<int>::iterator itr = (a).begin(); itr != (a).end(); ++itr)
class Graph{
  int V;
  list<int> *adj;
  int *color;
  bool *discovered;
  bool *processed;
public:
  Graph(int V);
  void addEdge(int v, int w);
  void initializer();
  int processedge(int,int);
  int bfs(int s);
  int compliment(int col);
  int twocolors();
  ~Graph();
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
  color = new int[V];
  discovered = new bool[V];
  processed = new bool[V];
}
Graph::~Graph(){

}
void Graph::addEdge(int v, int w){
  adj[v].push_back(w);
  adj[w].push_back(v);
}
void Graph::initializer(){
  int i;
  for (i = 0; i < V; i++)
    processed[i] = discovered[i] = false;
}
int Graph::twocolors(){
  int i;
  for (i = 0; i < V; i++)
    color[i] = -1;
  //bipartite = true;
  initializer();
  for(i = 0; i < V; i++)
    if (discovered[i] == false){
      color[i] = 1;
      if (bfs(i) == 0 )
	     return 0;
    }
  return 1;
}
int Graph::compliment(int col){
  if (col == 1) return 2;
  if (col == 2) return 1;
  return -1;
}
int Graph::processedge(int x, int y){
  if (color[x] == color[y]){
    //bipartite = false;
    //flag = 1;
    //cout << x << y;
  //  cout << "Not bipartite";
    return 0; //Bug Fixed.
  }
  color[y] = compliment(color[x]);
  return 1;
}
int Graph::bfs(int s){
  list<int> queue;
  discovered[s] = true;
  queue.push_back(s);
  while(!queue.empty()){
    s = queue.front();
    queue.pop_front();
    processed[s] = true;
    REP(adj[s], itr){
      if (processed[*itr] == false){ //Fixed.
        if (processedge(s,*itr) == 0)
          return 0;
      }
      if (!discovered[*itr]){
        discovered[*itr] = true;
        queue.push_back(*itr);
      }
    }
  }
  return 1;
}

int main(){
  int n, v, ve, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> v; //no of vertex
    cin >> ve; //no of edges
    Graph g(v);
    for (int j = 1; j <= ve; j++){
      cin >> x >> y;
      g.addEdge(x,y);
    }
    if (g.twocolors() == 0) cout << "NOT BICOLORABLE";
    else cout << "BICOLORABLE";
  }
  return 0;
}
