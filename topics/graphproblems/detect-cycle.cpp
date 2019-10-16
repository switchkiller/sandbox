#include<iostream>
#include<list>
#include<limits.h>

using namespace std;

class Graph{
  int V;
  list<int> *adj;
  bool iscyclicutil(int v, bool visited[], bool *rs);
public:
  Graph(int V);
  void addEdge(int v, int w);
  bool iscyclic();
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
  adj[v].push_back(w);  //Directed graph
}

bool Graph::iscyclicutil(int v, bool visited[], bool *recStack){
  if (visited[v] == false){
    visited[v] = true;
    recStack[v] = true;

    list<int>::iterator itr;
    for (itr = adj[v].begin(); itr != adj[v].end(); itr++){
      if ( !visited[*itr] && iscyclicutil(*itr, visited, recStack))
        return true;
      else if (recStack[*itr])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

bool Graph::iscyclic(){
  bool *visited = new bool[V];
  bool *recStack = new bool[V];
  for (int i = 0; i < V; i++)
    if (iscyclicutil(i, visited, recStack))
      return true;
  return false;
}

int main(){
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  if (g.iscyclic())
    cout << "Is cyclic.";
  else
    cout << "No cycle.";
  return 0;
}
