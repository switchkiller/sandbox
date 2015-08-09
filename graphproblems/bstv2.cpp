/*---------------------
| Author: switchkiller |
----------------------*/
#include<iostream>
#include<list>

using namespace std;

class Graph{
  int V;
  list<int> *adj;
  void DFSUtil(int v, bool visited[]);
public:
  Graph(int V);
  void addEdge(int v, int w);
  void DFS(int v);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int V, int w){
  adj[V].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
  visited[v] = true;
  cout<<v<<" ";
  list<int>::iterator itr;
  for(itr=adj[v].begin();itr!=adj[v].end();++itr)
    if (!visited[*itr])
      DFSUtil(*itr, visited);
}

void Graph::DFS(int V){
  bool *visited = new bool[V];
  for (int i=0; i < V; i++)
    visited[i] = false;
  DFSUtil(v,visited);
}
